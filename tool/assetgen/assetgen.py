#!/usr/bin/python

import json
import argparse
from pprint import pprint


class AssetParser(object):

    def parse(self, path_to_json_file):
        '''
        Carga los datos del fichero json y comprueba que son validos.
        Aniadimos los ids de cada asset por utilidad, y creamos las
        referencias de unos a otros.
        '''
        json_data = open(path_to_json_file)
        self.asset_data = json.load(json_data)

        self.check_assets()
        self.append_ids()
        self.build_refs()

    def append_ids(self):
        '''
        Aniadimos los ids de cada asset al mismo, por utilidad luego para
        poder referenciarlo en la construccion.
        '''
        for asset_list in ["textures", "spritesheets", "animations"]:
            for asset_id, asset in self.asset_data[asset_list].items():
                asset["id"] = asset_id

    def build_refs(self):
        for sheet_id, sheet in self.asset_data["spritesheets"].items():
            sheet["texture"] = self.asset_data["textures"][sheet["texture"]]

        for anim_id, anim in self.asset_data["animations"].items():
            anim["spritesheet"] = self.asset_data["spritesheets"][anim["spritesheet"]]
        pprint(self.asset_data)

    def check_assets(self):
        for tex_id, tex_data in self.asset_data["textures"].items():
            self.check_texture(tex_id, tex_data)
        for anim_id, anim_data in self.asset_data["animations"].items():
            self.check_animation(anim_id, anim_data)
        for sheet_id, sheet_data in self.asset_data["spritesheets"].items():
            self.check_spritesheet(sheet_id, sheet_data)

    def check_dict_args(self, pre_text, dictionary, expected_keys, optional=[]):
        if set(expected_keys) != set(dictionary.keys()):
            if set(dictionary.keys()).intersection(set(optional)) != set(optional):
                exception_string = pre_text + "\n" + \
                        "\tExpected: " + str(expected_keys) + "\n" \
                        "\tGot: " + str(dictionary.keys()) + "\n"
                raise Exception(exception_string)

    def check_texture(self, tex_id, tex_data):
        self.check_dict_args("At texture " + tex_id, tex_data, ["path"])

    def check_animation(self, anim_id, anim_data):
        where = "At animation " + anim_id

        # check correct animation dict
        self.check_dict_args(where, anim_data, ["spritesheet", "frame_sequence", "frame_duration"], optional=["numplays"])

        # check frame length
        if len(anim_data["frame_sequence"]) != len(anim_data["frame_duration"]):
            raise Exception(where + "\n\tIncorrect frame_duration and frame_sequence length.")

        # check valid spritesheet
        if anim_data["spritesheet"] not in self.asset_data["spritesheets"]:
            raise Exception(where + "\n\tSpritesheet " + anim_data["spritesheet"] + " not defined.")

    def check_spritesheet(self, sheet_id, sheet_data):
        where = "At spritesheet " + sheet_id

        # check correct spritesheet dict
        self.check_dict_args(where, sheet_data, ["texture", "size"])

        # check size dimensions == 2
        if len(sheet_data["size"]) != 2:
            raise Exception(where + "\n\tSize must be 2 (width, height).")

        # check valid texture
        if sheet_data["texture"] not in self.asset_data["textures"]:
            raise Exception(where + "\n\tTexture " + sheet_data["texture"] + " not defined.")

    def build_assets_def(self):
        definitions = ""

        asset_types = {
            "textures": "sf::Texture",
            "spritesheets": "Spritesheet",
            "animations": "Animation",
        }

        for asset_list in asset_types.keys():
            for asset_id, asset in self.asset_data[asset_list].items():
                definitions += "\t" + asset_types[asset_list] + " " + asset_id + ";\n"
        return definitions

    def build_assets_init(self):
        inits = ""

        inits += "\t\t// TEXTURES\n"
        for tex_id, tex in self.asset_data["textures"].items():
            # TODO: check if loadFromFile returns true!
            inits += "\t\tthis->" + tex_id + ".loadFromFile(\"" + tex["path"] + "\");\n"

        inits += "\n\t\t// SPRITESHEETS\n"
        for sheet_id, sheet in self.asset_data["spritesheets"].items():
            inits += "\t\tthis->" + sheet_id + ".Prepare(&(this->" + sheet["texture"]["id"] + "), sf::Vector2i( " + str(sheet["size"][0]) + ", " + str(sheet["size"][1]) + " ));\n"

        inits += "\n\t\t// ANIMATIONS\n"
        for anim_id, anim in self.asset_data["animations"].items():
            numplays = -1
            if "numplays" in anim:
                numplays = str(anim["numplays"])
            inits += "\t\tthis->" + anim_id + ".Prepare( &" + anim["spritesheet"]["id"] + ", " + str(len(anim["frame_sequence"])) + ", " + str(numplays) + " );\n"
            fseq = anim["frame_sequence"]
            fdur = anim["frame_duration"]
            for idx in range(0, len(anim["frame_sequence"])):
                frame_num = fseq[idx][0] + fseq[idx][1] * anim["spritesheet"]["size"][0]
                inits += "\t\tthis->" + anim_id + ".SetFrame(" + str(idx) + ", " + str(frame_num) + ", sf::seconds(" + str(fdur[idx]) + "f) );\n"

        return inits


    def build_file(self):
        return Template.cpp_file_tpl % \
            {
                "inits": self.build_assets_init(),
                "definitions": self.build_assets_def()
            }

    def gen_h_file(self, path):
        with open(path, "w") as f:
            f.write(self.build_file())

class Template(object):
    cpp_file_tpl = \
'''

#pragma once

#include <SFML/Graphics.hpp>
#include <core/assets/Animation.h>
#include <core/assets/Spritesheet.h>

class Assets {

public:

\tAssets() {

%(inits)s
\t}

%(definitions)s
};

'''


def main():

    parser = argparse.ArgumentParser()
    parser.add_argument("--jsonpath", required=True, help="Path to json file to load")
    parser.add_argument("--outcpp", required=False, help="Generated .h file name")
    args = parser.parse_args()

    parser = AssetParser()
    parser.parse(args.jsonpath)
    print(parser.build_file())

    if args.outcpp:
        parser.gen_h_file(args.outcpp)


if __name__ == '__main__':
    main()



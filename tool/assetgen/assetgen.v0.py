
import json
import argparse
from pprint import pprint

'''
def checkdictargs(*args):
    def wrap(f):
        def wrapped_f(**kwargs):
            if set(*args) != set(kwargs.keys()):
                raise Exception("Incorrect arguments to parse!")
            else:
                f(kwargs)
'''

def checkdictargs(expected_keys, dictionary, object_type=""):
    if set(expected_keys).issubset(set(dictionary.keys())):
        exception_string = object_type + "\n" + \
                "Expected: " + expected_keys + "\n" \
                "Got: " + dictionary.keys()
        raise Exception(exception_string)

animation_frame_tpl = '''%(anim_id)s->AddFrame(%(frame_num)s, %(frame_duration)s);'''
def build_frame(anim_id, **frame):
    checkdictargs(["x", "y", "duration"], frame, object_type="build_frame")
    checkdictargs(["width"], frame["spritesheet"], object_type="build_frame")
    frame_num = int(frame["x"]) + int(frame["y"]) * int(frame["spritesheet"]["width"])
    return animation_frame_tpl % { 'anim_id': anim_id, 'frame_num': frame_num, 'frame_duration': frame["duration"] }

generic_object_creation_tpl = '''%(asset_id)s = new %(asset_class)s();'''
@checkdictargs("asset_kind", "asset_id", "asset_class")
def build_create_object(**kwargs):
    checkdictargs(["asset_kind", "asset_id", "asset_class"], kwargs, object_type="build_create_object")
    return generic_object_creation_tpl % kwargs

generic_object_declaration_tpl = '''%(asset_class)s* %(asset_id);'''
@checkdictargs("asset_class", "asset_id")
def build_declare_object(**kwargs):
    return generic_object_declaration_tpl % kwargs

def build_animation_frames(**anim):
    checkdictargs(["id", "frames", "spritesheet"], anim, object_type="animation")
    checkdictargs(["width"], anim["spritesheet"])

    def xy2num(x,y):
        return int(anim["spritesheet"]["width"]) * y + x

    ret = ""
    for frame in anim["frames"]:
        ret = ret + build_frame(anim_id=anim["id"], spritesheet_id=anim["spritesheet"], **frame)
    return ret

def build_animations(animation_list):
    animations = { "init": "", "decl": "" }
    for anim in animation_list:
        anim_create = build_create_object("animation", anim["id"])
        anim_add_frames = build_animation_frames(anim)
        animations["init"] += anim_create + anim_add_frames
        #ret = ret + parse_init_animation(


generic_definition_tpl = "%(type)s* %(var_name);"

image_init_tpl = \
'''
        images["%(id)s"]->loadFromFile("%(path)");
'''

animation_add_frame_tpl = '''%(asset_id)s->AddFrame( %(frame_x)s, %(frame_y)s, %(frame_time)s );'''

check_asset = {
    "animation": check_animation,
    "spritesheet": check_spritesheet,
    "texture": check_texture,
}

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument("jsonpath", help="Path to json file to load")
    args = parser.parse_args()
    json_data = open(args.jsonpath)
    asset_data = json.load(json_data)

    pprint(asset_data)

    asset_lists = {
        "animation" : [],
        "spritesheet" : [],
        "image" : [],
    }

    for asset in asset_data:
        asset_lists[asset["kind"]].append(asset)

    for anim in asset_lists["animation"]:
        anim["spritesheet"] = asset_lists["spritesheet"][anim["spritesheet"]]

    loaders = {
        "animation" : parse_anim,
        "image" : parse_image,
    }

    for asset in asset_data:
        loaders[asset["kind"]]( asset )

'''
    text_render = {
        'init' : {
            'image' : trImage,
            'animation' : trAnimation,
        }
    }
'''

if __name__ == '__main__':
    main()


'''

#pragma once

class Assets {{

public:

    Assets() {{
        %(images_init)s
        %(animations_init)s
    }}

    %(assets_definition)s

}};

'''

'''
Se creará mejor una clase AssetParser para llevar mejor control de todo.
Pasos:

    1. introduce objetos en listas miembro del objeto AssetParser, no importa orden.
       Ya se tiene acceso a las listas miembro con los assets, asi que pueden acceder
       entre ellos de ahora en adelante.

    2. Construye el arbol cambiando ids por diccionarios en si.
       Ejemplo: "animation" tiene "spritesheet" que es el id, asi que hacemos asi:
            anim["spritesheet"] = self.spritesheets[anim["spritesheet"]]

    3. Generamos los textos de cada tipo de assets a partir de las listas, tanto para
       definición como para creación POR SEPARADO, no importa orden.

    4. Se compone el documento final teniendo en cuenta el orden en el que debe aparecer cada cosa.

'''

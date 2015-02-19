#!/usr/bin/python

import sys
import json

current_flag = 0

def next_flag():
    global current_flag
    ret = 2 ** current_flag
    current_flag = current_flag + 1
    return ret

single_component_flag_template = '''
template <>
struct component_flags<{0}Component>
{{ static const ctflags_t flags = {1}; }};'''

component_flags_template = '''
#pragma once

#include <cstdint>
#include <ecs/component/ComponentFlags.h>
#include "Components.h"
#include "ComponentsDecl.h"

typedef std::uint32_t ctflags_t;
{0}

template <class... Ts>
struct construct_flags;

template <class First, class... Rest>
struct construct_flags<First, Rest...>
{{
	static const ctflags_t flags =
		component_flags<First>::flags |
		construct_flags<Rest...>::flags;
}};

template <class T>
struct construct_flags<T>
{{ static const ctflags_t flags = component_flags<T>::flags; }};'''

component_pools_template = '''
#pragma once

#include "Components.h"

#include <rztl/pool.h>
template <typename T> using Pool = rztl::Pool<T>;

{0}'''

single_component_pool_template = '''typedef Pool<{0}Component> C{0}Pool;'''

component_pool_holder_template = '''
#pragma once

#include "ComponentPools.h"

class ComponentPoolHolder {{
public:

    ComponentPoolHolder()
    {{ {0}
        Locator<EntityPool>::set(&entitypool);
    }}

private: {1}
    EntityPool entitypool;

}};'''

def make_flag(component_name):
    return single_component_flag_template.format(component_name, next_flag())

def make_pool(component_name):
    return single_component_pool_template.format(component_name)

def main():

    if len(sys.argv) != 2:
        print("What json file?")
        sys.exit()

    json_data = open(sys.argv[1])
    data = json.load(json_data)
    json_data.close()
    print(data)

    component_flag_list = []
    component_pool_list = []
    components_decl_file_content = "#pragma once\n"
    component_headers_file_content = "#pragma once\n"
    component_pool_holder_pools = ""
    component_pool_holder_locators = ""

    for c in data:
        component_name = c[u'name']
        pool_type_name = "C" + component_name + "Pool"
        pool_var_name = component_name.lower() + "pool"
        component_flag_list.append(make_flag(component_name))
        component_pool_list.append(make_pool(component_name))
        components_decl_file_content = components_decl_file_content + "\nclass " + component_name + "Component;"
        component_headers_file_content = component_headers_file_content + '\n#include "' + component_name + 'Component.h"'
        component_pool_holder_pools = component_pool_holder_pools + "\n\t" + pool_type_name + " " + pool_var_name + ";"
        component_pool_holder_locators = component_pool_holder_locators + "\n\t\tLocator<" + pool_type_name + ">::set(&" + pool_var_name + ");"

    component_flag_file_content = component_flags_template.format("\n".join(component_flag_list))
    component_pool_file_content = component_pools_template.format("\n".join(component_pool_list))
    component_pool_holder_file_content = component_pool_holder_template.format(component_pool_holder_locators, component_pool_holder_pools)

    print(component_flag_file_content)
    print(component_pool_file_content)
    print(components_decl_file_content)
    print(component_headers_file_content)
    print(component_pool_holder_file_content)

    f = open("ComponentFlags.h", "w+")
    f.write(component_flag_file_content)
    f.close()

    f = open("ComponentPools.h", "w+")
    f.write(component_pool_file_content)
    f.close()

    f = open("ComponentsDecl.h", "w+")
    f.write(components_decl_file_content)
    f.close()

    f = open("Components.h", "w+")
    f.write(component_headers_file_content)
    f.close()

    f = open("ComponentPoolHolder.h", "w+")
    f.write(component_pool_holder_file_content)
    f.close()



if __name__ == "__main__":
    main()

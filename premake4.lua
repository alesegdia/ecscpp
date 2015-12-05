
require 'lfs'

solution "ecscpp-project"
  configurations { "Debug", "Release" }
  platforms { "x64", "x32" }

project "ecscpp"
  location 		"build"
  kind "StaticLib"
  language "C++"
  buildoptions {"-std=c++11", "-pg" }
  includedirs {"include64,include", "/usr/include/freetype2", "src/lib", "module/rztl/include"}
  targetdir "lib"
  files {
    "src/lib/**.cpp",
    "src/lib/**.h",
  }

function parseFileName(url)
  return string.match(url, ".-([^\\/]-)%.?([^%.\\/]*)$")
end

function define_test(testname, filename)
	print(filename)
	project(testname)
		location 		"build"
		language 		"C++"
		kind 			"WindowedApp"
		files 			{ "src/tests/" .. filename }
		links 			{ "ecscpp", "c", "dl", "m", "rt", "rt" }
		buildoptions 	{ "-std=c++11", "-pg" }
		includedirs 	{ "include64,include", "src/lib", "module/rztl/include" }
		configuration 	{ "Debug*" }
			defines 	{ "_DEBUG", "DEBUG" }
			flags		{ "Optimize" }
			targetdir 	"bin"
		configuration 	{ "x32" }
			includedirs { "include64,include", "src/lib", "module/rztl/include" }
			linkoptions { "-pg" }
		configuration 	{ "x64" }
			includedirs { "include64,include", "src/lib", "module/rztl/include" }
			linkoptions { "-pg", "-ftest-coverage", "-fprofile-arcs" }
end

for file in lfs.dir([[src/tests]]) do
	local name, ext = parseFileName(file)
	if ext == "cpp" then
		define_test(name, name .. "." .. ext)
	end
end


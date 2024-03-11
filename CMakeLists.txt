# CMakeList.txt: candy 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("server")

# 将源代码添加到此项目的可执行文件。
#add_executable (candy "candy.cpp" )

# TODO: 如有需要，请添加测试并安装目标。


include_directories(include)


add_subdirectory(example)
add_subdirectory(src)
add_subdirectory(tests)
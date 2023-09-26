cmake_minimum_required(VERSION 3.0)
project(pokegame01) 

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

set(CMAKE_PREFIX_PATH "/home/chaxuxx/workspace/includerely/")
# set是设置变量 这句就指定了gtest寻找路径 很重要 和GTEST_ROOT必须要有一个。但是上面这句可以使内部的所有库都能被找到
# 增加库文件搜索路径lib 头文件include 系统的安装位置一般是usr/local/lib & include
# set(GTEST_ROOT "/home/chaxuxx/workspace/includerely/usr/local/")
include_directories(/mnt/c/Users/DchG/Desktop/pokegame01/dezhoupoke)#这句使test文件能够索引到dezhoupoke文件夹中的头文件(executable那儿也得link上)

include_directories(/home/chaxuxx/workspace/includerely/include)
link_directories(/home/chaxuxx/workspace/includerely/lib)
find_package(GTest REQUIRED)

set(LIB_SRC
    dezhoupoke/poke.cc
    )
add_library(poke SHARED ${LIB_SRC}) #这是生成共享库 库名为sylar_dchg
# force_redefine_file_macro_for_sources(sylar_dchg) #这样更改__FILE__的位置为相对路径而不是绝对路径 加上上面的utils.cmake文件

# enable_testing()
#gtest要求的cmakelists写法/貌似不用
add_executable(poketest test/testpoke.cc)
# add_dependencies(poketest poke)
target_link_libraries(poketest poke)
# add_dependencies(poke1)
# target_link_libraries(poketest poke gtest gtest_main pthread) #注意库名称是gtest 大小写写错也会找不到
# include(GoogleTest)
# gtest_discover_tests(poke1)

add_executable(ladingou game/ladingou.cc)
target_link_libraries(ladingou poke)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)#二进制文件存放位置设置
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)#lib存放位置设置
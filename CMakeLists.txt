cmake_minimum_required(VERSION 3.0)
project(dezhoupoke) 

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

set(CMAKE_PREFIX_PATH "/home/chaxuxx/workspace/includerely/usr/local/")
#这句就指定了寻找路径 很重要
# 增加库文件搜索路径lib 头文件include 系统的安装位置一般是usr/local/lib & include
set(GTEST_ROOT "/home/chaxuxx/workspace/includerely/usr/local/")
set(GTEST_INCLUDE_DIRS "/home/chaxuxx/workspace/includerely/usr/local/include")
set(GTEST_LIBRARIES "/home/chaxuxx/workspace/includerely/usr/local/lib/libgtest.a","/home/chaxuxx/workspace/includerely/usr/local/lib/libgtest_main.a")
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(/home/chaxuxx/workspace/includerely/usr/local/lib)
find_package(GTest REQUIRED)
if(GTest_FOUND)
    include_directories(${GTest_INCLUDE_DIR})
endif()
# set(LIB_SRC
#     dezhoupoke/poke.cc
#     )
# add_library(poke SHARED ${LIB_SRC}) #这是生成共享库 库名为sylar_dchg
# force_redefine_file_macro_for_sources(sylar_dchg) #这样更改__FILE__的位置为相对路径而不是绝对路径 加上上面的utils.cmake文件

enable_testing()
#gtest要求的cmakelists写法
add_executable(poke1 dezhoupoke/poke.cc)
# add_dependencies(poke1)
target_link_libraries(poke1 gtest gtest_main pthread) 
#注意库名称是gtest 大小写写错也会找不到

include(GoogleTest)
gtest_discover_tests(poke1)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)#二进制文件存放位置设置
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)#lib存放位置设置
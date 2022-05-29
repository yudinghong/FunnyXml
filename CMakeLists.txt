cmake_minimum_required(VERSION 3.21)
project(funny_xml)

set(CMAKE_CXX_STANDARD 11)

add_executable(funny_xml main.cpp lib/FunnyXml.cpp lib/FunnyXml.h lib/FunnyNode.cpp lib/FunnyNode.h lib/FunnyEnum.h lib/FunnyStruct.h)

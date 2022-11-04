cmake_minimum_required(VERSION 3.5)

project(viterbi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( source
                main.cpp
                core/src/core.cpp
                coder/src/coder.cpp
                parser/xml_parser/src/xml_paser.cpp
                logger/console_logger/src/console_logger.cpp )

include_directories( core/h/
                     coder/h/
                     parser/xml_parser/h/
                     logger/console_logger/h/ )

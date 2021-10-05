# \authors Dmitrii Leliuhin
# \date June 2021

#========================================================================================

cmake_minimum_required( VERSION 3.10 FATAL_ERROR )

#========================================================================================

project( test_vsimple
    LANGUAGES CXX)

#========================================================================================

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
list( APPEND CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage" )

#========================================================================================

include_directories( ${CMAKE_SOURCE_DIR} )

include( ${CMAKE_CURRENT_LIST_DIR}/test_modules/test_modules.cmake )

#========================================================================================

add_executable( ${PROJECT_NAME}
    test_modules/test.cpp
    ${V_HEADERS}
    ${MODULES_TEST} )

target_link_libraries( ${PROJECT_NAME}
    -lgtest
    -fprofile-arcs
    -lpthread
    -ldl )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================

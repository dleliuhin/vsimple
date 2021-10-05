# \authors Dmitrii Leliuhin
# \date April 2021

#========================================================================================

cmake_minimum_required( VERSION 3.10 FATAL_ERROR )

#========================================================================================

project( vsimple
    LANGUAGES CXX )

#========================================================================================

set( CMAKE_BUILD_TYPE "Release" )

#========================================================================================

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

#========================================================================================

include_directories( ${CMAKE_SOURCE_DIR} )

include( ${CMAKE_CURRENT_LIST_DIR}/all.cmake )

#========================================================================================

add_library( ${PROJECT_NAME} SHARED ${V_HEADERS} )

set_target_properties( ${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX )

target_link_libraries( ${PROJECT_NAME}
    -lpthread
    -ldl )

#========================================================================================

unset ( QT_QMAKE_EXECUTABLE )

#========================================================================================

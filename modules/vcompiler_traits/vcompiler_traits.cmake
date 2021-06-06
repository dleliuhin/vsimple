#########################################################################################
##
##  GNU Lesser General Public License Usage
##  This file may be used under the terms of the GNU Lesser General Public License
##  version 3 as published by the Free Software Foundation and appearing in the file
##  LICENSE.LGPL3 included in the packaging of this file. Please review the following
##  information to ensure the GNU Lesser General Public License version 3 requirements
##  will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
##
#########################################################################################
# vcompiler_traits.cmake

# \authors Alexander Gromtsev, Dmitrii Leliuhin
# \date June 2021

#========================================================================================

if ( vcompiler_traits_included )
    return()
endif()

set( vcompiler_traits_included TRUE )

#========================================================================================

message( STATUS "=== About include vcompiler_traits... ===" )

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

list( APPEND V_HEADERS ${CMAKE_CURRENT_LIST_DIR}/vcompiler_traits.h )

list( APPEND V_HEADERS ${CMAKE_CURRENT_LIST_DIR}/details/vplatform.h )
list( APPEND V_HEADERS ${CMAKE_CURRENT_LIST_DIR}/details/vendian.h )
list( APPEND V_HEADERS ${CMAKE_CURRENT_LIST_DIR}/details/vpretty_function.h )

message( STATUS "=== vcompiler_traits included ===" )

# vcompiler_traits.cmake
#========================================================================================

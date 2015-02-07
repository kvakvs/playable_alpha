project(PLAYABLE)
cmake_minimum_required( VERSION 2.8 )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY       ${CMAKE_SOURCE_DIR}/bin CACHE PATH "Single Directory for all Executables." )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin CACHE PATH "Single Directory for all Executables." )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY       ${CMAKE_SOURCE_DIR}/linklib CACHE PATH "Single Directory for all static libraries." )

include_directories(${CMAKE_SOURCE_DIR}/deps/hge2/src/core
		    ${CMAKE_SOURCE_DIR}/deps/hge2/src/core/unix
		    ${CMAKE_SOURCE_DIR}/deps/hge2/src/core/windows)

set(PLAYABLE_SRCS
	src/main.cpp
)

add_definitions( -std=c++11 -Weverything -Wno-c++98-compat-pedantic -Wno-missing-noreturn
                 -Wno-c++98-compat -Wno-padded -Wno-format-nonliteral )

#--- Optimize (Linux) ---
#add_definitions( -O1 )
add_definitions( -ggdb3 -Werror ) # debug info

link_directories( ${CMAKE_SOURCE_DIR}/deps/hge2/bin
                ${CMAKE_SOURCE_DIR}/deps/hge2/linklib )
link_libraries( hge2core hge2helpers hgecximage hgezlib jpeg png )

add_executable(playable_alpha ${PLAYABLE_SRCS})
#target_link_libraries(playable_alpha ${HGE2_EXECLIBS})

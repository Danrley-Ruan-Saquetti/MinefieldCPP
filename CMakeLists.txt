cmake_minimum_required(VERSION 3.15)
project(CampoMinado VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include lib)

function(auto_add_subdirectories base_dir)
  file(GLOB children RELATIVE ${base_dir} ${base_dir}/*)
  foreach(child ${children})
    if(IS_DIRECTORY "${base_dir}/${child}")
      if(EXISTS "${base_dir}/${child}/CMakeLists.txt")
        message(STATUS "Adicionando subdiretório: ${base_dir}/${child}")
        add_subdirectory("${base_dir}/${child}")
      endif()
    endif()
  endforeach()
endfunction()

auto_add_subdirectories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES
  CONFIGURE_DEPENDS
  src/*.cpp
  lib/**/*.cpp
)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
  message("-- Debug ON")
  add_compile_options(-fsanitize=address -g)
  add_link_options(-fsanitize=address)
endif()

add_executable(CampoMinado ${SOURCES})

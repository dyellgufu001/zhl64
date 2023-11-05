cmake_minimum_required(VERSION 3.13.0)

set ("CMAKE_CXX_STANDARD" 17)
set (CMAKE_BUILD_TYPE "Debug")

project (zhl)

find_library(D3D11 d3d11.lib "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64")
find_library(DXGI dxgi.lib "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64")
find_library(D2D1 d2d1.lib "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64")

include_directories("${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/libzhl" 
    "${CMAKE_SOURCE_DIR}/libs/imgui" "${CMAKE_SOURCE_DIR}/libs/imgui/misc/freetype" 
    "${CMAKE_SOURCE_DIR}/libs/imgui/backends" )

# ANTLR
option(WITH_STATIC_CRT "" OFF)
option(ANTLR_BUILD_CPP_TESTS "" OFF)
option(ANTLR_BUILD_STATIC "" OFF)
add_subdirectory("libs/antlr4/runtime/Cpp")
include_directories ("libs/antlr4/runtime/Cpp/runtime/src")

# Parser
FILE(GLOB PARSER_SRC ${CMAKE_SOURCE_DIR}/libzhlgen/*.cpp)
add_executable(zhlparser ${PARSER_SRC})
target_link_libraries(zhlparser antlr4_shared)
target_compile_options(zhlparser PUBLIC "/wd4251" "/wd4275")
# wd4251 ignore warning C4251: 'type' : class 'type1' needs to have dll-interface to be used by clients of class 'type2'
# wd4275 ignore warning C4275: non - DLL-interface class 'class_1' used as base for DLL-interface class 'class_2'
target_compile_options(antlr4_shared PUBLIC "/wd4100" "/wd4244" "/wd4251" "/wd4275" "/wd4996")
# ignore all warnings from that lib. We are not the author, so we dont care about them

add_custom_command(TARGET zhlparser POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE_DIR:antlr4_shared>/antlr4-runtime.dll" "$<TARGET_FILE_DIR:zhlparser>")

# dsound
FILE(GLOB LAUNCHER_SRC "${CMAKE_SOURCE_DIR}/launcher/*.cpp")
add_library(xinput9_1_0 SHARED ${LAUNCHER_SRC})
target_compile_options(xinput9_1_0 PUBLIC "/MD" "/wd4996")

# IsaacRepentance.h/.cpp
FILE(GLOB ZHL_FILES ${CMAKE_SOURCE_DIR}/libzhl/functions/*.zhl)
# add_custom_command(OUTPUT "$<TARGET_FILE_DIR:libzhl>/Overwatch2.cpp" COMMAND "zhlparser" "--test" WORKING_DIRECTORY "$<TARGET_FILE_DIR:zhlparser>" DEPENDS ${ZHL_FILES} zhlparser)

# libzhl
FILE(GLOB ZHL_SRC ${CMAKE_SOURCE_DIR}/libzhl/*.cpp ${CMAKE_SOURCE_DIR}/libzhl/*.h)
add_library(libzhl SHARED ${ZHL_SRC})
target_compile_options(libzhl PUBLIC "/MD" "/wd4251" "/wd4996")

# ImGUI
enable_language(RC)
set(FREETYPE_SRC
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/autofit/autofit.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftbase.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftbbox.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftbdf.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftbitmap.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftcid.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftfstype.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftgasp.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftglyph.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftgxval.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftinit.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftmm.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftotval.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftpatent.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftpfr.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftstroke.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftsynth.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/fttype1.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftwinfnt.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/bdf/bdf.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/bzip2/ftbzip2.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/cache/ftcache.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/cff/cff.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/cid/type1cid.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/gzip/ftgzip.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/lzw/ftlzw.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/pcf/pcf.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/pfr/pfr.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/psaux/psaux.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/pshinter/pshinter.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/psnames/psnames.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/raster/raster.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/sdf/sdf.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/sfnt/sfnt.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/smooth/smooth.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/svg/svg.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/truetype/truetype.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/type1/type1.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/type42/type42.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/winfonts/winfnt.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/builds/windows/ftsystem.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/builds/windows/ftdebug.c
  ${CMAKE_SOURCE_DIR}/libs/freetype/src/base/ftver.rc
)
add_library(freetype SHARED ${FREETYPE_SRC} ${WinSDK})
target_include_directories(freetype PUBLIC "${CMAKE_SOURCE_DIR}/libs/freetype/include")
target_compile_options(freetype PUBLIC "/MD")
set_target_properties(freetype PROPERTIES C_VISIBILITY_PRESET hidden)
target_compile_definitions(freetype PRIVATE FT2_BUILD_LIBRARY PRIVATE DLL_EXPORT _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_WARNINGS)

FILE(GLOB IMGUI_SRC ${CMAKE_SOURCE_DIR}/libs/imgui/*.cpp)
FILE(GLOB IMGUI_BACKENDS_DIR ${CMAKE_SOURCE_DIR}/libs/imgui/backends/)
set(IMGUI_BACKENDS_DIR ${CMAKE_SOURCE_DIR}/libs/imgui/backends/)
add_library(imgui ${IMGUI_SRC} ${CMAKE_SOURCE_DIR}/libs/imgui/misc/freetype/imgui_freetype.h ${CMAKE_SOURCE_DIR}/libs/imgui/misc/freetype/imgui_freetype.cpp ${IMGUI_BACKENDS_DIR}/imgui_impl_dx11.cpp ${IMGUI_BACKENDS_DIR}/imgui_impl_dx11.h ${IMGUI_BACKENDS_DIR}/imgui_impl_win32.h ${IMGUI_BACKENDS_DIR}/imgui_impl_win32.cpp)
target_include_directories(imgui PUBLIC "${CMAKE_SOURCE_DIR}/libs/freetype/include")
target_compile_options(imgui PUBLIC "/MD")
target_compile_definitions(imgui PUBLIC IMGUI_ENABLE_FREETYPE)

# modTest
file(GLOB_RECURSE MODTEST_SRC ${CMAKE_SOURCE_DIR}/modtest/*.*)
# Display folder structure inside of VS solution - https://stackoverflow.com/a/54531576
foreach(_source IN ITEMS ${MODTEST_SRC})
    get_filename_component(_source_path "${_source}" PATH)
    string(REPLACE "${CMAKE_SOURCE_DIR}" "" _group_path "${_source_path}")
    string(REPLACE "/" "\\" _group_path "${_group_path}")
    source_group("${_group_path}" FILES "${_source}")
endforeach()
add_library(zhlModTest SHARED ${MODTEST_SRC})
target_compile_options(zhlModTest PUBLIC "/MD" "/wd4251" "/wd4996")

target_link_libraries(zhlModTest libzhl imgui freetype)

# D3D11 test env
FILE(GLOB TESTENV_SRC "${CMAKE_SOURCE_DIR}/testenv/*.cpp")
add_executable(testenv ${TESTENV_SRC})
target_link_options(testenv PUBLIC "/subsystem:windows")
target_include_directories(testenv PUBLIC "C:/Program Files (x86)/Windows Kits/10/Include/10.0.22000.0/um")
target_link_libraries(testenv D3D11 DXGI D2D1)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(antlr4_shared imgui freetype PROPERTIES FOLDER "External Libs")
set_target_properties(zhlparser libzhl PROPERTIES FOLDER "libzhl")
set_target_properties(xinput9_1_0 zhlModTest PROPERTIES FOLDER "ModTest")
set_target_properties(testenv PROPERTIES FOLDER "Test Environment")
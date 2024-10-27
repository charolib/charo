cmake_minimum_required(VERSION 3.9.4 FATAL_ERROR)

project(charo
        VERSION 0.0.1
        LANGUAGES CXX
        DESCRIPTION "Terminal User Interface Library"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

option(CHARO_WARNINGS                "charo: Enable all compiler warnings"    ON)
option(CHARO_WARNINGS_ERROR          "charo: Threat warnings as errors"       ON)

option(CHARO_THREAD_SANITAZER        "charo: Enable thread sanitizer"         OFF)
option(CHARO_ADDRESS_SANITAZER       "charo: Enable address sanitizer"        OFF)
option(CHARO_UNDEFINED_SANITAZER     "charo: Enable undefined sanitizer"      OFF)
option(CHARO_MEMORY_SANITAZER        "charo: Enable memory sanitizer"         OFF)
option(CHARO_LEAK_SANITAZER          "charo: Enable leak sanitizer"           OFF)

option(CHARO_OPTIMIZE                "charo: Enable some optimizations"       ON)

option(CHARO_STATIC                  "charo: Build static libs"               OFF)

option(CHARO_TESTS                   "charo: Build tests"                     OFF)
option(CHARO_EXAMPLES                "charo: Build examples"                  OFF)

if(CHARO_STATIC)
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    set(CMAKE_LINK_SEARCH_END_STATIC ON)
    add_link_options(-static-libgcc -static-libstdc++)
    set(CHARO_LIBTYPE STATIC)
else()
    set(CHARO_LIBTYPE SHARED)
    if (MSVC)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    endif()
endif()

list(APPEND HEADER_FILES
    include/charo/event/key.hpp
    include/charo/event/events.hpp
    include/charo/render/base/common_types.hpp
    include/charo/render/base/converter.hpp
    include/charo/render/base/glyph.hpp
    include/charo/render/base/glyphspace.hpp
    include/charo/render/style/color.hpp
    include/charo/render/style/effect.hpp
    include/charo/render/style/style.hpp
    include/charo/render/escape.hpp
    include/charo/render/screen.hpp
    include/charo/terminal.hpp
    include/charo/charo.hpp
)

list(APPEND SOURCE_FILES
    src/event/key.cpp
    src/event/events.cpp
    src/render/base/converter.cpp
    src/render/base/glyphspace.cpp
    src/render/escape.cpp
    src/render/screen.cpp
    src/terminal.cpp
)

add_library(charo ${CHARO_LIBTYPE})
target_sources(charo PRIVATE ${SOURCE_FILES})
target_sources(charo PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES ${HEADER_FILES}
)

set_target_properties(charo PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(charo PRIVATE include/)

set(DEFAULT_BUILD_TYPE "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")
endif ()

set(CMAKE_CXX_FLAGS_DEBUG "-g")

# -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables ????
if(CHARO_OPTIMIZE AND CMAKE_BUILD_TYPE EQUAL "Release")
    if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(charo PRIVATE -O2)
    elseif (MSVC)
        # using Visual Studio C++
    endif()
endif()

# if(CHARO_OPTIMIZE_LTO)
#     set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
# endif()

if (CHARO_THREAD_SANITAZER)
    target_compile_options(charo PRIVATE -fsanitize=thread)
    target_link_options(charo PRIVATE -fsanitize=thread)
endif()

if (CHARO_ADDRESS_SANITAZER)
    target_compile_options(charo PRIVATE -fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer)
    target_link_options(charo PRIVATE -fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer)
endif()

if (CHARO_UNDEFINED_SANITAZER)
    target_compile_options(charo PRIVATE -fsanitize=undefined)
    target_link_options(charo PRIVATE -fsanitize=undefined)
endif()

if (CHARO_MEMORY_SANITAZER)
    target_compile_options(charo PRIVATE -fsanitize=memory -fno-optimize-sibling-calls -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer)
    target_link_options(charo PRIVATE -fsanitize=memory -fno-optimize-sibling-calls -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer)
endif()

if (CHARO_LEAK_SANITAZER)
    target_compile_options(charo PRIVATE -fsanitize=memory -fsanitize=leak -fno-omit-frame-pointer)
    target_link_options(charo PRIVATE -fsanitize=memory -fsanitize=leak -fno-omit-frame-pointer)
endif()

if (CHARO_WARNINGS)
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(charo PRIVATE -Wall -Wextra -Wpedantic)
    else (MSVC)
        target_compile_options(charo PRIVATE /W4 /WX)
    endif()
endif()

message("Build Type: ${CMAKE_BUILD_TYPE}")

if(CHARO_OPTIMIZE)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT supported OUTPUT error)

    if( supported )
        message(STATUS "IPO / LTO enabled")
        set_property(TARGET charo PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    else()
        message(STATUS "IPO / LTO not supported: <${error}>")
    endif()
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/charo.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/charo.pc
  @ONLY
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/charo.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)


write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/charoConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)
    
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/charoConfigVersion.cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/charoConfig.cmake
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/charo
)
    
install(TARGETS charo
    EXPORT charoTargets
    FILE_SET HEADERS
 )
    
install(EXPORT charoTargets NAMESPACE charo:: DESTINATION ${CMAKE_INSTALL_DATADIR}/charo)

# EASELY IMPORT CHARO WITH find_package(Charo REQUIRED) target_link_libraries(${TARGET} charo)

if (CHARO_TESTS)
    add_subdirectory(tests)
endif()

if (CHARO_EXAMPLES)
    add_subdirectory(examples)
endif()

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_NAME "sfec")
# set(CPACK_PACKAGE_CONTACT https://github.com/nuclearbyte/sfec)

# set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

# SET(CPACK_GENERATOR "TGZ")
# SET(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 1)

# include(CPack)
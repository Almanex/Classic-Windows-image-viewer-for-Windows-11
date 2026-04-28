cmake_minimum_required(VERSION 3.16)

project(ShellImageViewer 
    VERSION 1.0
    DESCRIPTION "Shell Image Viewer for Windows"
    LANGUAGES CXX RC)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform check
if(NOT WIN32)
    message(FATAL_ERROR "This project is Windows-only")
endif()

# Build configuration
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Compiler-specific options
if(MSVC)
    # MSVC specific options
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /utf-8")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
    # Resource compiler flags for UTF-8 support
    set(CMAKE_RC_FLAGS "${CMAKE_RC_FLAGS} /c65001")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Clang/MinGW specific options
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC/MinGW specific options
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -mwindows")
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/file_utils.cpp
    src/dll_loader.cpp
    src/error_handler.cpp
    src/ui_dialogs.cpp
)

# Header files
set(HEADERS
    src/common.h
    src/file_utils.h
    src/dll_loader.h
    src/error_handler.h
    src/ui_dialogs.h
)

# Resource files
set(RESOURCES
    src/shimgvw.rc
)

# Create the executable
add_executable(shimgvw ${SOURCES} ${HEADERS} ${RESOURCES})

# Include directories
target_include_directories(shimgvw PRIVATE src)

# Set target properties
set_target_properties(shimgvw PROPERTIES
    OUTPUT_NAME "PhotoViewer"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/release"
    WIN32_EXECUTABLE TRUE
)

# Link libraries
target_link_libraries(shimgvw PRIVATE
    kernel32
    user32
    gdi32
    shell32
    ole32
    oleaut32
    comdlg32
    comctl32
    shlwapi
)

# Installation
install(TARGETS shimgvw
    RUNTIME DESTINATION bin
)

install(FILES README.md LICENSE
    DESTINATION .
)

# Package configuration
set(CPACK_PACKAGE_NAME "ShellImageViewer")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
set(CPACK_PACKAGE_VENDOR "Community Project")
set(CPACK_GENERATOR "ZIP;NSIS")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

include(CPack)

# Print build information
message(STATUS "")
message(STATUS "Shell Image Viewer ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "")

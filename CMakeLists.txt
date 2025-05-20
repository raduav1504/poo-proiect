cmake_minimum_required(VERSION 3.26)

# --------------------------------------------------------------------
# project & compiler settings
# --------------------------------------------------------------------
set(MAIN_PROJECT_NAME "oop")
set(MAIN_EXECUTABLE_NAME "${MAIN_PROJECT_NAME}")

project(${MAIN_PROJECT_NAME})

set(CMAKE_CXX_STANDARD      23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS    OFF)

include(cmake/Options.cmake)
include(cmake/CompilerFlags.cmake)
include(cmake/CopyHelper.cmake)

# --------------------------------------------------------------------
# collect sources
# --------------------------------------------------------------------
# - everything under src/*.cpp
# - plus your generated stub in generated/src/
file(GLOB_RECURSE PROJECT_SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/generated/src/*.cpp"
)

# --------------------------------------------------------------------
# create executable
# --------------------------------------------------------------------
add_executable(${MAIN_EXECUTABLE_NAME}
    main.cpp
    ${PROJECT_SOURCES}
)

# --------------------------------------------------------------------
# includes
# --------------------------------------------------------------------
# your headers live in include/ and generated/include/
target_include_directories(${MAIN_EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/generated/include
)

# silence warnings in generated code
target_include_directories(${MAIN_EXECUTABLE_NAME}
    SYSTEM PRIVATE
        ${CMAKE_SOURCE_DIR}/generated/include
)

# --------------------------------------------------------------------
# sanitizers, install, copy-helper
# --------------------------------------------------------------------
# MSan on Clang/Linux is giving a stack overflow in CI; disable sanitizers there,
# but keep them on everywhere else.
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(RUN_SANITIZERS FALSE CACHE BOOL "Disable MSan on Clang/Linux" FORCE)
else()
  set(RUN_SANITIZERS TRUE  CACHE BOOL "Enable sanitizers (ASan/UBSan/TSan etc.)" FORCE)
endif()

set_compiler_flags(
  RUN_SANITIZERS ${RUN_SANITIZERS}
  TARGET_NAMES  ${MAIN_EXECUTABLE_NAME}
)

install(TARGETS ${MAIN_EXECUTABLE_NAME}
        DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command
            DESTINATION ${DESTINATION_DIR})
endif()

copy_files(FILES tastatura.txt
           COPY_TO_DESTINATION
           TARGET_NAME ${MAIN_EXECUTABLE_NAME})

install(TARGETS ${MAIN_EXECUTABLE_NAME}
        DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command
            DESTINATION ${DESTINATION_DIR})
endif()

copy_files(FILES tastatura.txt
           COPY_TO_DESTINATION
           TARGET_NAME ${MAIN_EXECUTABLE_NAME})

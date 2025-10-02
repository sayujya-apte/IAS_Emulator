cmake_minimum_required(VERSION 3.1)
project(IAS_Emulator)

set(
    SOURCE_FILES

    src/main.c
    src/mem.c
    src/instr.c
    src/machine.c
    
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE_FILES}
)

set(
    INCLUDE_DIRS
    src/
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${INCLUDE_DIRS}
)

include_directories(${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)

set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
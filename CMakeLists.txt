cmake_minimum_required(VERSION 3.16)

project(main) # optional (... VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MVSC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ensure conanbuildinfo.cmake exists
if (NOT EXISTS ${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
    message(STATUS "The file conanbuildinfo.cmake doesn't exist, installing conan file")
    find_program(conan conan)
    if(NOT EXISTS ${conan})
        message(FATAL_ERROR "Please install conan!")
    else()
        execute_process(COMMAND ${conan} install . --build missing RESULT_VARIABLE return_code)
        if(NOT ${return_code} EQUAL 0)
            message(FATAL_ERROR "conan install command failed")
        endif()
    endif()
endif ()
# setup conan
include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(CONAN_INCLUDE_DIRS)


include_directories(include)

file(GLOB project_sources
    "${PROJECT_SOURCE_DIR}/src/**"
)
file(GLOB test_sources
    "${PROJECT_SOURCE_DIR}/test/**"
)

add_executable(${PROJECT_NAME} main.cpp ${project_sources})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

add_executable(${PROJECT_NAME}Test test.cpp ${project_sources} ${test_sources})
target_link_libraries(${PROJECT_NAME}Test ${CONAN_LIBS})

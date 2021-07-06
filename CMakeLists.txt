cmake_minimum_required(VERSION 3.10)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

project(university---db)

set(SOURCE Student.cpp University.cpp)
set(FLAGS -Wall -Wextra -Werror -Wpedantic -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCE})
target_compile_options( ${PROJECT_NAME}-lib PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options( ${PROJECT_NAME} PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

add_executable(${PROJECT_NAME}-ut ./test/greeter.ut.cpp)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
set_target_properties(${PROJECT_NAME}-ut PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_compile_options( ${PROJECT_NAME}-ut PRIVATE ${FLAGS})

enable_testing()
add_test(NAME unitTests COMMAND ./${PROJECT_NAME}-ut)

cmake_minimum_required(VERSION 3.10)

project(university---db)

set(SOURCE Student.cpp University.cpp Employee.cpp Menu.cpp Person.cpp catch_amalgamated.cpp catch_main.cpp test.cpp)
set(FLAGS -Wall -Wextra  -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCE})
target_compile_options( ${PROJECT_NAME}-lib PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options( ${PROJECT_NAME} PRIVATE ${FLAGS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
# Add catch2
add_executable(${PROJECT_NAME}-ut test.cpp )
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
set_target_properties(${PROJECT_NAME}-ut PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_compile_options( ${PROJECT_NAME}-ut PRIVATE ${FLAGS})

enable_testing()
add_test(NAME unitTests COMMAND ./${PROJECT_NAME}-ut --success)
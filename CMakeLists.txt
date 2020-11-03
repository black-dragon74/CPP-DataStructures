cmake_minimum_required(VERSION 3.17)
project(CPP_DataStructures)

set(CMAKE_CXX_STANDARD 20)

# List of all the ds libraries
set(ds_libs
        LinkedList)

# List of all the subdirectories that include the libraries
set(ds_subdirs
        ${PROJECT_SOURCE_DIR}/SinglyLinkedList)

# List of all the header-only libraries (required for code insights to work)
set(ds_library_headers
        ${PROJECT_SOURCE_DIR}/SinglyLinkedList/linkedlist.hpp)

# Add executable and build the libraries
add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(${ds_subdirs})

# Link the libraries to the executable
target_link_libraries(${PROJECT_NAME} ${ds_libs})

# For code insights to work in IDEs
target_sources(LinkedList INTERFACE ${ds_library_headers})
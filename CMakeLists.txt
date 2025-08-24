cmake_minimum_required(VERSION 3.10)
project(CloudStorageManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(cloud_storage
    src/main.cpp
    src/Utils.cpp
    src/StorageManager.cpp
)

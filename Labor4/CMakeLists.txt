cmake_minimum_required(VERSION 3.24)
project(Labor4v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor4v2 shop.cpp Fruit.cpp Repo.cpp ShopController.cpp ShopUI.cpp RepositoryTests.h RepositoryTests.cpp ControllerTests.cpp)

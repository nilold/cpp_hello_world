cmake_minimum_required(VERSION 3.16)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 14)

add_executable(HelloWorld main.cpp data-structures/ArrayList.h design-patterns/adapter.h design-patterns/builder.h design-patterns/observer.h design-patterns/visitor.h data-structures/heap.h)
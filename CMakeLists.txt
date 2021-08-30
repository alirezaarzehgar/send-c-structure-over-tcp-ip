cmake_minimum_required(VERSION 3.0)

project(example)

add_executable(server
    server/main.c
)

add_executable(client
    client/main.c
)
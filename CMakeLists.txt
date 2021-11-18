project(database)

set(target database_facade)

file(GLOB sources
    ${CMAKE_CURRENT_SOURCE_DIR}/db_facade.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/db_facade.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

add_executable(${target} ${sources})

target_link_libraries(${target}
       MySQL::MySQL)

target_include_directories(${target}
     PRIVATE
       ${PROJECT_SOURCE_DIR})

set_property(TARGET ${target}
     PROPERTY
       CXX_STANDARD 17)

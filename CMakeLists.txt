cmake_minimum_required(VERSION 3.20)

project(cliparse)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB sourcefiles ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(cliparse_e ${sourcefiles})

include(FetchContent)


set(cliparse_deps m)





add_library(cliparse SHARED ${sourcefiles})
add_library(cliparse_static STATIC ${sourcefiles})


target_link_libraries(cliparse PUBLIC ${cliparse_deps})
target_link_libraries(cliparse_e PUBLIC ${cliparse_deps})
target_link_libraries(cliparse_static PUBLIC ${cliparse_deps})




target_include_directories(
  cliparse_e
    PUBLIC
      $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      ${CMAKE_CURRENT_BINARY_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR}/include)


target_include_directories(
  cliparse
    PUBLIC
      $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      ${CMAKE_CURRENT_BINARY_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR}/include)



target_include_directories(
  cliparse_static
    PUBLIC
      $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      ${CMAKE_CURRENT_BINARY_DIR}/include
      ${CMAKE_CURRENT_SOURCE_DIR}/include)

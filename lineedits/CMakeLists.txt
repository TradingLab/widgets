project(lineedits)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(lineedits_SRCS lineedits.cpp main.cpp)
qt4_automoc(${lineedits_SRCS})
add_executable(lineedits ${lineedits_SRCS})
target_link_libraries(lineedits ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS lineedits RUNTIME DESTINATION bin)

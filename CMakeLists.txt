cmake_minimum_required(VERSION 3.12)
project(SFML_Template)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Alien.cpp Bullet.cpp Player.cpp) 

find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
add_executable(SFML_Template main.cpp Alien.h Alien.cpp Player.h Player.cpp Bullet.h Bullet.cpp)

if( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" AND MINGW )
    include_directories("C:/mingw/include")
    include_directories("C:/mingw64/include")
    include_directories("C:/mingw64/mingw64/include")
    include_directories("C:/mingw64/x86_64-w64-mingw32/include")
    
    target_link_directories(SFML_Template PUBLIC "C:/mingw/lib")
    target_link_directories(SFML_Template PUBLIC "C:/mingw64/lib")
    target_link_directories(SFML_Template PUBLIC "C:/mingw64/mingw64/lib")
    target_link_directories(SFML_Template PUBLIC "C:/mingw64/x86_64-w64-mingw32/lib")
elseif(UNIX AND ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    target_link_libraries(SFML_Template sfml-graphics sfml-system sfml-window )
endif()

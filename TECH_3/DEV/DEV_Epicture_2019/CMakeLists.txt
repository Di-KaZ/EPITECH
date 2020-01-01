project(Rtype)
cmake_minimum_required(VERSION 2.8.12)

add_definitions("-fPIC")
add_definitions("-g3")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

#sfml
find_package(SFML 2.5.1 COMPONENTS graphics audio window system REQUIRED)
# include_directories(${SFML_INCLUDE_DIR})

# Server sources
FILE(GLOB ServerSources ./src/Server/*.cpp)

# Client Sources
FILE(GLOB ClientSources ./src/Client/*.cpp ./src/Client/SFML/GameEngine/*.cpp ./src/Client/SFML/*.cpp ./src/Client/SFML/Game/*.cpp ./src/Object/*.cpp)


# Headers
set(ServerHeaders ./include/Server)
set(ECSHeaders ./include/Object)
set(ClientHeaders ./include/Client)
set(SFMLHeaders ./include/SFML ./include/SFML/GameEngine ./include/SFML/Game)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

# Setup Conan
conan_basic_setup()

find_package(Threads REQUIRED)
include_directories(${CMAKE_INCLUDE_PATH} ${ClientHeaders} ${ECSHeaders} ${ServerHeaders} ${SFMLHeaders})

add_executable(r-type_client ${ClientSources})
target_link_libraries(r-type_client ${CONAN_LIBS})
target_link_libraries(r-type_client sfml-graphics sfml-audio sfml-window sfml-system)
target_link_libraries(r-type_client Threads::Threads)

add_executable(r-type_server ${ServerSources})
target_link_libraries(r-type_server Threads::Threads)

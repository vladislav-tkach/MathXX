cmake_minimum_required(VERSION 3.20.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../")

project(Math++
	VERSION 0.0.0
	LANGUAGES CXX
)

include(GenerateExportHeader)
include_directories(${CMAKE_BINARY_DIR}/exports)
set(EXPORT_HEADER_DIR ${CMAKE_BINARY_DIR}/exports)
set(RESOURCES_DIR ${CMAKE_BINARY_DIR}/resources)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

message(STATUS "Populating googletest")
FetchContent_MakeAvailable(googletest)
message(STATUS "Populating googletest - done")

enable_testing()

add_subdirectory(src)
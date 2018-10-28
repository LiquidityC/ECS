cmake_minimum_required (VERSION 3.8.0)

SET(CMAKE_COLOR_MAKEFILE ON)

project(ecs CXX)

set(ecs_TITLE "ECS")
set(ecs_MAJOR_VERSION 0)
set(ecs_MINOR_VERSION 0)
set(ecs_PATCH_VERSION 1)
set(ecs_RELEASE_TYPE "(alfa)")

include(mk/cmake/FindCCache.cmake)
include(mk/cmake/Findcppcheck.cmake)

configure_file(
	"${PROJECT_SOURCE_DIR}/src/Config.h.in"
	"${PROJECT_BINARY_DIR}/Config.h"
	)

include_directories(
	${PROJECT_BINARY_DIR}
	)

add_definitions(-std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG
	"${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -fsanitize=address -fno-omit-frame-pointer -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wconversion -Wno-sign-conversion"
	)

add_library(ecs SHARED
	src/Entity
	src/Component
	src/Blank
	)

add_executable(testecs
	src/Entity
	src/Component
	test/catch
	test/Main
	test/TestEntity
	test/TestComponent
	test/TestUpdate
	test/TestMessage
	test/TestECS
	)

enable_testing()
add_test(NAME testecs
	COMMAND testecs
	)

# LINT:
if (CPPCHECK_FOUND)
	add_custom_target(lint
		COMMAND ${CPPCHECK_EXECUTABLE} --force --language=c++ --template=gcc --error-exitcode=1 --quiet --enable=warning,style,performance,portability,information,missingInclude src/
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Run cppcheck"
		)
endif (CPPCHECK_FOUND)

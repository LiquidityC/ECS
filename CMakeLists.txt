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

option(ECS_LINT_ENABLED "Enable lintecs build target" on)
option(ECS_TESTS_ENABLED "Enable testecs build target and testing" on)

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

if (ECS_TESTS_ENABLED)
	add_executable(testecs
		src/Entity
		src/Component
		test/catch
		test/Main
		test/TestEntity
		test/TestComponent
		test/TestUpdate
		test/TestMessage
		test/TestUpdateComponent
		test/TestChangeComponent
		test/TestECS
		)

	enable_testing()
	add_test(NAME testecs
		COMMAND testecs
		)
endif()

if (ECS_LINT_ENABLED)
	# LINT:
	if (CPPCHECK_FOUND)
		add_custom_target(lintecs
			COMMAND ${CPPCHECK_EXECUTABLE} --force --language=c++ --template=gcc --error-exitcode=1 --quiet --enable=warning,style,performance,portability,information,missingInclude src/
			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
			COMMENT "Run cppcheck"
			)
	endif (CPPCHECK_FOUND)
endif()

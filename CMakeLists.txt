cmake_minimum_required(VERSION 3.10)

#project_name
project(just_fun VERSION 1.0)

#specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use just_fun provided math implement" ON)

#configure a header file to pass some of the CMake settings
#to the source code
configure_file(just_fun.h.in just_fun.h)

#add_subdirectory(MathFunctions)

if(USE_MYMATH)
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
endif()

#add_execute
add_executable(just_fun fun.cpp)

target_link_libraries(just_fun PUBLIC ${EXTRA_LIBS})

#add the binary tree to the search path for include files
#so that we will find just_fun.h
target_include_directories(just_fun PUBLIC
			"${PROJECT_BINARY_DIR}"
			)	


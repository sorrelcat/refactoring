cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 11)
project(calculator)

add_subdirectory(googletest)

set(SOURCES
    calculator.cc
	pair.cc
	plusoperation.cc
	minusoperation.cc
	divideoperation.cc
	multiplyoperation.cc
	ioperation.cc
)

add_executable(calculator_test
                calculator_test.cc
                ${SOURCES})

target_link_libraries(calculator_test gtest gmock_main)
add_test(NAME calculator_test COMMAND test)

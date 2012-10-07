cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

function(simple_test TEST_NAME)
	add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction(simple_test TEST_NAME)

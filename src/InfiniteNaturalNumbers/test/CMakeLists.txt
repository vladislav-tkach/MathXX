set(TargetName "InfiniteNaturalNumbers.UnitTests")

file(GLOB_RECURSE SRC_FILES *)

add_executable(${TargetName} ${SRC_FILES})

target_link_libraries(${TargetName}
	PUBLIC
	gtest
	gtest_main
	InfiniteNaturalNumbers
)

add_test(NAME ${TargetName} COMMAND ${TargetName})
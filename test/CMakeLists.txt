project(test)

add_subdirectory(lib/gtest-1.8.0)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runUnitTests MinimumSearchTest.cpp SelectionSortTest.cpp InsertionSortTest.cpp ArrayFiller.cpp)

target_link_libraries(runUnitTests gtest gtest_main)


include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(sdktest_test sdktest_test.cpp)

target_link_libraries(sdktest_test
 PRIVATE
  GTest::GTest
  exercise1)
  
target_link_libraries(sdktest_test
PRIVATE
 GTest::GTest
 exercise2)

add_test(sdktest_gtests sdktest_test)
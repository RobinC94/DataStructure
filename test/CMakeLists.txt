cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/.repo)

project(Test)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

set(INCLUDE_DIR ${DataStructure_SOURCE_DIR}/include)
set(SOURCE_DIR ${DataStructure_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})
file(GLOB ALL_SRC "${SOURCE_DIR}/*.cpp")

#add_library(dataStructure ${ALL_SRC})

#set(test_SRCS ADD ALL TEST SOURCE FILES HERE)
add_executable(runSeqListTest seqList_test.cpp)
target_link_libraries(runSeqListTest gtest)
#target_link_libraries(runSeqListTest dataStructure)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does.
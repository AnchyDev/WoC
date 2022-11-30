set(WOC_MODULE_DIR ${CMAKE_SOURCE_DIR}/modules/${SOURCE_MODULE})
set(WOC_MODULE_SRC_DIR ${WOC_MODULE_DIR}/src)

message(STATUS "CMAKESOURCEDIR: ${CMAKE_SOURCE_DIR}")

target_include_directories(modules PUBLIC ${WOC_MODULE_SRC_DIR}/Config)
target_include_directories(modules PUBLIC ${WOC_MODULE_SRC_DIR}/Components)
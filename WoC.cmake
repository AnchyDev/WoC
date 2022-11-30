set(WOC_MODULE_DIR ${CMAKE_SOURCE_DIR}/modules/${SOURCE_MODULE})
set(WOC_MODULE_SRC_DIR ${WOC_MODULE_DIR}/src)

target_include_directories(modules PUBLIC ${WOC_MODULE_SRC_DIR}/Config)
target_include_directories(modules PUBLIC ${WOC_MODULE_SRC_DIR}/Components)

target_sources(modules PRIVATE ${WOC_MODULE_SRC_DIR}/Config/WoCConfig.cpp ${WOC_MODULE_SRC_DIR}/Components/WoCIGPlayerScript.cpp) 
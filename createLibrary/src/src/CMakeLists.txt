aux_source_directory(. srcs)

include_directories(${PROJECT_SOURCE_DIR}/include )

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 生成动态库目标
add_library(person SHARED ${srcs})
# 生成静态库目标
add_library(person_static STATIC ${srcs})

# 指定静态库的输出名称
set_target_properties(person_static PROPERTIES OUTPUT_NAME "person")
# 使动态库和静态库同时存在
set_target_properties(person PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(person_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
set_target_properties(person PROPERTIES VERSION 1.0 SOVERSION 1)
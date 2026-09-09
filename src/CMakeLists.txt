set(target ${MP2_LIBRARY})

file(GLOB hdrs "*.h*" "${MP2_INCLUDES}/*.h*")
file(GLOB srcs "*.c*")

add_library(${target} STATIC ${srcs} ${hdrs})
target_include_directories(${target} PUBLIC "${MP2_INCLUDES}")
target_link_libraries(${target} ${LIBRARY_DEPS})

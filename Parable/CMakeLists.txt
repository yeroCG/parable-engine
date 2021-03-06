add_subdirectory(src)

set(PARABLE_INCLUDE_DIRS src)

# Adding libraries
set(PARABLE_VENDOR  ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

add_subdirectory(${PARABLE_VENDOR}/glfw)
add_subdirectory(${PARABLE_VENDOR}/glad)
add_subdirectory(${PARABLE_VENDOR}/Catch2)

add_library(Parable STATIC ${PARABLE_SRCS})

target_link_libraries(Parable PRIVATE glfw glad)

target_include_directories(Parable PUBLIC ${PARABLE_INCLUDE_DIRS} ${PARABLE_VENDOR}/spdlog/include ${PARABLE_VENDOR}/glm ${PARABLE_VENDOR}/rapidjson/include)

target_precompile_headers(Parable PRIVATE src/pblpch.h)

# config definitions
target_compile_definitions(Parable PUBLIC $<$<CONFIG:Debug>:PBL_DEBUG> $<$<CONFIG:Release>:PBL_RELEASE>)
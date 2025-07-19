add_library(logger STATIC
    app_logger.cpp
)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

target_link_libraries(logger PRIVATE spdlog::spdlog)
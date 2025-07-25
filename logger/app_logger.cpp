#include "app_logger.h"

app_logger::app_logger(std::string log_level)
{
    this->logger = spdlog::stdout_color_mt("console");
    auto level = str2level(log_level);
    spdlog::set_level(level);
}

std::shared_ptr<spdlog::logger> app_logger::get_logger() {
    return this->logger;
}

spdlog::level::level_enum app_logger::str2level(const std::string& level_str) {
    if (level_str == "trace") return spdlog::level::trace;
    else if (level_str == "debug") return spdlog::level::debug;
    else if (level_str == "info") return spdlog::level::info;
    else if (level_str == "warn") return spdlog::level::warn;
    else if (level_str == "error") return spdlog::level::err;
    else if (level_str == "critical") return spdlog::level::critical;
    else return spdlog::level::off;
}
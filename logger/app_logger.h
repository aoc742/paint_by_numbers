#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // for logger object

class app_logger
{
public:
    app_logger();
    std::shared_ptr<spdlog::logger> get_logger();

private:
    std::shared_ptr<spdlog::logger> logger;

    spdlog::level::level_enum str2level(const std::string& level_str);
};
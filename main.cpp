#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include "app_config.h"
#include "logger/app_logger.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]){
    app_logger app_logger;
    auto logger = app_logger.get_logger();

    auto cfg = app_config_ns::app_config();
    std::ifstream f(argv[1]);
    json j = json::parse(f);
    app_config_ns::from_json(j, cfg);

    logger->info("Log level set to: {}", cfg.log_level);

    std::cout << "Hello world" << std::endl;
}
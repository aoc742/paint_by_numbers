#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include "app_config.h"
#include "logger/app_logger.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[]){
    auto cfg = app_config_ns::app_config();
    std::ifstream f(argv[1]);
    json j = json::parse(f);
    app_config_ns::from_json(j, cfg);

    app_logger app_logger(cfg.log_level);
    auto logger = app_logger.get_logger();
    logger->info("Log level set to: {}", cfg.log_level);

    std::string input_file = argv[2];
    logger->info("Input file: {}", input_file);

    
}
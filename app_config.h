#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace app_config_ns {
    struct app_config
    {
        std::string log_level = "info";
    };
    
    void from_json(const json& j, app_config& cfg) {
        cfg.log_level = j.value("log_level", cfg.log_level);
    }
}


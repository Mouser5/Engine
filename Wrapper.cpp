#include "wrapper.h"
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <algorithm>

using InputArgs = std::vector<std::pair<std::string, std::string>>;
using ArgsMap = std::vector<std::pair<std::string, std::string>>;

std::string Wrapper::execute(const ArgsMap& args_map) {
    if (args_map.size() != argsTitles.size()) {
        std::cerr << "Wrong number of arguments." << std::endl;
        return "";
    }
    std::vector<std::string> argsFunc;
    for (const auto& title : args_map) {
        argsFunc.push_back(title.second);
    }
    return function(argsFunc);
}
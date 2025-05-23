#pragma once
#include <vector>
#include <functional>
#include <string>
#include <iostream>

using InputArgs = std::vector<std::pair<std::string, std::string>>;
using ArgsMap = std::vector<std::pair<std::string, std::string>>;

class Wrapper { 
private:
    template <typename Subj, typename Method, std::size_t... I>
    std::string func_call(Subj* subject, Method method, const std::vector<std::string>& args, std::index_sequence<I...>) {
        return (subject->*method)(args[I]...);
    }
    std::function<std::string(const std::vector<std::string>& argsVector)> function; 
    std::vector<std::string> argsTitles;
public:
    template<typename Subj, typename... Args>
    Wrapper(Subj* subject, std::string(Subj::* method)(Args...), const InputArgs& input_args) {
        if (input_args.size() != sizeof...(Args)) {
            std::cerr << "Wrong number of arguments." << std::endl;
        }

        for (const auto& arg : input_args) {
            argsTitles.push_back(arg.first);
        }

        function = [this, subject, method](const std::vector<std::string>& argsVector) {
            return func_call(subject, method, argsVector, std::index_sequence_for<Args...>{}); 
        };
    }
    std::string execute(const ArgsMap& args_map);
};
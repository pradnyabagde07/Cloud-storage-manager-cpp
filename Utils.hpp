#pragma once
#include <string>
#include <vector>

namespace Utils {
    std::string hashPassword(const std::string &password);
    std::vector<std::string> split(const std::string &s, char delimiter);
}

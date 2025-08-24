#include "Utils.hpp"
#include <sstream>
#include <functional>

namespace Utils {
    std::string hashPassword(const std::string &password) {
        std::hash<std::string> hasher;
        return std::to_string(hasher(password));
    }

    std::vector<std::string> split(const std::string &s, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(s);
        std::string item;
        while (getline(ss, item, delimiter)) {
            tokens.push_back(item);
        }
        return tokens;
    }
}

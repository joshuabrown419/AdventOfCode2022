#ifndef COLORS
#define COLORS
#include <iostream>
namespace Colors {
    static const std::string RESET   = "\033[0m";
    static const std::string BLACK   = "\033[30m";
    static const std::string RED     = "\033[31m";
    static const std::string GREEN   = "\033[32m";
    static const std::string YELLOW  = "\033[33m";
    static const std::string BLUE    = "\033[34m";
    static const std::string MAGENTA = "\033[35m";
    static const std::string CYAN    = "\033[36m";
    static const std::string WHITE   = "\033[37m";
    static const std::string BOLD    = "\033[1m";
}
#endif

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <chrono>

class Utils {
    public:
        static std::vector<std::string>* loadFile(std::string filepath);
        static void printHeader(std::string dayTitle);
        static std::string color_text(const std::string in, const std::string color);
        static void startPart(std::string title);
        static void stopPart();
};

#endif
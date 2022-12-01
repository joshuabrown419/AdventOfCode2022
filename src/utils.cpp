#include "utils.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>


std::vector<std::string>* Utils::loadFile(std::string filepath) {
    std::vector<std::string>* vector = new std::vector<std::string>();

    std::ifstream input(filepath);
    std::string line;
    while(std::getline(input, line)){
        vector->push_back(line);
    }
    input.close();
    return vector;
}

void Utils::printHeader(std::string day) {
    const std::string adventStr = "Advent of Code 2022";
    size_t width = 30;

    const std::string topBotStr = "+" + std::string(width, '-') + "+";
    const std::string fmt = "{:^" + std::to_string(width) + "}";
    const std::string adventLine = adventStr;
    const std::string nameLine = day;

    std::cout << Utils::color_text(topBotStr + "\n|", Colors::GREEN);
    std::cout << Utils::color_text(adventLine, Colors::BOLD + Colors::BLUE);
    std::cout << Utils::color_text("|\n|", Colors::GREEN);
    std::cout << Utils::color_text(nameLine, Colors::BLUE);
    std::cout << Utils::color_text("|\n" + topBotStr + "\n", Colors::GREEN);
}

std::string Utils::color_text(const std::string in, const std::string color) {
    return color + in + Colors::RESET;
}

void printSeperator() {
    size_t width = 30;
    const std::string topBotStr = "+" + std::string(width, '-') + "+";
    std::cout << Utils::color_text(topBotStr + "\n", Colors::GREEN);
}

std::chrono::system_clock::time_point startTime;
std::string title;

void Utils::startPart(std::string partTitle) {
    title = partTitle;
    startTime = std::chrono::high_resolution_clock::now();

    
    std::cout << Utils::color_text("|", Colors::GREEN);
    partTitle = "Starting " + partTitle;
    std::cout << Utils::color_text(partTitle, Colors::MAGENTA);
    std::cout << Utils::color_text("|\n", Colors::GREEN);
    printSeperator();
}

void Utils::stopPart() {
    auto runTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime);
    
    printSeperator();
    std::cout << Utils::color_text("|", Colors::GREEN);
    std::cout << Utils::color_text(title.append(" ran in "), Colors::MAGENTA) << runTime.count() << "ms";
    std::cout << Utils::color_text("|\n", Colors::GREEN);
    printSeperator();
}
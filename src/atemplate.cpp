#include "utils.h"
#include <iostream>

#define DAY "dayx"

void part_1(std::vector<std::string>* input) {

}

void part_2(std::vector<std::string>* input) {

}

int main() {
    Utils::printHeader(DAY);
    std::vector<std::string>* input = Utils::loadFile("input/day_x.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
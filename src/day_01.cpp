#include "utils.h"
#include <iostream>
#include <algorithm>

#define DAY "day_01"

void part_1(std::vector<std::string>* input) {
    std::vector<int> elves;

    int i = 0;
    elves.push_back(0);
    for(std::string line : *input){
        if(line.length() == 1){
            // std::cout << elves.at(i) << std::endl;
            i++;
            elves.push_back(0);
            continue;
        }

        elves.at(i) += std::atoi(line.c_str());
        
    }

    std::cout << *std::max_element(elves.begin(), elves.end()) << std::endl;
}

void part_2(std::vector<std::string>* input) {
    std::vector<int> elves;

    int i = 0;
    elves.push_back(0);
    for(std::string line : *input){
        if(line.length() == 1){
            // std::cout << elves.at(i) << std::endl;
            i++;
            elves.push_back(0);
            continue;
        }

        elves.at(i) += std::atoi(line.c_str());
    }

    std::sort(elves.begin(), elves.end(), std::greater<int>());

    int sum = elves.at(0) + elves.at(1) + elves.at(2);
    std::cout << sum << std::endl;
}

int main() {
    Utils::printHeader(DAY);
    std::vector<std::string>* input = Utils::loadFile("input/day_01.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();

}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DAY "day_x"

void part_1(vector<string>* input) {

}

void part_2(vector<string>* input) {

}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_x.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define DAY "day_06"

void part_1(vector<string>* input) {
    string line = input->at(0);
        for(int i = 0; i < line.length() - 3; i++) {
            string substr = line.substr(i, 4);
            int counter[27] = { 0 };
            for(int j = 0; j < 4; j++) {
                counter[substr.at(j) - 97] += 1;
            }

            int max = *max_element(counter, counter + 27);
            if(max >= 2) continue;

            cout << i+4 << endl;
            break;
        }
}

void part_2(vector<string>* input) {
    string line = input->at(0);
        for(int i = 0; i < line.length() - 3; i++) {
            string substr = line.substr(i, 14);
            int counter[27] = { 0 };
            for(int j = 0; j < 14; j++) {
                counter[substr.at(j) - 97] += 1;
            }

            int max = *max_element(counter, counter + 27);
            if(max >= 2) continue;

            cout << i+14 << endl;
            break;
        }
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_06.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DAY "day_10"

void part_1(vector<string>* input) {
    int cycles_done = 1;
    int X = 1;
    int max_cycles = 220;
    int signal_strength = 0;
    bool adding = false;

    for(int i = 0; cycles_done <= max_cycles; cycles_done++) {

        string str = input->at(i);
        string instruction = str.substr(0, 4);

        if(((cycles_done - 20) % 40) == 0){
            signal_strength += cycles_done * X;
            // cout << (cycles_done * X) << endl;

            if(cycles_done == 220) {
                cycles_done++;
                continue;
            }
        }

        if(adding) {
            X += atoi(str.substr(5, str.length() - 5).c_str());
            adding = false;
            i++;
            continue;
        }



        if(instruction == "noop") {
            // cycles_done += 1;
            i++;
        } else if (instruction == "addx") {
            // cycles_done += 2;
            adding = true;
        }
    }

    std::cout << signal_strength << endl;
}

void part_2(vector<string>* input) {
    int cycles_done = 1;
    int X = 1;
    int signal_strength = 0;
    bool adding = false;

    vector<vector<bool>> crt = vector<vector<bool>>(6, vector<bool>(40, false));

    for(int i = 0; i < input->size(); cycles_done++) {
        
        int x_pos = cycles_done % 40;
        int y_pos = cycles_done / 40;

        string str = input->at(i);
        string instruction = str.substr(0, 4);

        if(adding) {
            X += atoi(str.substr(5, str.length() - 5).c_str());
            adding = false;
            i++;
            continue;
        }

        if(instruction == "noop") {
            // cycles_done += 1;
            i++;
        } else if (instruction == "addx") {
            // cycles_done += 2;
            adding = true;
        }
    }
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_10.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
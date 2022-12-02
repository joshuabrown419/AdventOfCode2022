#include "utils.h"
#include <iostream>
#include <vector>
#include <string>

#define DAY "day02"

/*
A = Rock
B = Paper
C = Scissors

X = Rock
Y = Paper
Z = Scissors
*/

void part_1(std::vector<std::string>* input) {
    int score = 0;
    for(std::string line : *input){
        char opponnent = line.substr(0, 1)[0];
        char you = line.substr(2, 1)[0];

        if((opponnent == 'A' && you == 'X') || (opponnent == 'B' && you == 'Y') || (opponnent == 'C' && you == 'Z')) {
            score += 3;
        } else if ((opponnent == 'A' && you == 'Z') || (opponnent == 'B' && you == 'X') || (opponnent == 'C' && you == 'Y')) {
            score += 0;
        } else {
            score += 6;
        }

        switch(you) {
            case 'X':
                score += 1;
                break;
            case 'Y':
                score += 2;
                break;
            case 'Z':
                score += 3;
                break;
        }
    }

    std::cout << score << std::endl;
}

/*
X = Loose
Y = Draw
Z = Win
*/

/*
A = Rock
B = Paper
C = Scissors

X = Rock
Y = Paper
Z = Scissors
*/

void part_2(std::vector<std::string>* input) {
    int score = 0;
    for(std::string line : *input){
        char opponnent = line.substr(0, 1)[0];
        char end = line.substr(2, 1)[0];
        char you;

        if(end == 'X') {
            if(opponnent == 'A'){
                you = 'Z';
            } else if(opponnent == 'B') {
                you = 'X';
            } else {
                you = 'Y';
            }
        } else if(end == 'Y') {
            if(opponnent == 'A'){
                you = 'X';
            } else if(opponnent == 'B') {
                you = 'Y';
            } else {
                you = 'Z';
            }
        } else {
            if(opponnent == 'A'){
                you = 'Y';
            } else if(opponnent == 'B') {
                you = 'Z';
            } else {
                you = 'X';
            }
        }

        if((opponnent == 'A' && you == 'X') || (opponnent == 'B' && you == 'Y') || (opponnent == 'C' && you == 'Z')) {
            score += 3;
        } else if ((opponnent == 'A' && you == 'Z') || (opponnent == 'B' && you == 'X') || (opponnent == 'C' && you == 'Y')) {
            score += 0;
        } else {
            score += 6;
        }

        switch(you) {
            case 'X':
                score += 1;
                break;
            case 'Y':
                score += 2;
                break;
            case 'Z':
                score += 3;
                break;
        }
    }

    std::cout << score << std::endl;
}

int main() {
    Utils::printHeader(DAY);
    std::vector<std::string>* input = Utils::loadFile("input/day_02.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define DAY "day_09"

void part_1(vector<string>* input) {
    int hx = 499, hy = 499, tx = 499, ty = 499, visited = 0;

    vector<vector<bool>> grid = vector<vector<bool>>(1000, vector<bool>(1000, false));

    for(string line : *input) {
        char dir = line.at(0);

        for(int count = atoi(line.substr(2, line.length() - 2).c_str()); count > 0; count--) {
            switch(dir) {
                case 'U':
                    hy++;
                    break;
                case 'D':
                    hy--;
                    break;
                case 'L':
                    hx--;
                    break;
                case 'R':
                    hx++;
                    break;
            }

            // cout << "hx: " << hx << " hy: " << hy << " tx: " << tx << " ty: " << ty << endl;

            if(abs(hy - ty) >= 2) {
                tx += hx > tx ? 1 : (hx == tx ? 0 : -1);
                ty += hy > ty ? 1 : -1;
            } else if(abs(hx - tx) >= 2) {
                ty += hy > ty ? 1 : (hy == ty ? 0 : -1);
                tx += hx > tx ? 1 : -1;
            }

            if(!grid.at(ty).at(tx)) {
                visited++;
                grid.at(ty).at(tx) = true;
            }
        }
    }

    cout << visited << endl;
}

class Point {
    public:
        int x;
        int y;

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

void part_2(vector<string>* input) {
    vector<Point> rope = vector<Point>(10, Point(499, 499));
    int visited = 0;

    vector<vector<bool>> grid = vector<vector<bool>>(1000, vector<bool>(1000, false));

    for(string line : *input) {
        char dir = line.at(0);

        for(int count = atoi(line.substr(2, line.length() - 2).c_str()); count > 0; count--) {
            switch(dir) {
                case 'U':
                    rope.at(0).y++;
                    break;
                case 'D':
                    rope.at(0).y--;
                    break;
                case 'L':
                    rope.at(0).x--;
                    break;
                case 'R':
                    rope.at(0).x++;
                    break;
            }

            for(int i = 1; i < rope.size(); i++) {
                int hx = rope.at(i-1).x, hy = rope.at(i-1).y;
                int tx = rope.at(i).x, ty = rope.at(i).y;

                if(abs(hy - ty) >= 2) {
                    tx += hx > tx ? 1 : (hx == tx ? 0 : -1);
                    ty += hy > ty ? 1 : -1;
                } else if(abs(hx - tx) >= 2) {
                    ty += hy > ty ? 1 : (hy == ty ? 0 : -1);
                    tx += hx > tx ? 1 : -1;
                }

                rope.at(i).x = tx;
                rope.at(i).y = ty;
            }

            if(!grid.at(rope.at(9).y).at(rope.at(9).x)) {
                visited++;
                grid.at(rope.at(9).y).at(rope.at(9).x) = true;
            }
        }
    }

    cout << visited << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_09.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
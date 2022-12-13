#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define DAY "day_08"

void part_1(vector<string>* input) {
    vector<vector<int>> treeGrid = vector<vector<int>>();

    int i = -1;
    for(string line : *input) {
        i++;
        treeGrid.push_back(vector<int>());
        for(char c : line) {
            treeGrid.at(i).push_back(c - '0');
        }
    }


    int seenCount = 0;
    for(int y = 0; y < treeGrid.size(); y++) {
        vector<int> row = treeGrid.at(y);
        for(int x = 0; x < row.size(); x++) {

            bool left = true;
            for(int xm = -1; x + xm >= 0; xm--) {
                if(row.at(x+xm) >= row.at(x)) {
                    left = false;
                    break;
                }
            }
            if(left) {
                cout << "x: " << x << " y: " << y << " left" << endl;
                seenCount++;
                continue;
            }

            bool right = true;
            for(int xp = 1; x + xp < row.size(); xp++) {
                if(row.at(x+xp) >= row.at(x)) {
                    right = false;
                    break;
                }
            }
            if(right) {
                cout << "x: " << x << " y: " << y << " right" << endl;
                seenCount++;
                continue;
            }

            bool up = true;
            for(int ym = -1; y + ym >= 0; ym--) {
                    if(treeGrid.at(y+ym).at(x) >= row.at(x)) {
                    up = false;
                    break;
                }
            }
            if(up) {
                cout << "x: " << x << " y: " << y << " up" << endl;
                seenCount++;
                continue;
            }

            bool down = true;
            for(int yp = 1; y + yp < treeGrid.size(); yp++) {
                if(treeGrid.at(y+yp).at(x) >= row.at(x)) {
                    down = false;
                    break;
                }
            }
            if(down) {
                cout << "x: " << x << " y: " << y << " down" << endl;
                seenCount++;
                continue;
            }
        }
    }

    cout << seenCount << endl;
}

void part_2(vector<string>* input) {
    vector<vector<int>> treeGrid = vector<vector<int>>();

    int i = -1;
    for(string line : *input) {
        i++;
        treeGrid.push_back(vector<int>());
        for(char c : line) {
            treeGrid.at(i).push_back(c - '0');
        }
    }


    vector<int> views = vector<int>();
    for(int y = 1; y < treeGrid.size()-1; y++) {
        vector<int> row = treeGrid.at(y);
        for(int x = 1; x < row.size()-1; x++) {

            int left = -1;
            for(int xm = -1; x + xm >= 0; left = --xm) {
                if(row.at(x+xm) >= row.at(x)) {
                    --left;
                    break;
                }
            }
            left *= -1;
            left--;
            cout << "x: " << x << " y: " << y << " left: " << left;

            int right = 1;
            for(int xp = 1; x + xp < row.size(); right = ++xp) {
                if(row.at(x+xp) >= row.at(x)) {
                    ++right;
                    break;
                }
            }
            cout << " right: " << right;
            right--;

            int up = -1;
            for(int ym = -1; y + ym >= 0; up = --ym) {
                if(treeGrid.at(y+ym).at(x) >= row.at(x)) {
                    --up;
                    break;
                }
            }
            up *= -1;
            up--;
            cout << " up: " << up;

            int down = 1;
            for(int yp = 1; y + yp < treeGrid.size(); down = ++yp) {
                if(treeGrid.at(y+yp).at(x) >= row.at(x)) {
                    ++down;
                    break;
                }
            }
            down--;
            cout << " down: " << down;

            cout << endl;

            
            views.push_back(left * right * up * down);
        }
    }

    cout << *max_element(views.begin(), views.end()) << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_08.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

#define DAY "day_14"

struct point {
    int x;
    int y;
};

void part_1(vector<string>* input) {
    bool map[1000][1000];

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            map[i][j] = false;
        }
    }

    for(string line : *input) {
        int sx, sy, ex, ey;
        stringstream ss = stringstream(line);
        string delimeter;
        char c;

        queue<struct point*> input = queue<struct point*>();

        do {
            ss >> sx;
            ss >> c;
            ss >> sy;

            struct point* point = new struct point;
            point->x = sx;
            point->y = sy;
            input.push(point);
            // cout << point->x << " x " << point->y << endl;
        } while(ss >> delimeter && delimeter == "->");

        
        while(!input.empty()) {
            sx = input.front()->x;
            sy = input.front()->y;
            input.pop();
            if(input.empty()) break;
            ex = input.front()->x;
            ey = input.front()->y;

            if(sx == ex) {
                for(int i = min(sy, ey); i <= max(sy, ey); i++) {
                    map[sx][i] = true;
                    // cout << sx << " " << i << endl;
                }
            } else if (sy == ey) {
                for(int i = min(sx, ex); i <= max(sx, ex); i++) {
                    map[i][sy] = true;
                    // cout << i << " " << sy << endl;
                }
            }
        }

        // cout << endl;
    }

    int s = -1;
    while(true) {
        int x = 500, y = 0;
        s++;
        while(y < 1000 && !(map[x][y+1] && map[x-1][y+1] && map[x+1][y+1])) {
            y++;
            if(!map[x][y]) continue;

            if(!map[x-1][y]) {
                x--;
                continue;
            }

            if(!map[x+1][y]) {
                x++;
                continue;
            }
        }

        if(y == 1000) {
            break;
        }

        map[x][y] = true;

    }

    cout << s << endl;

}

void part_2(vector<string>* input) {
    bool map[1000][1000];

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            map[i][j] = false;
        }
    }

    int my = 0;
    for(string line : *input) {
        int sx, sy, ex, ey;
        stringstream ss = stringstream(line);
        string delimeter;
        char c;

        queue<struct point*> input = queue<struct point*>();

        do {
            ss >> sx;
            ss >> c;
            ss >> sy;

            struct point* point = new struct point;
            point->x = sx;
            point->y = sy;
            input.push(point);
            // cout << point->x << " x " << point->y << endl;
        } while(ss >> delimeter && delimeter == "->");

        
        while(!input.empty()) {
            sx = input.front()->x;
            sy = input.front()->y;
            input.pop();
            if(input.empty()) break;
            ex = input.front()->x;
            ey = input.front()->y;

            if(sy > my) {
                my = sy;
            }

            if(ey > my) {
                my = ey;
            }
            if(sx == ex) {
                for(int i = min(sy, ey); i <= max(sy, ey); i++) {
                    map[sx][i] = true;
                    // cout << sx << " " << i << endl;
                }
            } else if (sy == ey) {
                for(int i = min(sx, ex); i <= max(sx, ex); i++) {
                    map[i][sy] = true;
                    // cout << i << " " << sy << endl;
                }
            }
        }

        // cout << endl;
    }

    for(int i = 0; i < 1000; i++) {
        map[i][my + 2] = true;
    }

    int s = 0;
    while(!map[500][0]) {
        int x = 500, y = 0;
        s++;
        while(!(map[x][y+1] && map[x-1][y+1] && map[x+1][y+1])) {
            y++;
            if(!map[x][y]) continue;

            if(!map[x-1][y]) {
                x--;
                continue;
            }

            if(!map[x+1][y]) {
                x++;
                continue;
            }
        }
        map[x][y] = true;
    }

    cout << s << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_14.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define DAY "day_12"

struct Node {
    int height;
    int travelCost;
    bool visited;
    int x;
    int y;
};

void part_1(vector<string>* input) {
    vector<vector<struct Node*>> heightMap = vector<vector<struct Node*>>();
    vector<struct Node*> unvisited = vector<struct Node*>();

    int sx, sy, ex, ey;
    for(int y = 0; y < input->size(); y++) {
        heightMap.push_back(vector<struct Node*>());
        for(int x = 0; x < input->at(y).length(); x++) {
            char c = input->at(y).at(x);
            if(c == 'S') {
                sx = x;
                sy = y;
                c = 'a';
            } else if (c == 'E') {
                ex = x;
                ey = y;
                c = 'z';
            }

            struct Node* node = (struct Node*) malloc(sizeof(struct Node));
            node->height = c - 'a';
            node->travelCost = INT32_MAX;
            node->x = x;
            node->y = y;

            node->visited = false;
            heightMap.at(y).push_back(node);
            unvisited.push_back(node);
        }
    }

    struct Node* curr = heightMap.at(sy).at(sx);

    curr->travelCost = 0;
    // unvisited.erase(remove_if(unvisited.begin(), unvisited.end(), [&](struct Node* remnode){ return (curr->x == remnode->x && curr->y == remnode->y); }));

    while(curr->x != ex || curr->y != ey) {
        // cout << curr->x << " " << curr->y << " " << curr->travelCost << endl;
        

        if(curr->x - 1 >= 0 && (curr->height - heightMap.at(curr->y).at(curr->x - 1)->height) >= -1) {
            struct Node* eplor = heightMap.at(curr->y).at(curr->x - 1);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->x + 1 < heightMap.at(curr->y).size() && (curr->height - heightMap.at(curr->y).at(curr->x + 1)->height) >= -1) {
            struct Node* eplor = heightMap.at(curr->y).at(curr->x + 1);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->y - 1 >= 0 && (curr->height - heightMap.at(curr->y - 1).at(curr->x)->height) >= -1) {
            struct Node* eplor = heightMap.at(curr->y-1).at(curr->x);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->y + 1 < heightMap.size() && (curr->height - heightMap.at(curr->y + 1).at(curr->x)->height) >= -1) {
            struct Node* eplor = heightMap.at(curr->y + 1).at(curr->x);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        curr->visited = true;
        unvisited.erase(remove_if(unvisited.begin(), unvisited.end(), [&](struct Node* remnode){ return (curr->x == remnode->x && curr->y == remnode->y); }));

        struct Node* nextNode = unvisited.at(0);
        for(struct Node* node : unvisited) {
            if(node->travelCost < nextNode->travelCost) { 
                nextNode = node;
            }
            // cout << "nx:" << node->x << " ny:" << node->y << "    ";
        }
        curr = nextNode;
    }

    cout << curr->travelCost << endl;
}

void part_2(vector<string>* input) {
    vector<vector<struct Node*>> heightMap = vector<vector<struct Node*>>();
    vector<struct Node*> unvisited = vector<struct Node*>();

    int sx, sy, ex, ey;
    for(int y = 0; y < input->size(); y++) {
        heightMap.push_back(vector<struct Node*>());
        for(int x = 0; x < input->at(y).length(); x++) {
            char c = input->at(y).at(x);
            if(c == 'S') {
                sx = x;
                sy = y;
                c = 'a';
            } else if (c == 'E') {
                ex = x;
                ey = y;
                c = 'z';
            }

            struct Node* node = (struct Node*) malloc(sizeof(struct Node));
            node->height = c - 'a';
            node->travelCost = INT32_MAX;
            node->x = x;
            node->y = y;

            node->visited = false;
            heightMap.at(y).push_back(node);
            unvisited.push_back(node);
        }
    }

    struct Node* curr = heightMap.at(ey).at(ex);

    curr->travelCost = 0;
    // unvisited.erase(remove_if(unvisited.begin(), unvisited.end(), [&](struct Node* remnode){ return (curr->x == remnode->x && curr->y == remnode->y); }));

    while(curr->height != 0) {
        // cout << curr->x << " " << curr->y << " " << curr->travelCost << endl;
        

        if(curr->x - 1 >= 0 && (curr->height - heightMap.at(curr->y).at(curr->x - 1)->height) <= 1) {
            struct Node* eplor = heightMap.at(curr->y).at(curr->x - 1);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->x + 1 < heightMap.at(curr->y).size() && (curr->height - heightMap.at(curr->y).at(curr->x + 1)->height) <= 1) {
            struct Node* eplor = heightMap.at(curr->y).at(curr->x + 1);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->y - 1 >= 0 && (curr->height - heightMap.at(curr->y - 1).at(curr->x)->height) <= 1) {
            struct Node* eplor = heightMap.at(curr->y-1).at(curr->x);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        if(curr->y + 1 < heightMap.size() && (curr->height - heightMap.at(curr->y + 1).at(curr->x)->height) <= 1) {
            struct Node* eplor = heightMap.at(curr->y + 1).at(curr->x);
            eplor->travelCost = curr->travelCost + 1 < eplor->travelCost ? curr->travelCost + 1 : eplor->travelCost;
        }

        curr->visited = true;
        unvisited.erase(remove_if(unvisited.begin(), unvisited.end(), [&](struct Node* remnode){ return (curr->x == remnode->x && curr->y == remnode->y); }));

        struct Node* nextNode = unvisited.at(0);
        for(struct Node* node : unvisited) {
            if(node->travelCost < nextNode->travelCost) { 
                nextNode = node;
            }
            // cout << "nx:" << node->x << " ny:" << node->y << "    ";
        }
        curr = nextNode;
    }

    cout << curr->travelCost << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_12.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
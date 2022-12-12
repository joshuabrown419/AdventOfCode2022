#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define DAY "day_07"

class Node {
    private:
        bool isDir;
        int size;
        string name;
        Node* parent;

        vector<Node*> children = vector<Node*>(0);

    public:
        Node(string name, int size, Node* parent) {
            this->size = size;
            this->name = name;
            this->parent = parent;
            this->isDir = size == -1;
        }

        int getSize() {
            if(this->size == -1) {
                int totalSize = 0;
                for(Node *child : children){
                    totalSize += child->getSize();
                }
                this->size = totalSize;
                return totalSize;
            } else {
                return this->size;
            }
        }

        Node* getSubdirectory(string name) {
            for(Node* child : children) {
                if(child->isDir && child->name == name) return child;
            }

            Node* newDir = new Node(name, -1, this);
            this->children.push_back(newDir);
            return newDir;
        }

        void addFile(string filename, int size){
            this->children.push_back(new Node(filename, size, this));
        }

        int aocCalc() {
            if(!this->isDir) return 0;

            int selfSize = this->getSize();
            selfSize = selfSize > 100000 ? 0 : selfSize;

            for(Node *child : children) {
                selfSize += child->aocCalc();
            }

            return selfSize;
        }

        int findSmallest(int minSize) {
            vector<int> potentialSizes = vector<int>();

            if(this->isDir) {
                for(Node* child : children) {
                    child->findSmallest(minSize, potentialSizes);
                }
            }

            if(this->getSize() >= minSize) {
                potentialSizes.push_back(this->getSize());
            }

            return *min_element(potentialSizes.begin(), potentialSizes.end());
        }

        void findSmallest(int minSize, vector<int> &potentialSizes) {
            if(!this->isDir) return;
                for(Node* child : children) {
                    child->findSmallest(minSize, potentialSizes);
                }

            if(this->getSize() >= minSize) {
                potentialSizes.push_back(this->getSize());
            }

            return;
        }

        Node* getParent() {
            return this->parent;
        }
};

void part_1(vector<string>* input) {
    Node root("/", -1, nullptr);
    Node *curr = &root;
    for(string line : *input) {
        if(line.at(0) == '$') {
            string cmd = line.substr(2, 2);
            if(cmd == "cd") {
                string dirName = line.substr(5);
                if(dirName == "/") {
                    curr = &root;
                } else if (dirName == "..") {
                    curr = curr->getParent();
                } else {
                    curr = curr->getSubdirectory(dirName);
                }
            }
        } else if (isdigit(line.at(0))) {
            int size = atoi(line.substr(0, line.find(' ')).c_str());
            string fileName = line.substr(line.find(' ') + 1);
            curr->addFile(fileName, size);
        }
    }

    cout << root.aocCalc() << endl;
}

void part_2(vector<string>* input) {
    Node root("/", -1, nullptr);
    Node *curr = &root;
    for(string line : *input) {
        if(line.at(0) == '$') {
            string cmd = line.substr(2, 2);
            if(cmd == "cd") {
                string dirName = line.substr(5);
                if(dirName == "/") {
                    curr = &root;
                } else if (dirName == "..") {
                    curr = curr->getParent();
                } else {
                    curr = curr->getSubdirectory(dirName);
                }
            }
        } else if (isdigit(line.at(0))) {
            int size = atoi(line.substr(0, line.find(' ')).c_str());
            string fileName = line.substr(line.find(' ') + 1);
            curr->addFile(fileName, size);
        }
    }

    int minNeeded = 30000000 - (70000000 - root.getSize());
    cout << root.findSmallest(minNeeded) << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_07.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
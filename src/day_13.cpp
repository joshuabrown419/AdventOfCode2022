#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define DAY "day_13"

bool isOrdered(const string& left_str, const string& right_str) {
        // cout << left_str << "    " << right_str << endl;
        queue<char> left = queue<char>();
        for(int i = 0; i < left_str.length(); i++) { 
            char c = left_str.at(i);
            if(c ==',') continue;

            if(c == '1' && left_str.at(i+1) == '0') {
                c = '}';
                i++;
            }

            left.push(c);
        }

        queue<char> right = queue<char>();
        for(int i = 0; i < right_str.length(); i++) { 
            char c = right_str.at(i);
            if(c ==',') continue;

            if(c == '1' && right_str.at(i+1) == '0') {
                c = '}';
                i++;
            }

            right.push(c);
        }


        bool inOrder = true;

        while(!left.empty()) {
            if(right.empty()) {
                inOrder = false;
                break;
            }

            char l = left.front();
            left.pop();
            char r = right.front();
            right.pop();

            if(l == r) continue;

            if(l == ']') break;

            if(r == ']') {
                inOrder = false;
                break;
            }

            if(l == '[') {
                int size = right.size();
                right.push(r);
                right.push(']');
                for(int i = 0; i < size; i++){
                    right.push(right.front());
                    right.pop();
                }
                continue;
            }

            if(r == '[') {
                int size = left.size();
                left.push(l);
                left.push(']');
                for(int i = 0; i < size; i++){
                    left.push(left.front());
                    left.pop();
                }
                continue;
            }

            if(l < r) break;

            if(l > r) {
                inOrder = false;
                break;
            }

            cout << "Should not be here" << endl;

        }

        return inOrder;
}

void part_1(vector<string>* input) {
    int sum = 0;
    for(int i = 0; i < input->size(); i += 3) {
        string left_str = input->at(i);
        string right_str = input->at(i+1);

        if(isOrdered(left_str, right_str)){
            sum += (i/3 + 1);
        } 
    }

    cout << sum << endl;
}

struct compareValues {
    inline bool operator() (const string& left_str, const string& right_str) {
        return isOrdered(left_str, right_str);
    }
};

void part_2(vector<string>* input) {
    vector<string> *newInput = new vector<string>();

    for(string line : *input) { 
        if(line.length() != 0) {
            newInput->push_back(line);
        }
    }

    input = newInput;
    input->push_back("[[2]]");
    input->push_back("[[6]]");


    sort(input->begin(), input->end(), compareValues());

    // for(string line : *input) {
    //     cout << line << endl;
    // }

    auto first_it = find(input->begin(), input->end(), "[[2]]");
    int first = first_it - input->begin() + 1;

    auto second_it = find(input->begin(), input->end(), "[[6]]");
    int second = second_it - input->begin() + 1;

    cout << first * second << endl;
}

int main() {
    Utils::printHeader(DAY);
    vector<string>* input = Utils::loadFile("input/day_13.txt");

    Utils::startPart("Part One");
    part_1(input);
    Utils::stopPart();

    Utils::startPart("Part Two");
    part_2(input);
    Utils::stopPart();
}
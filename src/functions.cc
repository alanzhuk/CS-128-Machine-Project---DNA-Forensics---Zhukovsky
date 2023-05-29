#include "functions.hpp"
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::vector<std::string>> ParseSheet(std::string name) {
    std::ifstream ifs{name};
    std::vector<std::vector<std::string>> hold;
    for(std::string line; std::getline(ifs, line); line = "") {
        hold.push_back(utilities::GetSubstrs(line, ','));
    }
    name = " ";
    return hold; 
}
int LongestStr(std::string input, std::string type) {
    int long_sequence = 0;
    int temp_int = 0;
    std::string temp_str;
    for (unsigned int i = 0; i < input.size(); i++) {
        temp_str += input.substr(i, 1);
        if (temp_str == type) {
            temp_int++;
            temp_str = "";
            if (temp_int > long_sequence) {
                long_sequence = temp_int;
            }
        } else if (temp_str.size() == type.size() && temp_str != type) {
            i = i - (temp_str.size() - 1);
            temp_str = "";
            temp_int = 0;
        }
    }
    input = " ";
    type = " ";
    return long_sequence;
}
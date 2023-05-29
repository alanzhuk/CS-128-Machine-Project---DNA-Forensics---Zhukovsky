#include <iostream>

#include "functions.hpp"
#include "utilities.hpp"
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }
  int matches = 0;
  int index = 0;
  std::string idk = argv[1];
  std::vector<std::vector<std::string>> saved = ParseSheet(idk);
  //int agatg = LongestStr(argv[2], "AGATG");
  //int aatg = LongestStr(argv[2], "AATG");
  //int tat = LongestStr(argv[2], "TAT");
  idk = argv[2];
  for (unsigned int i = 1; i < saved.size(); i++) {
    bool test = true;
    for (unsigned int w = 1; w < saved[i].size(); w++) {
      if (LongestStr(idk, saved[0][w]) != std::stoi(saved[i][w])) {
        test = false;
        break;
      }
    }
    if (test) {
        matches++;
        index = i;
    }
    //bool test_ag = agatg == std::stoi(saved[i][1]);
    //bool test_aa = aatg == std::stoi(saved[i][2]);
    //bool test_ta = tat == std::stoi(saved[i][3]);
    //if (test_ag && test_aa && test_ta) {
      //cout << saved[i][0];
      //return 0;
    //}
  }
  if (matches == 1) {
    cout << saved[index][0];
  } else {
    cout << "No match";
  }
}
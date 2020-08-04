//
// Created by nicon on 8/2/2020.
//

#ifndef FINALPROJECT_HASHTABLE_H
#define FINALPROJECT_HASHTABLE_H
#include <iostream>
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <vector>
#include <sstream>
#include<array>
#include <fstream>
using namespace std;

extern array<vector<pair<string,int>>, 250000> table;

int findSarcasmCount(string input);
vector<pair<string, int>> findMaxWords(void);
void printMaxValues();
void read(string word);
long int hashFunction(string input);
void decrementCount(string word);

#endif //FINALPROJECT_HASHTABLE_H

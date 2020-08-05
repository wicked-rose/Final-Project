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

extern array<vector<pair<string,int>>, 250037> table;//data table

int findSarcasmCount(string input);//look up sarcasm rating of a word
vector<pair<string, int>> findMaxWords(void);//find top 10 words with highest sarcasm rating
void printMaxWords();//print top 10 wors with highest sarcasm rating
void addWord(string word);//add sarcastic word to table or increment rating
long int hashFunction(string input);//hash function used to map words to table
void deleteWord(string word);//decrement the sarcasm rating of non sarcastic words

#endif //FINALPROJECT_HASHTABLE_H

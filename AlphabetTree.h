//
// Created by Kyle on 7/27/2020.
//

#ifndef PROJECT3_ALPHABETTREE_H
#define PROJECT3_ALPHABETTREE_H

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include "AlphabetNode.h"

using namespace _AlphabetNode;
using namespace std;

class AlphabetTree {
private:
    AlphabetNode* topNode;

public:
    AlphabetTree();

    void addWord(string word); // Adds a word into the tree
    void delWord(string word); // Removes a count of a word in the tree
    unsigned int getCount(string word);

    void printTopTen(); // Prints the top 10 most common words
    void printWords(); // Prints all words
    void printCount(); // Prints the total number of words
};


#endif //PROJECT3_ALPHABETTREE_H

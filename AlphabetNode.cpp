//
// Created by Kyle on 7/27/2020.
//

#include <iostream>
#include <cstring>
#include "AlphabetNode.h"
using namespace _AlphabetNode;
using namespace std;

// Default constructor
AlphabetNode::AlphabetNode() : letter(0){
    count = 0;
    subletters = map<char, AlphabetNode>();
    parent = nullptr;
}

// Standard Constructor
AlphabetNode::AlphabetNode(char letter, AlphabetNode* parent) : letter(letter){
    this->parent = parent;
    count = 0;
    subletters = map<char, AlphabetNode>();
}

//Copy Constructor
AlphabetNode::AlphabetNode(AlphabetNode *pNode) : letter(pNode->getLetter()){
    this->count = pNode->count;
    this->parent = pNode->parent;
    this->subletters = pNode->subletters;
}

unsigned int AlphabetNode::getCount(){
    return count;
}

// Return the combination of the counts of each subletter
unsigned int AlphabetNode::getSublettersCount(){
    int tempCount = 0;
    // Iterate through every subletter
    for(auto iter = subletters.begin(); iter != subletters.end(); iter++){
        tempCount += iter->second.getCount();
    }
    return tempCount;
}

// Return the pointer to the subletter
AlphabetNode* AlphabetNode::getSubletter(char subletter){
    if(subletters.count(subletter) == 0)
        return nullptr;
    return &subletters[subletter];
}

// Creates subletter node if one doesn't already exist, always returns a reference to the requested AlphabetNode
AlphabetNode *AlphabetNode::addSubletter(char subletter) {
    if(subletters.count(subletter) == 0)
        subletters[subletter] = new AlphabetNode(subletter, this);
    return &subletters[subletter];
}


char AlphabetNode::getLetter() {
    return letter;
}

void AlphabetNode::incCount(){
    count++;
}

// Recursively print every word in the tree below it
void AlphabetNode::recursivePrint(char* prefix){
    if(letter == 0)
        return;

    unsigned int tempCount = getCount() - getSublettersCount();
    if(tempCount != 0)
        cout << tempCount << " occurrence(s) of the word " << prefix << letter << endl;

    if(subletters.empty())
        return;

    for(auto iter = subletters.begin(); iter != subletters.end(); iter++){
        char * temp;
        if (letter != -1){
            strcpy(temp, prefix);
            strcat(temp, &letter);
        }
        iter->second.recursivePrint(temp);
    }
}

map<char, AlphabetNode>* AlphabetNode::getSubletters() {
    return &subletters;
}

// Prepends this->letter to the outString
void AlphabetNode::selfToAncestorsString(string* outString) {
    if (letter == -1 || letter == 0)
        return;
    outString->insert(0, 1, letter);
    parent->selfToAncestorsString(outString);
}

//Returns the Root-to-Self string, aka a word in correct order
string AlphabetNode::getRootToSelfString(){
    string outString;
    selfToAncestorsString(&outString);
    return outString;
}

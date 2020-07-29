//
// Created by Kyle on 7/27/2020.
//

#include <iostream>
#include <cstring>
#include "AlphabetNode.h"
using namespace _AlphabetNode;
using namespace std;

AlphabetNode::AlphabetNode() : letter(0){
    count = 0;
    subletters = map<char, AlphabetNode>();
}

AlphabetNode::AlphabetNode(char letter) : letter(letter){
    count = 0;
    subletters = map<char, AlphabetNode>();
}

AlphabetNode::AlphabetNode(AlphabetNode *pNode) : letter(pNode->getLetter()){
    this->count = pNode->getCount();
}

int AlphabetNode::getCount(){
    return count;
}

int AlphabetNode::getSublettersCount(){
    int tempCount = 0;
    for(auto iter = subletters.begin(); iter != subletters.end(); iter++){
        tempCount += iter->second.getCount();
    }
    return tempCount;
}

AlphabetNode* AlphabetNode::getSubletter(char subletter){
    if(subletter == '\n'|| subletters.count(subletter) == 0)
        return nullptr;

    return &subletters[subletter];

}

AlphabetNode *AlphabetNode::addSubletter(char subletter) {
    if(subletters.count(subletter) == 0)
        subletters[subletter] = new AlphabetNode(subletter);
    return &subletters[subletter];
}


char AlphabetNode::getLetter() {
    return letter;
}

void AlphabetNode::incCount(){
    count++;
}

void AlphabetNode::recursivePrint(char* prefix){
    if(letter == 0)
        return;

    int tempCount = getCount() - getSublettersCount();
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
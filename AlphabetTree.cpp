//
// Created by Kyle on 7/27/2020.
//


#include "AlphabetTree.h"

AlphabetTree::AlphabetTree() {
    this->topNode = new AlphabetNode(-1);
}


void AlphabetTree::addWord(string word) {
    AlphabetNode* currentNode = topNode;
    int stringPos = 0;
    while (currentNode != nullptr && stringPos < word.length()){
        currentNode->incCount();
        currentNode = currentNode->addSubletter(word.at(stringPos));
        stringPos++;
    }
    currentNode->incCount(); // Have to increment the last letter
    cout << "Added the word " << word << endl;
}

int AlphabetTree::getCount(string word) {
    AlphabetNode* currentNode = topNode;
    int stringPos = 0;
    while (stringPos < word.length()){
        AlphabetNode* tempNext = currentNode->getSubletter(word.at(stringPos));
        if(tempNext == nullptr)
            break;
        currentNode = tempNext;
        stringPos++;
    }
    int tempCount = currentNode->getCount() - currentNode->getSublettersCount();
    cout << tempCount << " occurrences of the word " << word << endl;
    return tempCount;
}

void AlphabetTree::printWords(){
    cout << "Printing words" << endl;
    char temp [1] = "";
    topNode->recursivePrint(temp);
}

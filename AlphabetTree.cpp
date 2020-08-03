//
// Created by Kyle on 7/27/2020.
//


#include "AlphabetTree.h"

// Default Constructor
AlphabetTree::AlphabetTree() {
    this->topNode = new AlphabetNode(-1, nullptr);
}

// Adds a word into the tree
void AlphabetTree::addWord(string word) {
    AlphabetNode* currentNode = topNode;
    // Increase total word count
    currentNode->incCount();
    int stringPos = 0;

    // Get to the last node in the word
    while (currentNode != nullptr && stringPos < word.length()){
        currentNode = currentNode->addSubletter(word.at(stringPos));
        stringPos++;
    }
    // Increment the last letter
    currentNode->incCount();
}

// Removes a word
void AlphabetTree::delWord(string word) {
    AlphabetNode* currentNode = topNode;

    // Get to the last node in the word
    for (int stringPos = 0; stringPos < word.length(); stringPos++){
        AlphabetNode* tempNext = currentNode->getSubletter(word.at(stringPos));
        if(tempNext == nullptr)
            return;
        currentNode = tempNext;
    }
    // Need to decrement the last letter
    currentNode->decCount();

    // Decrement the word count as well
    topNode->decCount();
}

// Returns the number of times the word shows up in the tree
int AlphabetTree::getCount(string word) {
    AlphabetNode* currentNode = topNode;

    for (int stringPos = 0; stringPos < word.length(); stringPos++){
        AlphabetNode* tempNext = currentNode->getSubletter(word.at(stringPos));
        if(tempNext == nullptr)
            return 0;
        currentNode = tempNext;
    }

    return currentNode->getCount();
}

// Prints the top 10 most common words in the list
void AlphabetTree::printTopTen(){
    stack<AlphabetNode *> nodeStack;
    pair<int, AlphabetNode*> topTen[10];
    nodeStack.push(topNode);

    while (!nodeStack.empty()){
        AlphabetNode *currentNode = nodeStack.top();
        nodeStack.pop();

        // Check if count > topTen[9], if so, insertion sort into topTen
        unsigned int count = currentNode->getCount();
        if(count > topTen[9].first && currentNode->getLetter() != -1){
            topTen[9] = make_pair(count, currentNode);
            for(int i = 8; i >= 0; i--) {
                if (topTen[i].first < count) {
                    topTen[i + 1] = topTen[i];
                    topTen[i] = make_pair(count, currentNode);
                }
                else
                    break;
            }
        }

        // Push children of the currentNode to stack from right to left
        for(auto iter = currentNode->getSubletters()->end(); iter != currentNode->getSubletters()->begin();){
            iter--;
            nodeStack.push(iter->second);
        }
    }

    // Prints the top 10
    for(int i = 0; i < 10; i++){
        if(topTen[i].second == nullptr)
            break;
        cout << i+1 << ". \""  << topTen[i].second->getRootToSelfString() << "\" with " << topTen[i].first << " entries" << endl;
    }
}

// Recursively prints all words in the tree
void AlphabetTree::printWords(){
    stack<AlphabetNode *> nodeStack;
    nodeStack.push(topNode);

    while (!nodeStack.empty()){
        AlphabetNode *currentNode = nodeStack.top();
        nodeStack.pop();

        unsigned int tempCount = currentNode->getCount();
        if(tempCount > 0)
            cout << currentNode->getRootToSelfString() << ": " << tempCount << endl;

        // Push children of the popped node to stack from right to left
        for(auto iter = currentNode->getSubletters()->end(); iter != currentNode->getSubletters()->begin();){
            iter--;
            nodeStack.push(iter->second);
        }
    }
}

// Prints the number of times there have been words added
void AlphabetTree::printCount() {
    cout << "There are " << topNode->getCount() << " (non-unique) words in this dataset." << endl;
}

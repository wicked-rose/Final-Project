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
    int stringPos = 0;

    // Increases the count for each node in the word
    while (currentNode != nullptr && stringPos < word.length()){
        currentNode->incCount();
        currentNode = currentNode->addSubletter(word.at(stringPos));
        stringPos++;
    }
    // Need to increment the last letter
    currentNode->incCount();
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

    return currentNode->getCount() - currentNode->getSublettersCount();
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
        unsigned int count = currentNode->getCount() - currentNode->getSublettersCount();
        if(count > topTen[9].first){
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
            nodeStack.push(&iter->second);
        }
    }

    // Actually prints the top 10
    for(int i = 0; i < 10; i++){
        if(topTen[i].second == nullptr)
            break;
        cout << i+1 << ". \""  << topTen[i].second->getRootToSelfString() << "\"  \twith " << topTen[i].first << " entries" << endl;
    }
}

// Recursively prints all words in the tree
void AlphabetTree::printWords(){
    stack<AlphabetNode *> nodeStack;
    nodeStack.push(topNode);

    while (!nodeStack.empty()){
        AlphabetNode *currentNode = nodeStack.top();
        nodeStack.pop();

        unsigned int tempCount = currentNode->getCount() - currentNode->getSublettersCount();
        if(tempCount > 0)
            cout << currentNode->getRootToSelfString() << ": " << tempCount << endl;

        // Push children of the popped node to stack from right to left
        for(auto iter = currentNode->getSubletters()->end(); iter != currentNode->getSubletters()->begin();){
            iter--;
            nodeStack.push(&iter->second);
        }
    }
}

// Prints the number of times there have been words added
void AlphabetTree::printCount() {
    cout << "There are " << topNode->getCount() << " (non-unique) words in this dataset." << endl;
}

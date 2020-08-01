//
// Created by Kyle on 7/27/2020.
//


#include "AlphabetTree.h"

AlphabetTree::AlphabetTree() {
    this->topNode = new AlphabetNode(-1, nullptr);
}


void AlphabetTree::loadFile() {
//    cout << "Starting file read" << endl;

    // read in file
    fstream fin;
    fin.open("../train-balanced-sarcasm.csv", ios::in);

    string line, word, temp;

    while (!fin.eof()) {
        // read each line
        getline(fin, line, '\n');
        stringstream s(line);
        // separate by words
        while (getline(s, word, ' ')) {
            // get rid of punctuation
            int length = word.size();
            for (int i = 0; i < length; i++) {
                if (ispunct(word[i])) {
                    word.erase(i--, 1);
                    length = word.size();
                }
            }
            transform(word.begin(), word.end(), word.begin(), ::tolower); // Lower-case letters
            addWord(word);
        }
    }

//    cout << "File read finished" << endl;
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
//    cout << "Added the word " << word << endl;
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
//    int tempCount = currentNode->getCount() - currentNode->getSublettersCount();
//    cout << tempCount << " occurrences of the word " << word << endl;
//    return tempCount;
    return currentNode->getCount() - currentNode->getSublettersCount();
}

void AlphabetTree::printTopTen(){
    stack<AlphabetNode *> nodeStack;
    pair<int, AlphabetNode*> topTen[10];
    nodeStack.push(topNode);

    while (!nodeStack.empty()){
        AlphabetNode *currentNode = nodeStack.top();
        nodeStack.pop();

        // Check if count > topTen[9], if so, insert into topTen
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


        // Push children of the popped node to stack from right to left
        for(auto iter = currentNode->getSubletters()->end(); iter != currentNode->getSubletters()->begin();){
            iter--;
            nodeStack.push(&iter->second);
        }
    }

    for(int i = 0; i < 10; i++){
        if(topTen[i].second == nullptr)
            break;
        cout << i+1 << ". \""  << topTen[i].second->getSelfToRootString() << "\"  \twith " << topTen[i].first << " entries" << endl;
    }

}

void AlphabetTree::printWords(){
//    cout << "Printing words" << endl;
//    char temp [1] = "";
//    topNode->recursivePrint(temp);

    stack<AlphabetNode *> nodeStack;
    nodeStack.push(topNode);

    while (!nodeStack.empty()){
        AlphabetNode *currentNode = nodeStack.top();
        nodeStack.pop();

        cout << currentNode->getSelfToRootString() << ": " << currentNode->getCount() - currentNode->getSublettersCount() << endl;

        // Push children of the popped node to stack from right to left
        for(auto iter = currentNode->getSubletters()->end(); iter != currentNode->getSubletters()->begin();){
            iter--;
            nodeStack.push(&iter->second);
        }
    }
}

void AlphabetTree::printCount() {
    cout << "There are " << topNode->getCount() << " (non-unique) words in this dataset." << endl;
}

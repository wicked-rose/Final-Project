
#include "hashtable.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <locale>
#include <chrono>
#include "AlphabetTree.h"


#ifdef _WIN32
#include <Windows.h>
void delay(unsigned milliseconds){
    Sleep(milliseconds);
}
#else
#include <unistd.h>
    void delay(unsigned milliseconds){
        sleep(milliseconds/1000);
    }
#endif

using namespace _AlphabetNode;
using namespace std;
using namespace chrono;

void read(AlphabetTree &tree) {
    // read in file
    fstream fin;
    fin.open("../train-balanced-sarcasm.csv", ios::in);

    string line, word;

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
            // turns each letter lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            //add word to tree and hash table
            tree.addWord(word);
            addWord(word);
        }
    }
    //open non sarcastic file
    fstream fin2;
    fin2.open("../train-balanced-sarcasm-nonsarcastic.csv", ios::in);

    while (!fin2.eof()) {
        // read each line
        getline(fin2, line, '\n');
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
            // turns each letter lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            //decrement sarcasm rating of each word in non sarcastic file
            tree.delWord(word);
            deleteWord(word);
        }
    }
}


int main() {
    //print prompt
    cout << "*insert funny loading message here*" << endl;
    //create tree data structure
    AlphabetTree tree = AlphabetTree();
    //call function to read both data files
    read(tree);
    //variable to store user input
    int choice = 0;
    typedef high_resolution_clock clock;

    while (choice != 3) {
        cout << "************************************" << endl;
        cout << "Welcome to the Sarcasm Detector 2000" << endl;
        cout << "  by *insert funny group name here* " << endl;
        cout << "************************************" << endl;
        cout << "Menu:" << endl;
        cout << "1. View top 10 sarcastic words" << endl;
        cout << "2. Search for sarcasm rating of a word" << endl;
        cout << "3. Quit" << endl;
        cout << "Please make a selection: " << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Wow thanks a lot for choosing that" << endl << endl;
            delay(1000);
            cout << "Top 10 Most Sarcastic Words From 26-ary Tree: " << endl;
            //time how long it takes to compute and print top ten ratings from tree
            auto t1 = clock::now();
            tree.printTopTen();
            auto t2 = clock::now();
            double time_taken = duration_cast<milliseconds>(t2-t1).count();
            cout << "Time taken by 26-ary Tree: " << time_taken << " milliseconds" << endl << endl;

            cout << "Top 10 Most Sarcastic Words From Hash Table: " << endl;
            //time how long it takes to compute and print top ten ratings from hash table
            t1 = clock::now();
            printMaxWords();
            t2 = clock::now();
            time_taken = duration_cast<milliseconds>(t2-t1).count();
            cout << "Time taken by Hash Table: " << time_taken << " milliseconds" << endl << endl;

            delay(1000);
            cout << "How exciting." << endl;

            delay(4000);

        } else if (choice == 2) {
            string word;
            cout << "I guess that's one choice to make";
            delay(500);
            cout << ".";
            delay(500);
            cout << ".";
            delay(500);
            cout << ".";
            delay(500);
            cout << "\nEnter a word to get its sarcasm rating: " << endl;
            cin >> word;

            auto t1 = clock::now();
            unsigned int rating = tree.getCount(word); // this will be function to find word in DS 1 and return rating
            auto t2 = clock::now();
            double time_taken = duration_cast<nanoseconds>(t2-t1).count();
            cout << "The sarcasm rating of \"" << word << "\" is: " << rating << endl;
            cout << "Time taken by 26-ary Tree: " << time_taken << " nanoseconds" << endl << endl;

            t1 = clock::now();
            rating = findSarcasmCount(word); // this will be function to find word in DS 2 and return rating
            t2 = clock::now();
            time_taken = duration_cast<nanoseconds>(t2-t1).count();
            cout << "The sarcasm rating of \"" << word << "\" is: " << rating << endl;
            cout << "Time taken by Hash Table: " << time_taken << " nanoseconds" << endl << endl;

            delay(1000);
            cout << "Thrilling." << endl;

            delay(4000);
        }
    }
    delay(1000);
    cout << "Have a fantastic day /s" << endl;
    return 0;
}

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
#include <chrono>

#ifdef _WIN32
    #include <Windows.h>
    void delay(unsigned milliseconds){
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void delay(unsigned milliseconds){
        usleep(milliseconds*1000);
    }
#endif

using namespace _AlphabetNode;
using namespace std;
using namespace chrono;

// TODO: Rename DS 1/DS 2 to actual names. Remove read function from main.cpp if implemented elsewhere in .

void read() {
    // read in file
    fstream fin;
    fin.open("../train-balanced-sarcasm.csv", ios::in);

    string line, word, temp;
    vector<string> words; // temp data structure for testing

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
            // TODO: replace with inserting into data structure
            words.push_back(((word)));
        }
    }
}


int main() {
    cout << "*insert funny loading message here*" << endl;
    AlphabetTree* tree = new AlphabetTree();
    tree->loadFile();

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
            cout << "Top 10 Most Sarcastic Words From DS 1: " << endl;
            auto t1 = clock::now();
            tree->printTopTen();
            auto t2 = clock::now();
            double time_taken = duration_cast<milliseconds>(t2-t1).count();
            cout << "Time taken by DS 1: " << time_taken << " milliseconds" << endl << endl;

            cout << "Top 10 Most Sarcastic Words From DS 2: " << endl;
            t1 = clock::now();
            // this will be function to print top 10 from DS 2
            t2 = clock::now();
            time_taken = duration_cast<milliseconds>(t2-t1).count();
            cout << "Time taken by DS 2: " << time_taken << " milliseconds" << endl << endl;

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
            int rating = tree->getCount(word); // this will be function to find word in DS 1 and return rating
            auto t2 = clock::now();
            double time_taken = duration_cast<nanoseconds>(t2-t1).count();
            cout << "The sarcasm rating of \"" << word << "\" is: " << rating << endl;
            cout << "Time taken by DS 1: " << time_taken << " nanoseconds" << endl << endl;

            t1 = clock::now();
            rating = 0; // this will be function to find word in DS 2 and return rating
            t2 = clock::now();
            time_taken = duration_cast<nanoseconds>(t2-t1).count();
            cout << "The sarcasm rating of \"" << word << "\" is: " << rating << endl;
            cout << "Time taken by DS 2: " << time_taken << " nanoseconds" << endl << endl;

            delay(4000);
        }
    }
    delay(1000);
    cout << "Have a fantastic day \\s" << endl;

//    tree->printWords();
//    tree->printCount();

    return 0;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

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
    cout << "blah blah blah menu selection" << endl;
    read();
    return 0;
}


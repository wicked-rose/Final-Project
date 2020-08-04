#include "HashTable.h"

array<vector<pair<string,int>>, 250000> table;

int findSarcasmCount(string input)
{
   // hash<string> strhash;
    //size_t index = strhash(input) % table.max_size();
   size_t index = hashFunction(input) % table.size();
    for(int i = 0; i < table[index].size(); ++i)
    {
        if(table[index][i].first == input)
            return table[index][i].second;
    }
    return 0;
}

vector<pair<string, int>> findMaxWords(void)
{
    vector<pair<string,int>> maxWords;

    for(int i =0; i < 10; ++i)
    {
        maxWords.push_back(make_pair("", 0));
    }

    for(int i = 0; i < table.size(); ++i)
    {
        for(int j = 0; j < table[i].size(); ++j)
        {
            if(table[i][j].second > maxWords[9].second)
            {
                if(table[i][j].second >= maxWords[0].second)
                {
                    for(int k = 9; k > 0; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[0] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[1].second)
                {
                    for(int k = 9; k > 1; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[1] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[2].second)
                {
                    for(int k = 9; k > 2; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[2] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[3].second)
                {
                    for(int k = 9; k > 3; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[3] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[4].second)
                {
                    for(int k = 9; k > 4; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[4] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[5].second)
                {
                    for(int k = 9; k > 5; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[5] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[6].second)
                {
                    for(int k = 9; k > 6; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[6] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[7].second)
                {
                    for(int k = 9; k > 7; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[7] = table[i][j];
                }
                else if(table[i][j].second >= maxWords[8].second)
                {
                    for(int k = 9; k > 8; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[8] = table[i][j];
                }
                else
                {
                    maxWords[9] = table[i][j];
                }
            }
        }
    }
    return maxWords;
}

void printMaxValues()
{
    vector<pair<string,int>> words;
    words = findMaxWords();
    for(int i = 0; i < words.size();++i)
    {
        cout<<i + 1 << ". \""<<words[i].first <<"\" with "<<words[i].second <<" entries" <<endl;
    }
}

void read(string word) {
    size_t index;
    index = hashFunction(word) % table.size();
    bool found = false;
    for (int i = 0; i < table[index].size(); ++i) {
        if (table[index][i].first == word) {
            ++table[index][i].second;
            found = true;
        }
    }
    if (!found)
        table[index].push_back(make_pair(word, 1));
}
void decrementCount(string word)
{
    size_t index;
    index = hashFunction(word) % table.size();
    for(int i = 0; i < table[index].size(); ++i)
    {
        if(table[index][i].first == word && table[index][i].second > 0)
        {

            --table[index][i].second;
            return;
        }
    }
}




long int hashFunction(string input)
{
    int hash = 0;
    for (int i = 0; i < input.size(); i++) {
        hash = (hash << 5) - hash + input[i];
        //hash = hash * 31 + input[i];
    }
    if(hash < 1)
        hash *= -1;
    return hash;
}


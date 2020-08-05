#include "HashTable.h"
/*Hash table is an array of vectors of pairs. The pair holds a string value for the word and an int value for the
 * number of times the word appears in the file. The table is made up of vectors to handle collisions. The size of the
 *table is 250,037 because there are 122,000 unique words so to minimize collisions I made the table twice the size
 * of what is needed and a prime number*/
array<vector<pair<string,int>>, 250037> table;
/*this method takes a word as input and looks up its sarcasm rating in the table using its hash function and then
 *looks through the vector at the index to find the word. Return sarcasm rating once word is found in table */
int findSarcasmCount(string input)
{
    //find index using hash function modulus table size
   size_t index = hashFunction(input) % table.size();
   //iterate through vector to find word
    for(int i = 0; i < table[index].size(); ++i)
    {
        //if word matches return sarcasm rating value
        if(table[index][i].first == input)
            return table[index][i].second;
    }
    //if not in table return 0
    return 0;
}
/*Finds the 10 words with the highest sarcasm rating and returns words and ratings in a vector of pairs
 *the first element in the vector has the highest rating and the last element has the 10th highest rating */
vector<pair<string, int>> findMaxWords(void)
{
    //create vector to store data with highest rating
    vector<pair<string,int>> maxWords;
    //initialize vector to have 10 elements
    for(int i =0; i < 10; ++i)
    {
        maxWords.push_back(make_pair("", 0));
    }
    //iterate through all elements in table
    for(int i = 0; i < table.size(); ++i)
    {
        //iterate through each vector in table
        for(int j = 0; j < table[i].size(); ++j)
        {
            /*Check if current word's rating is larger than the last element in the maxWords vector
             * Since a lot of words are being checked I added this if statement to skip the next 9 comparisons if
             *the word's rating isn't higher than the smallest rating in the max words vector. Skipping
             * 9 comparisons for a lot of values saves computational time*/
            if(table[i][j].second > maxWords[9].second)
            {
                //if bigger or equal to the largest rating, move all ratings down a spot and add new rating to #1 spot
                if(table[i][j].second >= maxWords[0].second)
                {
                    //move everything down a spot to make room for new largest rating
                    for(int k = 9; k > 0; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    //add new largest rating to #1 spot
                    maxWords[0] = table[i][j];
                }
                    //do same thing as above but for #2 spot. Check if bigger than #2
                else if(table[i][j].second >= maxWords[1].second)
                {
                    for(int k = 9; k > 1; --k )
                    {
                        maxWords[k] = maxWords[k-1];
                    }
                    maxWords[1] = table[i][j];
                }
                    //check if bigger than #3... trend continues all the way down
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
                    //means that rating is only bigger than #10 spot so replace #10 with new rating
                else
                {
                    maxWords[9] = table[i][j];
                }
            }
        }
    }
    //return vector with highest rated words
    return maxWords;
}
//this method prints maxwords vector
void printMaxWords()
{
    //create vector to hold maxwords
    vector<pair<string,int>> words;
    //call function to find maxwords
    words = findMaxWords();
    //print maxwords
    for(int i = 0; i < words.size();++i)
    {
        cout<<i + 1 << ". \""<<words[i].first <<"\" with "<<words[i].second <<" entries" <<endl;
    }
}
//word gets passed in from file and added to table
void addWord(string word) {
    //call hash function and modulus table size to find index
    size_t index;
    index = hashFunction(word) % table.size();
    //bool to check if word already exists in table
    bool found = false;
    //iterate through vector at index to see if word already exists
    for (int i = 0; i < table[index].size(); ++i) {
        //if word already exists, increment rating and set found flag to true
        if (table[index][i].first == word) {
            ++table[index][i].second;
            found = true;
        }
    }
    //if word was not found, add it to end of vector with rating of 1
    if (!found)
        table[index].push_back(make_pair(word, 1));
}
//word gets passed in from non sarcastic file and rating gets decremented for being nonsarcastic
void deleteWord(string word)
{
    //call hash function on word and modulus table size to get index
    size_t index;
    index = hashFunction(word) % table.size();
    //iterate through vector at index to find word
    for(int i = 0; i < table[index].size(); ++i)
    {
        //if word is found and rating isnt already zero, decrement rating.
        if(table[index][i].first == word && table[index][i].second > 0)
        {

            --table[index][i].second;
            //once word is found break out of function
            return;
        }
    }
}



/*Takes a string of input and returns a random long int to be used to map string of arbitrary size to fixed size values
 *the same string will always hash to the same value. This value will be modulus by table size to get index*/
long int hashFunction(string input)
{
    //create return value and initialize to zero
    int hash = 0;
    //hash is calculated based on each character in string
    for (int i = 0; i < input.size(); i++) {
        //multiply old hash value by 31, subtract old hash value and add ascii char code
        //this function should create different random ints depending on the string
        hash = (hash << 5) - hash + input[i];
    }
    //for large strings the hash value will overflow and become negative. Check if number is negative and make it positive
    if(hash < 1)
        hash *= -1;
    //return hash
    return hash;
}


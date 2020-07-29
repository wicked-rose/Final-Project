//
// Created by Kyle on 7/27/2020.
//

#ifndef PROJECT3_ALPHABETNODE_H
#define PROJECT3_ALPHABETNODE_H
#include <map>

namespace _AlphabetNode {
    class AlphabetNode {
    private:
        int count;
        char letter;
        std::map<char, AlphabetNode> subletters;

    public:
        AlphabetNode();
        AlphabetNode(char);
        AlphabetNode(AlphabetNode *pNode);

        char getLetter();

        AlphabetNode* getSubletter(char);
        AlphabetNode* addSubletter(char);
        int getSublettersCount();

        int getCount();
        void incCount();

        void recursivePrint(char *prefix);
    };
}


#endif //PROJECT3_ALPHABETNODE_H

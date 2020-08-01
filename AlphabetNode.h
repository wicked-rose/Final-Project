//
// Created by Kyle on 7/27/2020.
//

#ifndef PROJECT3_ALPHABETNODE_H
#define PROJECT3_ALPHABETNODE_H
#include <map>

namespace _AlphabetNode {
    class AlphabetNode {
    private:
        unsigned int count;
        char letter;
        AlphabetNode* parent;
        std::map<char, AlphabetNode> subletters;

    public:
        AlphabetNode();
        AlphabetNode(char, AlphabetNode*);
        AlphabetNode(AlphabetNode *pNode);

        char getLetter();

        AlphabetNode* getSubletter(char);
        AlphabetNode* addSubletter(char);
        unsigned int getSublettersCount();
        std::map<char, AlphabetNode>* getSubletters();

        unsigned int getCount();
        void incCount();

        void recursivePrint(char *prefix);

        void prefixPrint(std::string);

        void selfToRootString(std::string *);

        std::string getSelfToRootString();
    };
}


#endif //PROJECT3_ALPHABETNODE_H

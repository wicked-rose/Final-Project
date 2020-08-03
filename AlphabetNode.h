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
        std::map<char, AlphabetNode*> subletters;
        void selfToAncestorsString(std::string *);

    public:
        AlphabetNode();
        AlphabetNode(char, AlphabetNode*);
        AlphabetNode(AlphabetNode *pNode);
        ~AlphabetNode();

        char getLetter();

        unsigned int getCount();
        void incCount();
        void decCount();

        AlphabetNode* getSubletter(char);
        AlphabetNode* addSubletter(char);
        void delSubletter(char);
        std::map<char, AlphabetNode*>* getSubletters();

        void recursivePrint(char *prefix);

        std::string getRootToSelfString();
    };
}


#endif //PROJECT3_ALPHABETNODE_H

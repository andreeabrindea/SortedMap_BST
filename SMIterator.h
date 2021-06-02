#pragma once
#include "SortedMap.h"
#include <stack>

//DO NOT CHANGE THIS PART
class SMIterator{
    friend class SortedMap;
private:
    const SortedMap& map;
    SMIterator(const SortedMap& mapionar);
    //TODO - Representation

    BSTNode *currentNode;
    std::stack<BSTNode*> stack;
    BinaryTree bt;


public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};

#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m), stack{std::stack<BSTNode*>{} }{
    currentNode = new BSTNode();
    bt = m.tree;
    currentNode = bt.root;
    m.tree_to_stack(bt.root, stack);
    //TODO - Implementation
}

void SMIterator::first() {
    //TODO - Implementation
    if(!stack.empty())
        currentNode = stack.top();
    else
        currentNode = nullptr;
}

void SMIterator::next(){
    //TODO - Implementation
    if(!valid())
        throw exception();

    stack.pop();

    if(!stack.empty())
        currentNode = stack.top();
    else
        currentNode = nullptr;
}

bool SMIterator::valid() const{
    //TODO - Implementation
    if(currentNode == nullptr)
        return false;
    else
        return true;
}

TElem SMIterator::getCurrent() const{
    //TODO - Implementation
    if(currentNode == nullptr)
        return NULL_TPAIR;

    return currentNode->info;
}


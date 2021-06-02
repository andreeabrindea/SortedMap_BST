#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m), stack{std::stack<BSTNode*>{} }{
    first();
    //TODO - Implementation

}

void SMIterator::first() {
    //TODO - Implementation
    currentNode = bt.root;
    while(currentNode!= nullptr) {
        stack.push(currentNode);
        //currentNode = tree.currentNode.left;
    }
    if(!stack.empty())
        currentNode = stack.top();
    else
        currentNode = nullptr;
}

void SMIterator::next(){
    //TODO - Implementation
    if(!valid())
        throw exception();

    BSTNode* node = stack.top();
    stack.pop();

    if(node->right!= nullptr)
        node = node->right;

    while(node!= nullptr){
        stack.push(node);
        node = node->left;
    }

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
    return currentNode->info;
}


#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) : r(r){
    //TODO - Implementation
    this->sizeOfBST = 0;
    this->tree.root = nullptr;
}

TValue SortedMap::add(TKey k, TValue v) {
    //TODO - Implementation
    BSTNode *searched = search_rec(this->tree.root, k);
    int result = (searched == nullptr) ? NULL_TVALUE : searched->info.second;

    if(searched != nullptr){
        searched->info.second = v;
        return result;
    }

    this->tree.root = this->insert_rec(this->tree.root, std::make_pair(k,v));
    sizeOfBST++;

    return result;
}

TValue SortedMap::search(TKey k) const {
    //TODO - Implementation
    BSTNode *searched = search_rec(this->tree.root, k);
    return (searched == nullptr) ? NULL_TVALUE : searched->info.second;
}

TValue SortedMap::remove(TKey k) {
    //TODO - Implementation

    BSTNode *current = search_rec(tree.root, k);
    if(current != nullptr) {
        TValue result = current->info.second;
        if (current->left == nullptr && current->right == nullptr){
            current = nullptr;
        }// if the node we want to remove is a leaf
        else if (current->left == nullptr && current->right != nullptr){
            *current = *(current->right);
        }
        else if (current->left != nullptr && current->right == nullptr){
            *current = *(current->left);
        }//if the node we want to remove has one child
        else{
            BSTNode *minimum = findMinimum(current->right);
            current->info = minimum->info;
            remove(minimum->info.first);
            minimum = nullptr;
        }

        this->sizeOfBST--;
        return result;
    }
    return NULL_TVALUE;
}

void SortedMap::tree_to_stack(BSTNode *root, std::stack<BSTNode*> &stack) const {
    if(root == nullptr){
        return;
    }

    tree_to_stack(root->left, stack);
    stack.push(root);
    tree_to_stack(root->right, stack);
}

int SortedMap::size() const {
    //TODO - Implementation
    return this->sizeOfBST;
}

bool SortedMap::isEmpty() const {
    //TODO - Implementation
    return this->sizeOfBST == 0;
}

SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

SortedMap::~SortedMap() {
    //TODO - Implementation
    doomTheTree(tree.root);
}

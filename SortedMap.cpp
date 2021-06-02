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

    if(this->insert_rec(this->tree.root, std::make_pair(k,v)) == nullptr)
        return -1;
    sizeOfBST++;
    return (searched == nullptr) ? NULL_TVALUE : searched->info.second;
}

TValue SortedMap::search(TKey k) const {
    //TODO - Implementation
    BSTNode *searched = search_rec(this->tree.root, k);
    return (searched == nullptr) ? NULL_TVALUE : searched->info.second;
}

TValue SortedMap::remove(TKey k) {
    //TODO - Implementation

    BSTNode *current = search_rec(tree.root,k);
    if(current != nullptr) {
        if (current->left == nullptr && current->right == nullptr){
            current = nullptr;
        }// if the node we want to remove is a leaf

        else if (current->left == nullptr && current->right != nullptr){
            current = current->right;
        }
        else if (current->left != nullptr && current->right == nullptr){
            current = current->left;
        }//if the node we want to remove has one child
        else{
            BSTNode *minimum =  findMinimum(current->right);
            current->info = minimum->info;
            delete minimum;
        }
    }
    return NULL_TVALUE;
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
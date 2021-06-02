#pragma once
//DO NOT INCLUDE SORTEDMAPITERATOR

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);
class SMIterator;
typedef bool(*Relation)(TKey, TKey);

typedef  struct BSTNode {
    TElem info;
    BSTNode *left;
    BSTNode *right;
};

typedef struct BinaryTree{
    BSTNode* root;
};

class SortedMap {
    friend class SMIterator;
private:
    //TODO - Representation
    BinaryTree tree;
    int sizeOfBST;
    Relation r;

    // a function that creates a new node given the information to be stored in it.
    BSTNode* initNode(TElem e)
    {
        BSTNode* newThing = new BSTNode();
        newThing->info = e;
        newThing->left = newThing->right = nullptr;
        return newThing;
    }

    //insert operation - recursive implementation
    BSTNode *insert_rec(BSTNode* &node, TElem e){
        if(node == nullptr)
            node = initNode(e);
        else if (node->info >= e)
            node->left = insert_rec(node->left, e);
        else if (node->info < e)
            node->right = insert_rec(node->right, e);

        return node;
    }//Complexity: O(n)

    BSTNode *search_rec(BSTNode* node, TKey e) const
    {
        if(node == nullptr || node->info.first == e) {
            return node;
        }
        else if (node->info.first < e)
            return search_rec(node->right, e);
        else
            return search_rec(node->left,e);
    }//Complexity: O(n)

    BSTNode* findMinimum(BSTNode* currentNode)
    {
        if(currentNode == nullptr)
            return currentNode;
        else
            while(currentNode->left!= nullptr)
                currentNode = currentNode->left;
//            TElem minimum;
//            minimum = currentNode->info;

            return currentNode;
    }

    void doomTheTree(BSTNode* root){
        if(root == nullptr)
            return;
        doomTheTree(root->right);
        doomTheTree(root->left);
        delete root;
    }

public:

    // implicit constructor
    SortedMap(Relation r);

    // adds a pair (key,value) to the map
    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
    //if the key SMes not exist, a new pair is added and the value null is returned
    TValue add(TKey c, TValue v);

    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
    TValue search(TKey c) const;


    //removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
    TValue remove(TKey c);

    //returns the number of pairs (key,value) from the map
    int size() const;

    //checks whether the map is empty or not
    bool isEmpty() const;

    // return the iterator for the map
    // the iterator will return the keys following the order given by the relation
    SMIterator iterator() const;

    // destructor
    ~SortedMap();
};
//
//  AVLTree.hpp
//  BST
//
//  Created by Le Nguyen VIet Long on 3/25/18.
//  Copyright © 2018 Le Nguyen Viet Long. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <stdio.h>
#include <stack>
// right is bigger, left is smaller
struct BSTNode{
    // default
    BSTNode(int val, int size, int length, BSTNode* parent,BSTNode* leftC,BSTNode* rightC ):
    val(val),
    size(size),
    length(length),
    parent(parent),
    leftC(leftC),
    rightC(rightC){};
    
    BSTNode(int value):val(value),
    parent(nullptr),
    leftC(new BSTNode{-69,0,-1,this, nullptr,nullptr}),
    rightC(new BSTNode{-69,0,-1,this, nullptr,nullptr}),
    size(1){};
    int val;
    int size; // size of subtree with this as its topNode
    int length; // the # of paths/vertices from this node to the furthest leaf.
    BSTNode* parent;
    BSTNode* leftC;
    BSTNode* rightC;
};

class BST{
public:
    BSTNode* topNode;
    
    // create the fictious node
    BST(): topNode(new BSTNode(-69,0,-1,nullptr, nullptr,nullptr)){};
    BST(BSTNode* top): topNode(top){};
    
    void insert(BSTNode* newN);
    void counterclock(BSTNode* grandpa);
    void clockwise(BSTNode* grandpa);
    int checkAVL(BSTNode* check);
    BSTNode* search(int searchVal);
    int inOrderTranversal(BSTNode* top);
    BSTNode* min(BSTNode* nodeSub);
    BSTNode* successor(int val);
    BSTNode* predecessor(int val);
    void fixAVL(BSTNode* myNode);
    void printTreeStack();
    
    void deleteN(int searchVal);
};

#endif /* AVLTree_hpp */

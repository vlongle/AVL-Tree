//
//  AVLTree.cpp
//  BST
//
//  Created by Le Nguyen VIet Long on 3/25/18.
//  Copyright © 2018 Le Nguyen Viet Long. All rights reserved.
//

#include "AVLTree.hpp"
#include <iostream>



    // these codes for insert are genuinely SUCKY
    void BST::insert(BSTNode* newN){
        BSTNode* current = topNode;
        
        
        std:: cout << "insert(): newN: " << newN -> val << std::endl;
        
        
        
        
        
        
        while (true){
            current -> size +=1;
            if (newN -> val > current -> val){
                if (current-> rightC->length != -1){ // instead of nullptr, we use some fictious node
                    current->length = std::max(current->leftC->length, current->rightC->length+1)+1;
                    
                    
                    
                    
                    current = current-> rightC;
                    
                }
                else{
                    current->length = std::max(current->leftC->length, current->rightC->length+1)+1;
                    current -> rightC = newN;
                    break;
                }
            }
            
            else{
                if (current -> leftC->length != -1){
                    current->length = std::max(current->leftC->length+1, current->rightC->length)+1;
                    
                    
                    std::cout << "break point " << std::endl;
                    
                    current = current -> leftC;
                    
                    
                    
                }
                else{
                    current->length = std::max(current->leftC->length+1, current->rightC->length)+1;
                    current -> leftC = newN;
                    break;
                }
                
            }
            
        }
        
        newN -> parent = current;
        
        
        
        
        
        
        
        
        
        
        
        // THIS PART OF CODE IS WRONG BECAUSE HAVEN'T CHECKED THE ZIG-ZAG CASE
//        // check AVL part. The fixAVL take O(1), but bubling up may take O(logn)
        while (newN != nullptr){ // eventually newN must reach the topNode whose parent = nullptr
            fixAVL(newN);
            std:: cout << "reassign parent " << std:: endl;
            newN = newN -> parent;
            std::cout << "newN: " << newN << " | ";
            
            if (newN != nullptr){
                std:: cout << newN-> val << std::endl;
            }
        }
        
    }
    
    
    /*   we fix an imbalance at the most local level (involving only 3 nodes)
     4                                                              6
     6             left rotate (rotate 4 down) ---->         4       8
     8
     
     */



// COUNTERCLOCK BUGGY??
    void BST::counterclock(BSTNode* grandpa){
        BSTNode* middle = grandpa-> rightC;
        // Have to change great grandpa as well
        // insert code HERE
        grandpa -> length = std::max(grandpa->leftC->length, middle->leftC->length)+1;
        middle->length =std::max(grandpa->length, middle->rightC->length)+1
        ;
        
        
        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->rightC->size-1;
        

        if (grandpa->parent== nullptr){ // grandpa == topNode
            middle->parent = nullptr;
            topNode = middle;
        }
        else{
            if (grandpa->parent->leftC == grandpa){
                grandpa->parent->leftC = middle;
            }
            else{
                grandpa->parent->rightC=middle;
            }
        }
        
        middle-> parent = grandpa-> parent;
        grandpa->parent = middle;
        grandpa->rightC = middle-> leftC;
        middle->leftC = grandpa;

    }
    
    /*
     8                               6
     6               ----->          4       8
     4
     */
    void BST::clockwise(BSTNode* grandpa){
        BSTNode* middle = grandpa-> leftC;
        
        std:: cout << "middle is " << middle << std:: endl;
        
        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->leftC->size-1;
        grandpa -> length = std::max(grandpa->rightC->length, middle->rightC->length)+1;
        middle->length =std::max(grandpa->length, middle->leftC->length)+1;
        
        
        
        if (grandpa->parent== nullptr){ // grandpa == topNode
            middle->parent = nullptr;
            topNode = middle;
        }
        else{
        if (grandpa->parent->leftC == grandpa){
            grandpa->parent->leftC = middle;
        }
        else{
            grandpa->parent->rightC=middle;
        }
        }
        
        
        middle-> parent = grandpa-> parent;
        grandpa->parent = middle;
        grandpa->leftC = middle-> rightC;
        middle->rightC = grandpa;
        
 
        
        
    }


// Counterclockwise & clockwise length has problem

    // 0 if satisfy AVL, -1 if left-heavy, 1 if right heavy
    int BST::checkAVL(BSTNode* check){
        if (check == nullptr || check-> leftC->length == -1 &&  check-> rightC->length == -1){
            return 69;
        }
        std:: cout << "From checkAVL, check->rightC->length: " << check->rightC->length;
        std::cout<< " check->leftC->length: " << check->leftC->length << std:: endl;
        int diff = check->rightC->length - check->leftC->length;
        if (diff > 1){
            std:: cout << "right heavy " << std:: endl;
            return 1;
        }
        else if (diff <-1){
            std:: cout << "left heavy " << std::endl;
            return -1;
        }
        else{
            std:: cout << "difference = 0, already balanced " << std::endl;
            return 0;
        }
    }




void BST::fixAVL(BSTNode* myNode){
    std:: cout << "Calling fixAVL on " << myNode -> val << std:: endl;
    int direction = checkAVL(myNode);
    std:: cout << "direction: " << direction << std:: endl;
    
    if (direction ==-1){
        std::cout << "dirc == -1 " << std::endl;
        if (myNode->leftC->rightC->length >= myNode->leftC->leftC->length){
            counterclock(myNode->leftC);
            clockwise(myNode);
        }
        else{
            clockwise(myNode);
        }
    }
        else if (direction == 1){
            std::cout << "dirc == 1 " << std::endl;

            if (myNode->rightC->leftC->length >= myNode->rightC->rightC->length){
                clockwise(myNode->rightC);
                counterclock(myNode);
            }
            else{
                counterclock(myNode);
            }
        }
        
        
    }


    
    
    
    
    
    BSTNode* BST::search(int searchVal){
        BSTNode* current = topNode;
        while (current->size != -1){
            if (searchVal > current->val){
                current = current->rightC;
            }
            else if ( searchVal< current -> val){
                current = current -> leftC;
            }
            else{ // equal scenario !!!
                return current;
            }
        }
        std::cout << "Can't find the searched value " << std::endl;
        return nullptr;
    }
    
    // print out the tree in increasing order (as array)
    int BST::inOrderTranversal(BSTNode* top){
        if (top->length == -1){
            return 0;
        }
        inOrderTranversal(top->leftC);
        std::cout << top-> val << std::endl;
        inOrderTranversal(top->rightC);
        return 0;
    }

    // find the min member in the subtree with nodeSub as its root
    BSTNode* BST::min(BSTNode* nodeSub){
        BSTNode* target = nodeSub;
        while (target -> leftC->length != -1){
            target = target -> leftC;
        }
        return target; // if the nodeSub has no leftC, just return nodeSub itself
    }
    
BSTNode* BST::successor(int val){ // next larger node
    BSTNode* myNode  = search(val);
    if (myNode->rightC->length != -1) {
        return min(myNode->rightC);
    }
    else{
        return myNode-> parent;
    }
}

BSTNode* BST::predecessor(int val){ // next larger node
    BSTNode* myNode  = search(val);
    if (myNode->leftC->length != -1) {
        return min(myNode->rightC);
    }
    else{
        return myNode-> parent;
    }
}
    
    // UR CODE SUCKS PLEASE FIND SOME C++ BOOK TO MAKE IT MORE OPTIMAL
    
void BST::deleteN(int searchVal){
            BSTNode* delN = search(searchVal);
    if (delN->rightC->length == -1 && delN->leftC->length==-1 ){ // leaf
        if (delN == delN->parent->leftC){
            delN->parent->leftC = delN->leftC; // the fictious leaf
        }
        else{
            delN->parent->rightC = delN->leftC;
        }
        delete delN;
    } // leaf
    
    else if (delN->rightC->length == -1){ // meaning leftC still active
        if (delN == delN->parent->leftC){
            delN->parent->leftC = delN->leftC; // the fictious leaf
        }
        else{
            delN->parent->rightC = delN->leftC;
        }
        delete delN;
    }
    else if (delN->leftC->length == -1){
        if (delN == delN->parent->leftC){
            delN->parent->leftC = delN->rightC; // the fictious leaf
        }
        else{
            delN->parent->rightC = delN->rightC;
        }
        delete delN;
    }
    else{ // have both left & right child
    BSTNode* succ = successor(searchVal);
    succ-> rightC->parent = succ->parent;
        if (succ->parent->rightC == succ){
            succ->parent->rightC = succ ->rightC;
        }
        else{
    succ -> parent-> leftC = succ->rightC;
        }
    // remove succ in place
        
    succ -> parent = delN -> parent;
    succ -> rightC = delN->rightC;
    succ->leftC = delN->leftC;
        
        delN->rightC->parent = succ;
        delN->leftC->parent = succ;

        
        if (delN->parent->leftC == delN){
            delN->parent->leftC = succ;
        }
        else{
            delN->parent->rightC = succ;
        }
        
    
    delete delN;
        }

//            if (delN != nullptr){
//                delN -> parent;
//            }
        }



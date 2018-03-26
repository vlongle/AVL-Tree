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
//        while (newN != nullptr){ // eventually newN must reach the topNode whose parent = nullptr
//            fixAVL(newN);
//            std:: cout << "reassign parent " << std:: endl;
//            newN = newN -> parent;
//            std::cout << "newN: " << newN << " | " << std::endl;
//        }
        
    }
    
    
    /*   we fix an imbalance at the most local level (involving only 3 nodes)
     4                                                              6
     6             left rotate (rotate 4 down) ---->         4       8
     8
     
     */
    
    void BST::leftRotate(BSTNode* grandpa){
        BSTNode* middle = grandpa-> rightC;
        // Have to change great grandpa as well
        // insert code HERE

        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->rightC->size-1;
        
        
        middle-> parent = grandpa-> parent;
        grandpa->parent = middle;
        grandpa->rightC = middle-> leftC;
        middle->leftC = grandpa;
        if (grandpa == topNode){
            topNode = middle;
        }
    }
    
    /*
     8                               6
     6               ----->          4       8
     4
     */
    void BST::rightRotate(BSTNode* grandpa){
        BSTNode* middle = grandpa-> leftC;
        std:: cout << "middle is " << middle << std:: endl;
        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->leftC->size-1;
        
        
        
        middle-> parent = grandpa-> parent;
        grandpa->parent = middle;
        grandpa->leftC = middle-> rightC;
        middle->rightC = grandpa;
        if (grandpa == topNode){
            topNode = middle;
        }
    }




    // 0 if satisfy AVL, -1 if left-heavy, 1 if right heavy
    int BST::checkAVL(BSTNode* check){
        if (check == nullptr){
            return 69;
        }
        int diff = check->leftC->length - check->rightC->length;
        return diff;
    }




void BST::fixAVL(BSTNode* myNode){
    int direction = checkAVL(myNode);
    std:: cout << "direction: " << direction << std:: endl;
    
    switch (direction) {
        case 69:
            std:: cout << "Bullshit response " << std::endl;
            break;
        case 0:
            std:: cout << "Already balanced " << std::endl;
            break;
            
        case 1:
            std:: cout << "Right heavy " << std::endl;
            
            
            leftRotate(myNode);
            break;
            
        case -1:
            std:: cout << "Left heavy " << std::endl;
            rightRotate(myNode);
            break;
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


    
    // UR CODE SUCKS PLEASE FIND SOME C++ BOOK TO MAKE IT MORE OPTIMAL
    
    //    void deleteN(int searchVal){
    //        BSTNode* delN = search(searchVal);
    //        if (delN != nullptr){
    //            delN -> parent
    //        }
    //    }


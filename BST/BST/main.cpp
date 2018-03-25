#include <iostream>
using namespace std;

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
    
    // these codes for insert are genuinely SUCKY
    void insert(BSTNode* newN){
         BSTNode* current = topNode;

        while (true){
            current -> size +=1;
            if (newN -> val > current -> val){
                if (current-> rightC->length != -1){ // instead of nullptr, we use some fictious node
                    current->length = max(current->leftC->length, current->rightC->length+1)+1;
                    
                    
                    
                    
                    current = current-> rightC;
                    
                }
                else{
                    current->length = max(current->leftC->length, current->rightC->length+1)+1;
                    current -> rightC = newN;
                    break;
                }
            }
            
            else{
                if (current -> leftC->length != -1){
                    current->length = max(current->leftC->length+1, current->rightC->length)+1;
                    
                    
                    cout << "break point " << endl;
                    
                    current = current -> leftC;
                    
                    
                    
                }
                else{
                    current->length = max(current->leftC->length+1, current->rightC->length)+1;
                    current -> leftC = newN;
                    break;
                }

            }
            
        }
            
            newN -> parent = current;

    }
    
    
/*   we fix an imbalance at the most local level (involving only 3 nodes)
 4                                                              6
    6             left rotate (rotate 4 down) ---->         4       8
        8
 
 */

    void leftRotate(BSTNode* grandpa){
        BSTNode* middle = grandpa-> rightC;
        // Have to change great grandpa as well
        // insert code HERE
        if (grandpa == topNode){
            topNode = middle;
        }
        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->rightC->size-1;
        
        
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
    void rightRotate(BSTNode* grandpa){
        BSTNode* middle = grandpa-> leftC;
        if (grandpa == topNode){
            topNode = middle;
        }
        middle -> size = grandpa-> size;
        grandpa-> size = middle-> size - middle->leftC->size-1;
        
        
        
        middle-> parent = grandpa-> parent;
        grandpa->parent = middle;
        grandpa->leftC = middle-> rightC;
        middle->rightC = grandpa;
    }

    // true if satisfy AVL, 0 otherwise
    bool checkAVL(BSTNode* check){
        int diff = abs(check->leftC->length - check->rightC->length);
        if (diff >1){
            return false;
        }
        else{
            return true;
        }
    }
    
    
    
    
    
    BSTNode* search(int searchVal){
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
    cout << "Can't find the searched value " << endl;
    return nullptr;
    }
    
    // print out the tree in increasing order (as array)
    int inOrderTranversal(BSTNode* top){
        if (top->length == -1){
            return 0;
        }
        inOrderTranversal(top->leftC);
        cout << top-> val << endl;
        inOrderTranversal(top->rightC);
        return 0;
    }
    
    // find the min member in the subtree with nodeSub as its root
    BSTNode* min(BSTNode* nodeSub){
        BSTNode* target = nodeSub;
            while (target -> leftC->length != -1){
                target = target -> leftC;
            }
        return target; // if the nodeSub has no leftC, just return nodeSub itself
    }
    
    BSTNode* successor(int val){ // next larger node
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
};
int main(){
//    BSTNode *n1 = new BSTNode(49);
//    BSTNode *n2 = new BSTNode(46);
//    BSTNode *n3 = new BSTNode(79);
//    BSTNode *n4 = new BSTNode(64);
//    BSTNode *n5 = new BSTNode(83);
//    BSTNode *n6 = new BSTNode(43);
//
//
//
//    BST tree(n1);
//    tree.insert(n2);
//    tree.insert(n3);
//    tree.insert(n4);
//    tree.insert(n5);
//    tree.insert(n6);
//    cout << tree.search(46) << endl;
//     tree.inOrderTranversal(tree.topNode);
//    cout << "Test " << endl;
//    cout << tree.successor(46) << endl;
//    cout << "Yeah" << endl;
//
    
    BSTNode *n1 = new BSTNode(8);
    BSTNode *n2 = new BSTNode(6);
    BSTNode *n3 = new BSTNode(4);
    BST tree(n1);
    tree.insert(n2);
    tree.insert(n3);

    cout << "first round " << endl;
    cout << "for 8: " << boolalpha << tree.checkAVL(n1) << endl;

    
    tree.rightRotate(n1);
    cout << "for 6: " << boolalpha << tree.checkAVL(n2) << endl;

    
//    cout << "checking for balanced tree " << endl;
//    cout << "for 49: " << boolalpha << tree.checkAVL(n1) << endl;
    
    
    cout << "second round " << endl;
}

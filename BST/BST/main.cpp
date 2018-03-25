#include <iostream>
using namespace std;

// right is bigger, left is smaller
struct BSTNode{
    BSTNode(int value):val(value), parent(nullptr), leftC(nullptr), rightC(nullptr), size(1){};
    int val;
    int size; // size of subtree with this as its topNode
    BSTNode* parent;
    BSTNode* leftC;
    BSTNode* rightC;
};
class BST{
public:
    BSTNode* topNode;
    BST(BSTNode* top): topNode(top){};
    
    // these codes for insert are genuinely SUCKY
    void insert(BSTNode* newN){
         BSTNode* current = topNode;

        while (true){
            current -> size +=1;
            if (newN -> val > current -> val){
                if (current-> rightC != nullptr){
                    current = current-> rightC;
                }
                else{
                    current -> rightC = newN;
                    break;
                }
            }
            else{
                if (current -> leftC != nullptr){
                    current = current -> leftC;
                }
                else{
                    current -> leftC = newN;
                    break;
                }

            }
            newN -> parent = current;
        }
//        BSTNode* current = topNode;
//        BSTNode* moveNext;
//        do{
//            if (newN -> val > current -> val){
//                current-> size +=1;
//                moveNext = current -> rightC;
//            }
//            else{
//                current-> size +=1;
//                moveNext = current -> leftC;
//
//            }
//            if (moveNext != nullptr){
//                current = moveNext;
//            }
//        }while(moveNext != nullptr);
//        newN -> parent = current;
//        if (newN -> val > current -> val){
//            current -> rightC = newN;
//
//        }
//        else{
//            current -> leftC = newN;
//
//        }
    }
    


    BSTNode* search(int searchVal){
        BSTNode* current = topNode;
        while (current != nullptr){
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
        if (top == nullptr){
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
            while (target -> leftC != nullptr){
                target = target -> leftC;
            }
        return target; // if the nodeSub has no leftC, just return nodeSub itself
    }
    
    BSTNode* successor(int val){ // next larger node
        BSTNode* myNode  = search(val);
        if (myNode->rightC != nullptr) {
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
    BSTNode *n1 = new BSTNode(49);
    BSTNode *n2 = new BSTNode(46);
    BSTNode *n3 = new BSTNode(79);
    BSTNode *n4 = new BSTNode(64);
    BSTNode *n5 = new BSTNode(83);
    BSTNode *n6 = new BSTNode(43);



    BST tree(n1);
    tree.insert(n2);
    tree.insert(n3);
    tree.insert(n4);
    tree.insert(n5);
    tree.insert(n6);
    cout << tree.search(46) << endl;
     tree.inOrderTranversal(tree.topNode);
    cout << "Test " << endl;
    cout << tree.successor(46) << endl;
    cout << "Yeah" << endl;
}

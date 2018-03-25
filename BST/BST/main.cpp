#include <iostream>
#include "AVLTree.hpp"
using namespace std;


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
    cout << "for 8: "  << tree.checkAVL(n1) << endl;
    
    
    tree.fixAVL(n1);

    
//    tree.rightRotate(n1);
    cout << "for 6: " << boolalpha << tree.checkAVL(n2) << endl;

    
//    cout << "checking for balanced tree " << endl;
//    cout << "for 49: " << boolalpha << tree.checkAVL(n1) << endl;
    
    
    cout << "second round " << endl;
}

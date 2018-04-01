#include <iostream>
#include "AVLTree.hpp"
using namespace std;


int main(){
    BSTNode *n1 = new BSTNode(100);
    BSTNode *n2 = new BSTNode(69);
    BSTNode *n3 = new BSTNode(60);
    BSTNode *n4 = new BSTNode(65);
    BSTNode *n5 = new BSTNode(101);
    BSTNode *n6 = new BSTNode(105);
    BSTNode *n7 = new BSTNode(103);
    BSTNode *n8 = new BSTNode(106);



    BST tree(n1);
    tree.insert(n2);
    tree.insert(n3);
    tree.insert(n4);
    tree.insert(n5);
    tree.insert(n6);
    tree.insert(n7);
    tree.insert(n8);

    cout << "--------END OF INSERTION " << endl;
    
    
    // SEARCH HAS BUGG
//    cout << tree.search(46) << endl;
    
    
    
     tree.inOrderTranversal(tree.topNode);
    
    cout << "Test " << endl;
    
    tree.printTreeStack();
    cout << "-----END------ " << endl;
    
//    // SUCCESSOR ALSO DEPEND ON SEARCH
////    cout << tree.successor(46) << endl;
//
//
//    cout << "Yeah" << endl;
//
//    tree.deleteN(65);
//    cout << "-------DELETE TREE " << endl;
//    tree.inOrderTranversal(tree.topNode);
//    cout << "Yeah" << endl;
//
//    tree.deleteN(106);
//    cout << "-------DELETE TREE " << endl;
//    tree.inOrderTranversal(tree.topNode);
//    cout << "Yeah" << endl;

    
    
//    BSTNode *n1 = new BSTNode(8);
//    BSTNode *n2 = new BSTNode(6);
//    BSTNode *n3 = new BSTNode(4);
//    BST tree(n1);
//    tree.insert(n2);
//    tree.insert(n3);
//
//    cout << "first round " << endl;
//    cout << "for 8: "  << tree.checkAVL(n1) << endl;
//
//
//    tree.fixAVL(n1);
//
//
////    tree.rightRotate(n1);
//    cout << "for 6: " << boolalpha << tree.checkAVL(n2) << endl;
//
//
////    cout << "checking for balanced tree " << endl;
////    cout << "for 49: " << boolalpha << tree.checkAVL(n1) << endl;
//
//
//    cout << "second round " << endl;
}

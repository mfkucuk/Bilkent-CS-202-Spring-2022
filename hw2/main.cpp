#include <iostream>
using namespace std;

#include "BinarySearchTree.h"

int main() {
    BinarySearchTree tree;
    tree.add(50);
    tree.add(80);
    tree.add(10);
    tree.add(20);
    tree.add(65);
    tree.add(75);
    tree.add(45);
    tree.add(90);
    tree.add(70);
    tree.add(60);
    tree.add(30);
    tree.add(40);
    tree.add(63);

    tree.add(76);
    cout << tree.getHeight() << endl;
    cout << tree.getNumberOfNodes() << endl;
    cout << tree.contains(90) << endl;
    cout << tree.getWidth() << endl;
    tree.inorderTraverse();
    cout << tree.count(40,60) << endl;
    cout << tree.select(31) << endl;
    cout << tree.select(45) << endl;
    cout << tree.successor(34) << endl;
    cout << tree.successor(65) << endl;

    cout << tree.remove(10) << endl;
    cout << tree.remove(75) << endl;
    cout << tree.remove(80) << endl;
    cout << tree.remove(20) << endl;
    cout << tree.remove(50) << endl;


    return 0;
}
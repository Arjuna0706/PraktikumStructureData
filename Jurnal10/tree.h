#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
using namespace std;

struct Node;
typedef Node* adrNode;

struct Node {
    int value;
    adrNode left;
    adrNode right;
};

void createTree_108072500059(adrNode &root);
adrNode createNode_108072500059(int x);
void insertNode_108072500059(adrNode &root, adrNode p);
adrNode searchNode_108072500059(adrNode root, int x);
void displayTree_108072500059(adrNode root);
int countLeafNodes_108072500059(adrNode root);
int countInternalNodes_108072500059(adrNode root);
int heightTree_108072500059(adrNode root);
int sumOfValues_108072500059(adrNode root);

#endif
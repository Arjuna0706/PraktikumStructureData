#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *adrNode;

struct Node {
    infotype info;
    adrNode left;
    adrNode right;
};

void createTree_108072500059(adrNode &root);
adrNode createNode_108072500059(infotype x);
void insertNode_108072500059(adrNode &root, adrNode p);
void displayTree_108072500059(adrNode root);

adrNode getMinNode_108072500059(adrNode root);
adrNode getMaxNode_108072500059(adrNode root);

#endif
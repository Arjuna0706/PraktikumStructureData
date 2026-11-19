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
adrNode searchNode_108072500059(adrNode root, infotype x);
void displayTree_108072500059(adrNode root);

int countNodes_108072500059(adrNode root);
infotype getMinValue_108072500059(adrNode root);
infotype getMaxValue_108072500059(adrNode root);

#endif
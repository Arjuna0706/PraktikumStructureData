#include "tree.h"

void createTree_108072500059(adrNode &root) {
    root = nullptr;
}

adrNode createNode_108072500059(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode_108072500059(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else if (p->info < root->info) {
        insertNode_108072500059(root->left, p);
    } else {
        insertNode_108072500059(root->right, p);
    }
}

void displayTree_108072500059(adrNode root) {
    if (root != nullptr) {
        displayTree_108072500059(root->left);
        cout << root->info << " ";
        displayTree_108072500059(root->right);
    }
}

adrNode getMinNode_108072500059(adrNode root) {
    adrNode p = root;
    while (p != nullptr && p->left != nullptr) {
        p = p->left;
    }
    return p;
}

adrNode getMaxNode_108072500059(adrNode root) {
    adrNode p = root;
    while (p != nullptr && p->right != nullptr) {
        p = p->right;
    }
    return p;
}
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

adrNode searchNode_108072500059(adrNode root, infotype x) {
    if (root == nullptr) {
        return nullptr;
    } else if (x < root->info) {
        return searchNode_108072500059(root->left, x);
    } else if (x > root->info) {
        return searchNode_108072500059(root->right, x);
    }
    return root;
}

void displayTree_108072500059(adrNode root) {
    if (root != nullptr) {
        displayTree_108072500059(root->left);
        cout << root->info << " ";
        displayTree_108072500059(root->right);
    }
}

int countNodes_108072500059(adrNode root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes_108072500059(root->left)
             + countNodes_108072500059(root->right);
}

infotype getMinValue_108072500059(adrNode root) {
    if (root->left == nullptr) {
        return root->info;
    }
    return getMinValue_108072500059(root->left);
}

infotype getMaxValue_108072500059(adrNode root) {
    if (root->right == nullptr) {
        return root->info;
    }
    return getMaxValue_108072500059(root->right);
}
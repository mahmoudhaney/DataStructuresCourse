// Created by Mahmoud Haney on 8/4/2022.
#include <iostream>
#include "AVLTree.h"
using namespace std;

void AVLTree::inOrder(AVLTree::binaryNode *rootNode) {
    if(!rootNode)
        return;
    inOrder(rootNode->left);
    cout << rootNode->data << " ";
    inOrder(rootNode->right);
}

void AVLTree::inOrder() {
    inOrder(root);
    cout << endl;
}

int AVLTree::binaryNode::childHeight(AVLTree::binaryNode *node) {
    if(!node)
        return -1; // For Null
    return node->height;
}

int AVLTree::binaryNode::updateHeight() {
    return height = 1 + max(childHeight(left), childHeight(right));
}

int AVLTree::binaryNode::balanceFactor() {
    return childHeight(left) - childHeight(right);
}

AVLTree::binaryNode *AVLTree::rightRotation(AVLTree::binaryNode *rootNode) {
    binaryNode* leftNode = rootNode->left;
    rootNode->left = leftNode->right;
    leftNode->right = rootNode;
    rootNode->updateHeight();
    leftNode->updateHeight();
    return leftNode; // Left node will be the new root of the tree.
}

AVLTree::binaryNode *AVLTree::leftRotation(AVLTree::binaryNode *rootNode) {
    binaryNode* rightNode = rootNode->right;
    rootNode->right = rightNode->left;
    rightNode->left = rootNode;
    rootNode->updateHeight();
    rightNode->updateHeight();
    return rightNode; // Right node will be the new root of the tree.
}

AVLTree::binaryNode *AVLTree::balance(AVLTree::binaryNode *node) {
    // Cases where the balance factor = 2
    if (node->balanceFactor() == 2){ // 1- It's Left
        if(node->left->balanceFactor() == -1) // 2- It's Left-Right
            node->left = leftRotation(node->left); // 3- Then turn it to Left-Left
        node = rightRotation(node); // 4- Balance Left-Left
        // Note: if node->left->balanceFactor() != -1 then it's Left-Left and I will balance it directly.
    }

    // Cases where the balance factor = -2
    else if(node->balanceFactor() == -2) { // 1- It's Right
        if (node->right->balanceFactor() == 1) // 2- It's Right-Left
            node->right = rightRotation(node->right); // 3- Then turn it to Right-Right
        node = leftRotation(node); // 4- Balance Right-Right
        // Note: if node->left->balanceFactor() != 1 then it's Right-Right and I will balance it directly.
    }
    return node;
}

AVLTree::binaryNode *AVLTree::insertNode(int value, AVLTree::binaryNode *node) {
    if(value < node->data){ // Go Left
        if(!node->left) // Has no left "if node->left == NULL" then, insert here.
            node->left = new binaryNode(value);
        else // Go more left.
            node->left = insertNode(value, node->left); //Need to update the left each time.
    }
    else if (value > node->data){ // Go Right
        if(!node->right) // Has no right "if node->right == NULL" then, insert here.
            node->right = new binaryNode(value);
        else // Go more left.
            node->right = insertNode(value, node->right); //Need to update the right each time.
    }
    node->updateHeight();
    return balance(node); // Return the tree after inserting and updating.
}

void AVLTree::insert(int value) {
    if(!root)
        root = new binaryNode(value);
    else
        root = insertNode(value, root);
}

AVLTree::binaryNode *AVLTree::deleteNode(int value, AVLTree::binaryNode *node) {
    if(!node) // Empty
        return nullptr;
    if(value < node->data) // if value is less than current node->data ==> Go Left
        node->left = deleteNode(value, node->left);
    else if(value > node->data) // if value is greater than current node->data ==> Go Right
        node->right = deleteNode(value, node->right);
    else{ // Value is equal to node->data
        binaryNode* temp = node;
        if(!node->left && !node->right) // Case 1: No children => Just delete it.
            node = nullptr;
        else if(!node->right) // Case 2: Has only left then ==> connect it with its left child
            node = node->left;
        else if(!node->left) // Case 2: Has only right then ==> connect it with its right child
            node = node->right;
        else { // Case 3: Has 2 children ==> Use Successor
            binaryNode* mn = node->right; // Go to right subtree
            while (mn && mn->left) // Then pick the minimum
                mn = mn->left;
            node->data = mn->data; // Replace the deleted value with min of right subtree
            node->right = deleteNode(node->data, node->right);
            temp = nullptr;	// Don't delete me. Successor will be deleted
        }
        if(temp) delete temp;
    }
    if(node)
        node->updateHeight(), node = balance(node);
    return node;
}

void AVLTree::deleteValue(int value) {
    if(root)
        root = deleteNode(value, root);
}

bool AVLTree::search(int value, AVLTree::binaryNode *node) {
    if(!node)
        return false;
    if(value == node->data)
        return true;
    if(value < node->data)
        return search(value, node->left);
    return search(value, node->right);
}

bool AVLTree::search(int value) {
    return search(value, root);
}



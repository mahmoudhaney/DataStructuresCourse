// Created by Mahmoud Haney on 8/3/2022.
#ifndef DATASTRUCTURESTRAINING_BINARYSEARCHTREE_H
#define DATASTRUCTURESTRAINING_BINARYSEARCHTREE_H

struct node{
    int data { };
    node* left { };
    node* right { };
    node(int data) : data(data) {}
};

class BinarySearchTree {
private:
    node *root;
    void inorder(node *r);
    void preorder(node *r);
    void postorder(node *r);
    void clearTree(node* &r);
    void deleteNode(node * &r);
    int height(node *r);
    int nodesCount(node *r);
    int leavesCount(node *r);
public:
    BinarySearchTree() : root(NULL){}
    ~BinarySearchTree() {clearTree(this->root);}
    bool isEmpty();
    void inorder();
    void preorder();
    void postorder();
    void insert(int value);
    void clearTree();
    void remove(int);
    int height();
    int nodesCount();
    int treeLeavesCount();
    bool isExist(int value);
};
#endif //DATASTRUCTURESTRAINING_BINARYSEARCHTREE_H

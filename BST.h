#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include"NODE.h"
#include"COLOUR.h"
using namespace std;
class bstnode {
public:
    string category;
    string date;
    node* listnode;
    bstnode* left;
    bstnode* right;
    bstnode(string cat, string dt, node* ln) : category(cat), date(dt), listnode(ln), left(nullptr), right(nullptr) {}
};

class bst {
public:
    bstnode* root;
    bst() : root(nullptr) {}

    void insert(string cat, string dt, node* ln) {
        root = insert(root, cat, dt, ln);
    }

    bstnode* insert(bstnode* root, string cat, string dt, node* ln) {
        if (root == nullptr) {
            return new bstnode(cat, dt, ln);
        }
        if (cat < root->category || (cat == root->category && dt < root->date)) {
            root->left = insert(root->left, cat, dt, ln);
        }
        else if (cat > root->category || (cat == root->category && dt > root->date)) {
            root->right = insert(root->right, cat, dt, ln);
        }
        return root;
    }

    node* search(string cat, string dt) {
        return search(root, cat, dt);
    }

    node* search(bstnode* root, string cat, string dt) {
        if (root == nullptr) {
            return nullptr;
        }
        if (cat == root->category && dt == root->date) {
            return root->listnode;
        }
        if (cat < root->category || (cat == root->category && dt < root->date)) {
            return search(root->left, cat, dt);
        }
        else {
            return search(root->right, cat, dt);
        }
    }
};
//
// Created by Spandana Boppana on 1/22/17.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Tree
{
private:
    int data;
    Tree *left;
    Tree *right;
public:
    int visited;
    Tree(){
        data = 0;
        visited = 0;
        left = NULL;
        right = NULL;
    }
    Tree(int d){
        data = d;
        visited = 0;
        left = NULL;
        right = NULL;
    }
    Tree(int d, Tree *l, Tree *r){
        visited = 0;
        data = d;
        left = l;
        right = r;
    }
    Tree* getLeft() { return left; }
    Tree* getRight() { return right; }
    int getData(){ return data; }
    void setLeft(Tree *le) { left = le; }
    void setRight(Tree *ri) { right = ri; }
    void setData(int d) { data = d; }
    void show() { cout << data; }
};

class BinarySTree
{
    BinarySTree* left;
    BinarySTree* right;
    int data;
public:
    BinarySTree()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BinarySTree(int k)
    {
        data = k;
        left = NULL;
        right = NULL;
    }
    BinarySTree(int k, BinarySTree *l, BinarySTree *r)
    {
        data = k;
        left = l;
        right = r;
    }
    BinarySTree* getLeft(){ return left;};
    BinarySTree* getRight() { return right;};
    int getData(){ return data;};
    void setLeft(BinarySTree *le) {left = le;};
    void setRight(BinarySTree *ri){right = ri;};
    void setData(int d){ data = d; };
    void show(){ cout << data; };

};


#endif //TREES_TREE_H

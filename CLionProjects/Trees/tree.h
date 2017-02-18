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
    Tree(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Tree(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
    Tree(int d, Tree *l, Tree *r){
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
#endif //TREES_TREE_H

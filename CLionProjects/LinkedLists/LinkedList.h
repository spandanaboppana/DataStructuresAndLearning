//
// Created by Spandana Boppana on 12/25/16.
//

#ifndef DLL_LINKEDLISTS_LINKEDLIST_H
#define DLL_LINKEDLISTS_LINKEDLIST_H
#include <iostream>
#include <stdio.h>
using namespace std;

class List {
public:
    int value;
    List *next;
public:
    List();
    List(int v);
    List(int v, List *p);
    int getValue() {return value;}
    List* getNext() {return next;}
    // List* createANewNode(int val);
    // List* InsertAtHead(List *head);

    void show() {
        cout << value << " ";
    }
};
#endif //DLL_LINKEDLISTS_LINKEDLIST_H


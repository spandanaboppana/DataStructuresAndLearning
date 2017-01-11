//
// Created by Spandana Boppana on 12/25/16.
//

#ifndef DLL_LINKEDLISTS_LINKEDLIST_H
#define DLL_LINKEDLISTS_LINKEDLIST_H
#include <iostream>
#include <stdio.h>
#include <map>
#include <stack>
using namespace std;


class List {
public:
    int value;
    List *next;
    int flag;
public:
    List();
    List(int v);
    List(int v, List *p);
    List(int v, List *p, int flag);
    int getValue() {return value;}
    List* getNext() {return next;}
    // List* createANewNode(int val);
    // List* InsertAtHead(List *head);

    void show() {
        cout << value << " ";
    }
};
List* createSLL (int array[], int length) {
    List *curr, *prev;
    for (int n = 0; n < length; n++) {
        if (n==0) {
            curr = new List(array[n]);
        } else {
            curr = new List(array[n], prev);
        }
        prev = curr;
    }
    return curr;
}
List *createCLL (int array[], int length)
{
    List *curr,*prev,*last;
    for(int i=0;i<length;i++) {

        if (i==0) {
            curr = new List(array[i]);
            last = curr;

        } else {
            curr = new List(array[i], prev);
        }
        prev = curr;
    }
    if(curr->next != NULL)
    {
        last->next = curr;
    }

    return curr;
}
/*
 *
 */
List* createSLLwithFlag (int array[], int length, int f) {
    List *curr, *prev;
    for (int n = 0; n < length; n++) {
        if (n==0) {
            curr = new List(array[n]);
        } else {
            curr = new List(array[n], prev, f);
        }
        prev = curr;
    }
    return curr;
}
#endif //DLL_LINKEDLISTS_LINKEDLIST_H


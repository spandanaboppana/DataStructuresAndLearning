//
// Created by Spandana Boppana on 1/9/17.
//

#ifndef STACKS_STACK_H
#define STACKS_STACK_H
#include <iostream>
#endif //STACKS_STACK_H
using namespace std;
template <class Type>
class stack{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack()  = 0;
    virtual bool isFullStack()  = 0;
    virtual void Push(const Type &newItem) = 0;
    virtual Type Top()  = 0;
    virtual void Pop() = 0;

};

template <class Type>
class stackType: public stack<Type>
{
public:
   void initializeStack();
    bool isEmptyStack();
    bool isFullStack();
    void Push(const Type &newItem);
    Type Top();
    void Pop();
    stackType(int stackSize=100);
    ~stackType();
private :
    int maxStackSize;
    int stackTop;
    Type *list;
};

template <class Type>
void stackType<Type> ::initializeStack()
{
    stackTop =0;
}

template <class Type>
bool stackType<Type>::isEmptyStack()  {
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type> ::isFullStack()  {
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type> ::Push(const Type &newItem){
    if(!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
        cout<<"cannot add to a full stack"<<endl;
}
template <class Type>
Type stackType<Type>::Top()  {
    if(stackTop != NULL)
    {
        return list[stackTop-1];
    }
}

template <class Type>
void stackType<Type>::Pop(){
    if(!isEmptyStack())
    {
        stackTop--;
    }
    else
    {
        cout<<"cannot remove from empty stack"<<endl;

    }
}

template <class Type>
stackType<Type> :: stackType(int stackSize)
{
    if(stackSize <= 0)
    {
        maxStackSize = 100;
    }
    else
    {
        maxStackSize = stackSize;
    }
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type> :: ~stackType()
{
    delete [] list;
}

template <class Type>
struct nodeType
{
    Type value;
    nodeType<Type> *next;
};

template <class Type>
class linkedStackType: public stack<Type>
{
public:
    void initializeStack();
    bool isEmptyStack();
    bool isFullStack();
    void Push(const Type &newItem);
    Type Top();
    void Pop();
    linkedStackType();
    ~linkedStackType();

private:
    nodeType<Type> *stackTop;

};

template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = NULL;
}
template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp;
    while(stackTop != NULL)
    {
        temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }

}

template <class Type>
linkedStackType<Type>::~linkedStackType() {
    initializeStack();
}



template <class Type>
bool linkedStackType<Type> :: isEmptyStack()
{
 return (stackTop == NULL);
}

template <class Type> //here in linked list, practically isFullStack doesnt work as we can add more nodes any time as it doesnt have any limitation
bool linkedStackType<Type> ::isFullStack() {
    return false;
}

template <class Type>
void linkedStackType<Type> :: Push(const Type &newItem){
    nodeType<Type> *newNode;
        newNode = new nodeType<Type>;

        newNode->value = newItem;
        newNode->next = stackTop;
        stackTop = newNode;
}

template <class Type>
Type linkedStackType<Type> ::Top(){
    if(stackTop!= NULL){
        return (stackTop->value);
    }
    else
    {
        cout<<"No elements in stack"<<endl;
        return 0;
    }

}

template <class Type>
void linkedStackType<Type> ::Pop(){
    nodeType<Type> *temp;
    if(!isEmptyStack())
    {
        temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }
    else
    {
        cout<<"Cannot remove from an empty stack"<<endl;
    }
}

class twoStacks
{
    int top1;
    int top2;
    int *arr;
    int size;
public:
    twoStacks(int n);
    void Push1(int x);
    void Push2(int x2);
    int Top1();
    int Top2();
    void Pop1();
    void Pop2();
};
twoStacks::twoStacks(int n)
{
    size = n;
    arr = new int[n];
    top1 = -1;
    top2 = size;
}
void twoStacks::Push1(int x)
{
    if(top1 < top2 -1)
    {
        top1++;
        arr[top1] = x;

    }
    else
    {
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
}

void twoStacks::Push2(int x)
{
    if(top1 <top2-1)
    {
        top2--;
        arr[top2] = x;
    }
    else
    {
        cout<<"Stack overflow"<<endl;
        exit(1);
    }
}

int twoStacks::Top1()
{
    if(top1>=0)
    {
        return arr[top1];
    }

}

int twoStacks::Top2()
{
    if(top2 < size)
    {
        return arr[top2];
    }
}

void twoStacks::Pop1()
{
    if(top1>=0)
    {
        top1--;
    }
    else
    {
        cout<<"stack under flow"<<endl;
        exit(1);
    }


}

void twoStacks::Pop2()
{
    if(top2 < size)
    {
        top2++;
    }
    else
    {
        cout<<"stack underflow"<<endl;
        exit(1);
    }

}

class kStacks
{
    int *arr;
    int *top;
    int *next;

    int n, k;
    int free;
public:
    kStacks(int k,int n);
    bool isFull();
    bool isEmpty(int sn);
    void push(int item, int sn);
    int pop(int sn);

};

kStacks :: kStacks(int k1, int n1) {
    k = k1;
    n= n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];

    for(int i=0;i<k;i++)
    {
        top[i] = -1;
    }
    free =0;
    for(int i=0;i<n-1;i++)
    {
        next[i]= i+1;
        next[n-1]= -1;
    }
}
bool kStacks::isFull()
{
    return (free == -1);
}

bool kStacks::isEmpty(int sn) {
    return (top[sn] == -1);
}
//sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
    if(isFull())
    {
        cout<<"The stack overflow"<<endl;
        return;
    }
    int i = free;//store index of first free slot
    free = next[i+1];

    next[i] = top[sn];
    top[sn] = i;

    arr[i] = item;//Put the item in array

}

//To pop item from stack number sn where sn is from 0 to k-1
/*int kStacks::Pop(int sn)
{
    if(isEmpty(sn))
    {
        cout<<"Stack Underflow"<<endl;
        return INT8_MAX;
    }

    int i = top[sn];
    top[sn] = next[i];

    next[i] = free;
    free = i;

    return arr[i];
}*/
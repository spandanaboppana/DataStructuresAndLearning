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
    stackTop =0;
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


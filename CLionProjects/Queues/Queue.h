//
// Created by Spandana Boppana on 1/13/17.
//

#ifndef QUEUES_QUEUE_H
#define QUEUES_QUEUE_H
#include <iostream>
#include <assert.h>
using namespace std;

template <class Type>
class Queue
{
public:
virtual bool isEmptyQueue() =0;
virtual bool isFullQueue()=0;
virtual Type Front()=0;
virtual Type Back()=0;
virtual void initializeQueue()=0;
virtual void addQueue(Type &element)=0;
virtual void deleteQueue()=0;

};

template <class Type>
class queueType: public Queue<Type>
{
public:
    bool isEmptyQueue();
    bool isFullQueue();
    void initializeQueue();
    Type Front();
    Type Back();
    void addQueue(Type &element);
    void deleteQueue();
    queueType(int queueSize =100);
    ~queueType();
    int size();
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueBack;
    Type *list;
    int queuesize;
};

template <class Type>
int queueType<Type>::size()
{
    queuesize = (maxQueueSize-queueFront+queueBack)%maxQueueSize;
    return queuesize;
}
template <class Type>
bool queueType<Type>::isEmptyQueue()
{
    return(queueFront == queueBack);
}

template <class Type>
bool queueType<Type>::isFullQueue() {

    return(queueFront == (queueBack +1)%maxQueueSize);
}

template <class Type>
void queueType<Type>::initializeQueue() {
    queueFront =0;
    queueBack = maxQueueSize-1;
    count =0;
}

template <class Type>
Type queueType<Type>::Front(){
    assert(!isEmptyQueue());
    return list[queueFront];
}

template <class Type>
Type queueType<Type>::Back() {
    assert(!isFullQueue());
    return list[queueBack];
}

template <class Type>
void queueType<Type>::addQueue(Type &element) {
    if(!isFullQueue())
    {
        count++;
        list[queueBack] = element;
        queueBack = (queueBack+1)%maxQueueSize;//using the mod operator to point to the next element as the array is circular
    }
    else
    cout<<"Cannot add to a full queue"<<endl;
}

template <class Type>
void queueType<Type>::deleteQueue() {
    if(!isEmptyQueue())
    {
        count--;
        queueFront = (queueFront+1)%maxQueueSize;
    }
    else
        cout<<"Cannot delete from a empty queue"<<endl;
}

template <class Type>
queueType<Type>::queueType(int queueSize) {
    if(queueSize <=0)
    {
        maxQueueSize = 100;
    }
    else
    {
        maxQueueSize = queueSize;
        queueFront = 0;
        queueBack = 0;
        count =0;
        list = new Type[maxQueueSize];
    }
}

template <class Type>
queueType<Type>::~queueType()
{
    delete[] list;
}

//Linked list implementation of queue
template <class Type>
struct nodeType
{
    Type data;
    nodeType<Type> *next;

};

template <class Type>
class linkedQueueType:public Queue<Type>
{
public:
    bool isEmptyQueue();
    bool isFullQueue();
    Type Front();
    Type Back();
    void initializeQueue();
    void addQueue(Type &element);
    void deleteQueue();
    linkedQueueType();
    ~linkedQueueType();

private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRare;
};

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue()
{
    return(queueFront == NULL);
}

template <class Type>
bool linkedQueueType<Type>::isFullQueue() {
    return false;
}

template <class Type>
Type linkedQueueType<Type>::Front() {
        assert(queueFront!=NULL);
        return queueFront->data;
}

template <class Type>
Type linkedQueueType<Type>::Back() {
    assert(queueRare!= NULL);
    return queueRare->data;
}

template <class Type>
void linkedQueueType<Type>::initializeQueue() {

    nodeType<Type> *temp;
    while(queueFront!=NULL)
    {
        temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
    }
    queueRare = NULL;
}

template <class Type>
void linkedQueueType<Type>::addQueue(Type &element) {
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;

    newNode->data = element;
    newNode->next = NULL;

    if(queueFront == NULL)
    {
        queueFront = newNode;
        queueRare = newNode;
    }
    else
    {
        queueRare->next = newNode;
        queueRare = queueRare->next;
    }

}

template <class Type>
void linkedQueueType<Type>::deleteQueue() {
    nodeType<Type> *temp;
    if(!isEmptyQueue())
    {
        temp = queueFront;
        queueFront = queueFront->next;
        delete temp;

        if(queueFront == NULL)
        {
            queueRare = NULL;
        }

    }
    else
    {
        cout<<"The queue is empty to delete";
    }
}

template <class Type>
linkedQueueType<Type> ::linkedQueueType() {
    queueFront = NULL;
    queueRare = NULL;
}

template <class Type>
linkedQueueType<Type> ::~linkedQueueType() {
    initializeQueue();
}

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
struct nodeSType
{
    Type value;
    nodeSType<Type> *next;
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
    nodeSType<Type> *stackTop;

};

template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = NULL;
}
template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeSType<Type> *temp;
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
    nodeSType<Type> *newNode;
    newNode = new nodeSType<Type>;

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
    nodeSType<Type> *temp;
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

#endif //QUEUES_QUEUE_H

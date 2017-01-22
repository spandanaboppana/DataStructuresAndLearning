
#include "Queue.h"
void QueueUsingArrays()
{
    queueType<int> qt;
    qt.initializeQueue();
    int x =1, y=2, z=3, p=4, q=5;
    int temp;
    qt.addQueue(x);
    qt.addQueue(y);
    qt.addQueue(z);
    qt.addQueue(p);
    qt.addQueue(q);

    cout<<"The elements of queue in array are"<<endl;
    while(!qt.isFullQueue())
    {
       temp = qt.Front();
        qt.deleteQueue();
        cout <<temp;
    }
    cout <<endl;
}

void QueueUsingLinkedLists()
{
    linkedQueueType<int> lqt;
    lqt.initializeQueue();
    int x=1, y=2,z=3,p=4,q=5,r=6;
    int temp;
    lqt.addQueue(x);
    lqt.addQueue(y);
    lqt.addQueue(z);
    lqt.addQueue(p);
    lqt.addQueue(q);
    lqt.addQueue(r);

    cout<<"The elements of queue in array are"<<endl;
    while(!lqt.isFullQueue())
    {
        temp = lqt.Front();
        lqt.deleteQueue();
        cout<<temp;
    }
    cout<<endl;
}
//Method to reverse a Queue
void reverseAQueue()
{
    queueType<int> qt;
    int x=1,y=2,z=3,p=4,q=5,r=6;
    int temp;
    qt.initializeQueue();
    qt.addQueue(x);
    qt.addQueue(y);
    qt.addQueue(z);
    qt.addQueue(p);
    qt.addQueue(q);
    qt.addQueue(r);
    stackType<int> st;
    while(!qt.isEmptyQueue())
    {
        st.Push(qt.Front());
        qt.deleteQueue();
    }
    while(!st.isEmptyStack())
    {
        temp = st.Top();
        cout<<temp<<" ";
        st.Pop();
    }

}
class QueueUsingStacks{
private:
    stackType<int> inputStack;
    stackType<int> outputStack;
    int size;
public:
    void Enqueue(int ele);
    int Dequeue();

};

class StackUsingTwoQueues{
private:
    queueType<int> inputqueue;
    queueType<int> outputqueue;
public:
    void addaQueue(int ele);
    int deleteaQueue();
};
//Push the element into the queue by seeing which queue is empty
void StackUsingTwoQueues::addaQueue(int ele) {
    if(!inputqueue.isEmptyQueue())
    {
        inputqueue.addQueue(ele);
    }
    else
    {
        outputqueue.addQueue(ele);
    }
}
//Pop the element
int StackUsingTwoQueues::deleteaQueue() {
    int temp=0;
    if(!inputqueue.isEmptyQueue())
    {
        int qsize = inputqueue.size();

        while(qsize > 1)
        {
            temp = inputqueue.Front();
            outputqueue.addQueue(temp);
            inputqueue.deleteQueue();
            qsize = inputqueue.size();
        }
        int ret = inputqueue.Front();
        inputqueue.deleteQueue();
        return ret;

    } else
    {
        int qsize = outputqueue.size();
        while(qsize > 1)
        {
            temp = outputqueue.Front();
            inputqueue.addQueue(temp);
            outputqueue.deleteQueue();
            qsize = outputqueue.size();
        }
        return outputqueue.Front();
    }
}

//Enqueue
void QueueUsingStacks:: Enqueue(int ele)
{

        inputStack.Push(ele);
        size++;
}

int QueueUsingStacks::Dequeue()
{
    int temp=0;
    if(outputStack.isEmptyStack())
    {
        temp = NULL;
        while(!inputStack.isEmptyStack())
        {
            temp = inputStack.Top();
            outputStack.Push(temp);
            inputStack.Pop();
        }

    }
    if(!outputStack.isEmptyStack()) //if output stack is not empty pop out elements which are present
    {

        temp =  outputStack.Top();
        outputStack.Pop();
        size--;
    }


    return temp;
}

//Implementing aqueue using two stacks;
void queueUsingTwoStacks()
{
    QueueUsingStacks qus;
    for(int i=1;i<=3;i++)
    {
        qus.Enqueue(i);
    }
    for(int i=0;i<2;i++)
    {
        cout<<qus.Dequeue();
    }
    for(int i=4;i<=5;i++)
    {
        qus.Enqueue(i);
    }
   cout<<qus.Dequeue();

}

//Implementing a one Stack using two queues
void stackUsingTwoQueues()
{
    int ret;
    StackUsingTwoQueues suq;
    suq.addaQueue(1);
    suq.addaQueue(2);
    suq.addaQueue(3);
    ret = suq.deleteaQueue();
    cout << ret;
    ret = suq.deleteaQueue();
    cout << ret;
    ret = suq.deleteaQueue();
    cout << ret;
}
//Maximum sum in sliding window

int main() {

    //QueueUsingArrays();
    //QueueUsingLinkedLists();
    //reverseAQueue();
    //queueUsingTwoStacks();
    stackUsingTwoQueues();
    return 0;
}
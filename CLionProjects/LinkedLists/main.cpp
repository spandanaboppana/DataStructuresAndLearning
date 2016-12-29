#include "LinkedList.h"
List::List() {
    value = -1;
    next = NULL;
    flag = 0;
}

List::List(int v) {
    value = v;
    next = NULL;

}
/*
 * Adds at head
 */
List::List(int v, List *p) {
    value = v;
    next = p;

}

List::List(int v, List *p, int f)
{
    value =v;
    next = p;
    flag = f;
}

void printList(List *head) {
    while(head != NULL) {
        head->show();
        head = head->getNext();
    }
    cout << endl;
}

List* createANewNode(int val)
{
    List* newNode;
    newNode = new List(val);
    newNode->next = NULL;
    return newNode;
}

List* insertAtHead(List *head, int data)
{
    List *newNode = createANewNode(data);
    if(head!= NULL)
    {

        newNode->next = head;
        head = newNode;
    }
    return head;
}

List* insertAtPos(List *head, int pos, int data)
{
    int k=1;
    List *newNode = createANewNode(data);

    if (pos == 1 )
    {
        newNode->next = head;
        head = newNode;
    } else {
        List *current;
        List *prevcurrent;
        current = head;
        prevcurrent = current;

        while(current!= NULL && k < pos-1)          //Moving the pointer infront of position.
        {
            prevcurrent = current;
            current = current->next;
            k++;
        }
        if(current == NULL)                     //In the end
        {

            prevcurrent->next = newNode;
            newNode->next = NULL;
        } else {                                  //In the middle
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    return head;
}

List* deleteANode(List *head, int pos)  //Here position node is the node where we stop. so after this position node we will delete the new node.
{
        int k =1;
        List *current;
        List *prevcurrent;
        current = head;

        if(pos == 1 )
        {
            head = current->next;
            delete current;
        } else {
            while (current!= NULL && k < pos )
            {
                prevcurrent = current;
                current = current->next;
                k++;
            }
            if(current == NULL)
            {
               cout<<"Position doesnt exists";
            } else {
                prevcurrent->next = current->next;
                delete current;
            }
        }
        return head;
    }
//finding a nth node from ll using brute force method
int findNthnode(int n, List*head)
{
    List *current;
    List *temp;
    current = head;
    temp = current;
    int count = 0;
    while(current!= NULL)
    {
        current = current->next;
        count++;
    }
    if(n > count)
    {
        cout<<"The number of nodes are smaller than the node";
        return 0;
    }
    for(int i=1;i<(count-n+1);i++)
    {
        temp = temp->next;

    }
    return temp->value;
}
//finding the nth node using map.
int findNthnodeUsingMap(int n, List*head)
{

    List *current;
    current = head;
    std::map <int,List*> mapofwords;
    int pos = 0;
    List *addr;
    int count = 0;

    while(current!= NULL)
    {
        pos = pos+1;
        addr = current;
        mapofwords[pos] = addr;
        current = current->next;
        count++;
    }


    if(n>count)
    {
       cout<<"The given number is greater than list size" <<endl;
    }
    else
    {
        cout<<"The number at nth position is";
        mapofwords[count-n+1]->show();
        //it->second->show();
        cout<<endl;
    }

}

//finding the nth node of a list from end in efficient way.
int findNthNodeE(int n, List* head)
{
    List *ptemp;
    List *ntemp;
    ptemp = head;
    ntemp = head;
    int i = 0;

    while(i<n) {
        if(ptemp == NULL)
        {
            cout<<"The value is greater than number of nodes in the list"<< n <<endl;
        }
        ptemp = ptemp->next;
        i++;
    }
        while(ptemp!= NULL)
        {
            ntemp = ntemp->next;
            ptemp = ptemp->next;
        }
    return ntemp->value;
}
//check whether the given linked list contains cycle or not //here two nodes will have  next pointers  same.
int findCyleinLLusingflag(List *head)
{
    List *current;
    current = head;

    while(current!= NULL)
    {
        if(current->flag)
        {
            cout<<"Node already visited and there is a loop"<<endl;
            return 1;
        }

        current->flag = 1;
        current = current->next;

    }
        cout<<"No loop"<<endl;
        return 0;
}
//check whether the given list contains cycle or not using hashing
int findCycleinLLusingHashMap(List *head)
{
    List *current;
    current = head;

    int pos=0;
    List *addr;
    std::map<List*,int> mapofwords;
    while(current!= NULL)
    {
        pos = pos+1;
        addr = current;
        if(mapofwords.find(addr) == mapofwords.end())
        {
            mapofwords[addr]=pos;
        }
        else {
            cout<<"Loop exists in linked list"<<endl;
            return 0;

        }
        current = current->next;
    }
    cout<<"Loop doesnt exists"<<endl;
    return 1;
}
//check whether the given list contains cycle or not using the efficient method //Some where in loop two pointers will meet, if the one pointer moves one step and other pointer moves two steps.
int findCycleinLLE(List *head)
{
    List *fastptr;
    List *slowptr;
    fastptr = head;
    slowptr = head;
    while(fastptr!= NULL)
    {
        slowptr = slowptr->next; //moving one step at a time
        fastptr = fastptr->next->next; //moving two steps at a time.
        if(fastptr == slowptr)
        {
            cout<<"loop exixts"<<endl;
            return 0;
        }
    }
        cout<<"loop doesnt exixts"<<endl;
        return 1;
}

//check whether linked list contains cycle , if there is a cycle find start node of the loop
int findCycleandStartNodeofLoopifCycle(List *head)
{
    List *fastptr;
    List *slowptr;
    int  strtNodeOfLoop;
    fastptr = head;
    slowptr = head;
    while(fastptr!= NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr)
        {
            cout<<"loop exists"<<endl;
            slowptr = head;
            while(slowptr!=fastptr)
            {
                slowptr = slowptr->next;
                fastptr = fastptr->next;
            }
            strtNodeOfLoop = slowptr->value;
            return strtNodeOfLoop;
        }

    }
    cout << "loop doesnt exists"<<endl;
    return 1;
}

//check whether linked list contains a cycle, if there is a cycle find length of loop
int findCycleandLengthofloopifCycle(List *head)
{
    List *slowptr;
    List *fastptr;
    int length = 1;
    slowptr = head;
    fastptr = head;
    while(fastptr!= NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(slowptr == fastptr)
        {
            cout<<"loop exixts"<<endl;
            slowptr = slowptr->next;
            while(slowptr!=fastptr)
            {
                length++;
                slowptr = slowptr->next;

            }

            return length;
        }


    }
    cout<<"loop doesnt exists"<<endl;
    return 1;
}

//inserting a node in a sorted linked list
//Here my array is in descending order
List* insertANodeinSortedList(List *head, int data)
{
    List *current;
    current = head;
    List *temp;
    List *newNode;
    temp = head;
    newNode = createANewNode(data);
    while(current!= NULL && current->value > data)
    {
        temp = current;
        current = current->next;
    }

            if(current->value < data)
            {
                newNode->next = current;
                current = newNode;
                return current;
            }
            else
            {
                newNode->next = current;
                temp->next = newNode;
                return head;

            }
}

void basicLinkedListOperations() {
    int val;
    List *n1 = new List(10);
    List *n2 = new List(20, n1);
    List *n3 = new List(30, n2);
    List *n4 = new List(40, n3);
    List *n5 = new List(40, n4);
    List *head = n5;

    //head = insertAtHead(head, 50);
    //head = insertAtPos(head, 1, 60);
    printList(head);

  //  head = deleteANode(head,5);

    val = findNthnode(2,head);
   // cout <<"The value at 2nd position is "<<val<<endl;
   //val = findNthnodeUsingMap(7,head);
    findCyleinLLusingflag(head);
       // val = findNthNodeE(7, head);
    //cout <<"The value at position is "<<val<<endl;
    // head = removeDuplicates(head);
    // head = reverse(head);
    // head = reversepairs(head);
    printList(head);
}
void linkedListsForkProblem() {
    List *n1 = new List(10);
    List *n2 = new List(20, n1);
    List *n3 = new List(30, n2);
    List *n4 = new List(40, n3);
    List *n5 = new List(50, n4);
    List *head1 = n5;
    List *n6 = new List(60, n2);
    List *n7 = new List(70, n6);
    List *head2 = n7;
    printList(head1);
    printList(head2);

}

void LinkedlistLoop()
{
    int value;
    int length;
    List *n1 = new List(10);
    List *n2 = new List(20, n1,0);
    List *n3 = new List(30, n2,0);
    List *n4 = new List(40, n3,0);
    List *n5 = new List(50, n4,0);
    List *n6 = new List(60, n5,0);
    List *n7 = new List(70, n6,0);
    List *n8 = new List(80, n7,0);
    List *head = n8;
    //findCyleinLLusingflag(head);
    //findCycleinLLusingHashMap(head);
    //findCycleinLLE(head);
    //findCycleandStartNodeofLoopifCycle(head);
    n1->next = n8;
    //findCycleinLLusingHashMap(head);
    //findCyleinLLusingflag(head);
    //findCycleinLLE(head);
    //value = findCycleandStartNodeofLoopifCycle(head);
    //cout<<"The starting node of loop is"<< value<<endl;
    length = findCycleandLengthofloopifCycle(head);
    cout<<"The length of the loop is"<<length<<endl;
    //printList(head);
}

int main() {
    //basicLinkedListOperations();
    // linkedListsForkProblem();
   // LinkedlistLoop();
   int inputArray[] = {10,20,30,40,50,60,70,80};
   List* head = createSLL(inputArray, 8);
    printList(head);
    head =  insertANodeinSortedList(head,5);
    printList(head);
        return 0;
    }


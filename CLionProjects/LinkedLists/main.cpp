#include "LinkedList.h"
List::List() {
    value = -1;
    next = NULL;
    flag = 0;
}

List::List(int v) {
    value = v;
    next = NULL;
    flag = 0;
}

/*
 * Adds at head
 */
List::List(int v, List *p) {
    value = v;
    next = p;
    flag = 0;
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

/*void printListCLL(List **head)
{
    List **current;
    *current = *head;
    if(*head == NULL)
    {
        return ;
    }
    do
    {
        //*current->show();
        *current = *current->next;
    }while(*current!= *head);
    cout << endl;
}*/

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
            return 1;
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
int findCycleinLLE(List *head) {
    List *fastptr;
    List *slowptr;
    fastptr = head;
    slowptr = head;
    if (head == NULL) {
        cout << "Input validation error" << endl;
        return 1;
    }
    while (fastptr != NULL) {
        slowptr = slowptr->next; //moving one step at a time
        fastptr = fastptr->next;
        if (fastptr == NULL) {
            cout << "loop doesnt exixts" << endl;
            return 1;
        }
        fastptr = fastptr->next;
        if (fastptr == slowptr) {
            cout << "loop exixts" << endl;
            return 0;
        }
    }
    cout << "loop doesnt exixts" << endl;
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

    if (current->value < data)
    {
        if(temp->value < data)       //for first node
        {
            newNode->next = current;
            current = newNode;
            return current;
        }
        else
        {   // current
            newNode->next = current;   //for last node and middle node
            temp->next = newNode;
            return head;

        }
    }
    else {
        temp->next = newNode;
        return head;
    }

}

//Reversing a Single Linked List.
List* ReverseASingleLinkedList(List *head)
{
    List *temp;
    List *nextNode;
    temp = NULL; nextNode = NULL;
    while(head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;

    }
return temp;

}

//Finding the merge point in between two single linked lists //using brute force method
int findMergePointinTwoLists(List *head1, List *head2)
{
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    int mergepoint;
    while(current1 != NULL)
    {
        while(current2 != NULL)
        {
            if(current1 != current2)
            {
                current2 = current2->next;
            }
            else
            {
                mergepoint = current2->value;
                cout<<"The merge point of both list is "<< mergepoint;
                return mergepoint;
            }

        }
        current2 = head2;
        current1 = current1->next;
    }
    cout<<"No merge point exists in the list"<< endl;
    return 0;
}
//Finding merge point in two lists using Hasp Map
int findMergePointinTwoListsusingHashMap(List *head1, List *head2)
{
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    std::map <List*,int> mapofwords;
    int pos = 0;
    List *addr;
    int mergepoint;
    while(current1 != NULL) //choosing one list randomly
    {
        addr = current1;
        pos = pos +1;
        mapofwords[addr] = pos;
        current1 = current1->next;
    }
    if(head1 != NULL) {


        while (current2 != NULL) {
            auto foundaddr = mapofwords.find(current2);
            if (foundaddr != mapofwords.end()) {
                mergepoint = foundaddr->first->value;
                cout << "The merge node is " << mergepoint << endl;
                return mergepoint;
            } else {
                current2 = current2->next;
            }
        }
        cout << "The merge point doesn't exixts" << endl;
        return 0;
    }
}
//finding merge point of two linked list using stack
int findMergePointinTwoListsusingStack(List *head1, List *head2)
{
    std::stack<List*> mystack1;
    std::stack<List*> mystack2;
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    List* temp;
    int mergepoint;
    while(current1 != NULL)
    {
        mystack1.push(current1);
        current1 = current1->next;
    }
    while(current2 != NULL)
    {
        mystack2.push(current2);
        current2 = current2->next;
    }

    while(!mystack1.empty() && !mystack2.empty())
    {
        if (mystack1.top() == mystack2.top())
        {
            temp = mystack1.top();
            mystack1.pop();
            mystack2.pop();
        }
        else //whenever the top of stack value is different, from there list diverges, so common node is previous stored value in temp
        {
            mergepoint = temp->value;
            cout << "The merge point is " << mergepoint;
            return mergepoint;
        }
    }
    cout<<"Merge point doesn't exists"<<endl;
    return 0;
}

//Finding the merge point of two linked lists// finding the first repeating number
/*void findMergePointinListsUsingFindingFirstRepeatNumber(List *head1, List *head2)
{
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    List* array;
    array = new List[4];

    while(current1 != NULL && current2 != NULL)
    {
        array[i] = current1;
        current1 = current1->next;
        array[i] = current2;
        current2 = current2->next;
    }
}*/

//Finding the Merge Point of two linked lists in an Efficient manner
int findmergePointinListsUsingEfficientmanner(List *head1, List *head2)
{
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    int length1 = 0;
    int length2 = 0;
    int d = 0;
    int i = 0;
    int mergepoint;
    while(current1 != NULL)
    {
        current1 = current1->next;
        length1++;
    }
    while(current2 != NULL)
    {
        current2 = current2->next;
        length2++;
    }
    d = length1 - length2;
    current1 = head1;
    current2 = head2;
    if(length1 < length2)
    {
        current1 = head2;
        current2 = head1;
        d = length2 - length1;
    }
    for(i=0;i<d;i++)
    {
        current1 = current1->next;
    }
    while(current1 != NULL && current2 != NULL)
    {
        if(current1 == current2)
        {
            mergepoint = current1->value;
            cout<<"The merge point of both lists is " << mergepoint;
            return mergepoint;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return 0;
}

//Finding the Middle of Linked List //using the brute force method
int FindMiddleofLinkedList(List *head)
{
    List *current;
    List *temp;
    current = head;
    int count =0;
    while(current != NULL)
    {
        current = current->next;
        count++;
    }
    current = head;
    count = count/2;
    for (int i=0; i<count ; i++)
    {
        current = current->next;
    }
    cout <<"The middle point in list"<<current->value;
}
// Finding the middle of linked list
int FindMiddleofLinkedListusingHashmap(List *head) {
    List *current;
    current = head;
    std::map<int, List *> mapofwords;
    List *addr;
    int pos = 0;
    std::map<int,List*>::iterator it;
    List* middlepoint;
    while (current != NULL) {
        addr = current;
        mapofwords[pos] = addr;
        pos++;
        current = current->next;
    }
    pos = (pos/2);
    it = mapofwords.find(pos);
    if (it != mapofwords.end()) {
        middlepoint = it->second;
        cout << "The middle node is " << middlepoint->value << endl;
        return middlepoint->value;
    }
    return 0;
}
//Finding the middle of linkedlist using one scan-Efficient Method
int FindMiddleofLinkedListE(List *head)
{
    List *currentfast;
    List *currentslow;
    currentfast = head;
    currentslow = head;
    while(currentfast->next != NULL)
    {
        currentfast = currentfast->next;
        if(currentfast->next != NULL)
        currentfast = currentfast->next;

        currentslow = currentslow->next;
    }
    cout << "The middle node of linked list is "<< currentslow->value;
    return currentslow->value;

}

//Displaying Linked List from end
void DisplayLinkedListFromEnd(List *head)
{
    if(!head)
    {
        return;
    }
    DisplayLinkedListFromEnd(head->next);
    cout << head->value;
}
//check whether linked list length is even or odd
void isLinkedListEvenorOdd(List *head)
{
    List *current;
    current = head;
    int length=0;
    while(current != NULL)
    {
        current = current->next;
        length ++;
    }
    if(length%2 == 0)
    {
        cout<<"The linked list is even";
    }
    else
    {
        cout<<"The linked list is odd";
    }
}
//check whether linked list is even or odd Effective method
void isLinkedListEvenorOddE(List *head)
{
    List *current;
    current = head;
    while(current && current->next)
    {
        current = current->next->next;

    }
    if(!current)
    {
        cout <<"The linked list is even"<<endl;

    }
    else
    {
        cout<<"The linked list is odd"<<endl;
    }
}
//Given two sorted lists, we need to merge them into new single list
List * MergeTwoListofSortedOrderIntoThirdList(List *head1, List *head2)
{
    List *current1;
    List *current2;
    List *result= NULL;
    current1 = head1;
    current2 = head2;
    if(current1 == NULL)
    {
        return current2;
    }
    if(current2 == NULL)
    {
        return current1;
    }
    if(current1->value <= current2->value)
    {
        result = current1;
        result->next = MergeTwoListofSortedOrderIntoThirdList(current1->next,current2);
    }
    else
    {
        result = current2;
        result->next = MergeTwoListofSortedOrderIntoThirdList(current1,current2->next);
    }
    return result;

}
//Reverse the linked list in pairs
List* ReverseLinkedListPair(List *head)
{
    List *temp;
    List *current;
    current = head;
    if(current == NULL || current->next == NULL)
    {
        return current;
    }

    temp = current->next;
    current->next = temp->next;
    temp->next = current;

    current->next = ReverseLinkedListPair(current->next);
    return temp;
}
//Splitting Circular linked list
void SplittingCLL(List *head,List **head1, List **head2)
{
    List *fastptr,*slowptr;
    fastptr = head;
    slowptr = head;
    List *currfirst;
    List *currsecond;
    while(fastptr->next != head && fastptr->next->next != head)//for odd lists, fastptr points to last before node,for even list fastptr points to last node
    {
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    *head1 = head;         //making first list head
    if(head->next != head)
    {
        *head2 = slowptr->next;         //making the second list head;
    }

    //making first list circular
    slowptr->next = head;
    //making second list circular
    fastptr->next = slowptr->next;

}
//comparing two lists

bool compareLists(List *head1,List*head2)
{
    List *current1;
    List *current2;
    current1 = head1;
    current2 = head2;
    while(current1 != NULL && current2 != NULL)
    {
        if(current1->value == current2->value){
            current1 = current1->next;
            current2 = current2->next;
        }
        else
            return 0;

    }
    if(current1 == NULL && current2 == NULL){
        return 1;
    }
    return 0;
}
//Check whether the linked list is a palindrome or not
bool isLLaPalindromeorNot(List *head)
{
    List *fastptr, *slowptr;
    List *midnode;
    midnode = NULL;
    fastptr = head;
    slowptr = head;
    List *secondhead;
    secondhead = NULL;
    List *slowptrprev;
    int count = 0;

    while(fastptr != NULL )
    {
        fastptr = fastptr->next;
        if (fastptr == NULL) {
            // We have a odd sized list
            midnode = slowptr;
            slowptrprev->next = NULL;
            slowptr = slowptr->next;
            break;
        }
        fastptr = fastptr->next;
        slowptrprev = slowptr;
        slowptr = slowptr->next;
        count++;
    }



    secondhead = slowptr;
    slowptrprev->next = NULL;//first list

    secondhead = ReverseASingleLinkedList(secondhead);
    return compareLists(head,secondhead);
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
    //findMergePointinTwoLists(head1, head2);
   // findMergePointinTwoListsusingHashMap(head1,head2);
    //findMergePointinTwoListsusingStack(head1, head2);
    findmergePointinListsUsingEfficientmanner(head1, head2);


}
void linkedListsSortingProblem(){
    List *n1 = new List(90);
    List *n2 = new List(70, n1);
    List *n3 = new List(50, n2);
    List *n4 = new List(30, n3);
    List *n5 = new List(10, n4);
    List *head1 = n5;

    List *n6 = new List(80);
    List *n7 = new List(60,n6);
    List *n8 = new List(40,n7);
    List *n9 = new List(20,n8);
    List *head2 = n9;

    printList(head1);
    printList(head2);
    MergeTwoListofSortedOrderIntoThirdList(head1,head2);
    printList(head1);
}
void LinkedlistLoop()
{
    int value;
    int length;
    List *n1 = new List(10);
    List *n2 = new List(20, n1);
    List *n3 = new List(30, n2);
    List *n4 = new List(40, n3);
    List *n5 = new List(50, n4);
    List *n6 = new List(60, n5);
    List *n7 = new List(70, n6);
    List *n8 = new List(80, n7);
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
void  linkedListPalindromeTest() {
    int inputArray[] = {1,2,3,1,1};
    List* head = createSLL(inputArray, 5);
    printList(head);
    if(isLLaPalindromeorNot(head))
    {
        cout<<"The Linked list is a palindrome"<<endl;
    }
    else
    {
        cout<<"The linked list is not a palindrome"<<endl;
    }
    int inputArray1[] = {1,2,1,1};
    head = createSLL(inputArray1, 4);
    printList(head);
    if(isLLaPalindromeorNot(head))
    {
        cout<<"The Linked list1 is a palindrome"<<endl;
    }
    else
    {
        cout<<"The linked list1 is not a palindrome"<<endl;
    }

}
int main() {
    basicLinkedListOperations();
   linkedListsForkProblem();
    LinkedlistLoop();
    linkedListsSortingProblem();


    linkedListPalindromeTest();

    /*
     *    List **head1 = NULL;
     *    List **head2 = NULL;

            *head = createCLL(inputArray,8);
            printListCLL(head);
            SplittingCLL(head,head1, head2);
            printListCLL(head1);
            printListCLL(head2);
     */

    //head = ReverseLinkedListPair(head);
   // printList(head);
    //isLinkedListEvenorOddE(head);
    //isLinkedListEvenorOdd(head);
    //DisplayLinkedListFromEnd(head);
    //FindMiddleofLinkedListE(head);
    //FindMiddleofLinkedListusingHashmap(head);
    //FindMiddleofLinkedList(head);
    //head =  insertANodeinSortedList(head,15);
   // printList(head);
    return 0;
}

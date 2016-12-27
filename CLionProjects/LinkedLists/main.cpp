#include "LinkedList.h"
List::List() {
    value = -1;
    next = NULL;
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
void basicLinkedListOperations() {
    List *n1 = new List(10);
    List *n2 = new List(20, n1);
    List *n3 = new List(30, n2);
    List *n4 = new List(40, n3);
    List *n5 = new List(40, n3);
    List *head = n5;
    head = insertAtHead(head, 50);
    head = insertAtPos(head, 1, 60);
    printList(head);

    head = deleteANode(head,5);
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

int main() {
        //basicLinkedListOperations();
        linkedListsForkProblem();

        return 0;
    }


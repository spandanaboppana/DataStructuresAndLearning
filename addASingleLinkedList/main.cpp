#include <iostream>
#include <vector>
using namespace std;
class list {
public:
    list() : _next(nullptr), _data(0) {}
    list(list *next) : _next(next), _data(0) {}
    list(list *next, int d) : _next(next), _data(d) {}
    list(int d) : _next(nullptr), _data(d) {}

    void print() { cout << _data << " "; }
    list* _next;
    int _data;
};
list* makeSLL(vector<int> input)
{
    list *head = nullptr;
    list *returnPtr = nullptr;
    if (input.size() == 0) return nullptr;

    head =  new list(input[0]);
    returnPtr = head;

    for (int i = 1; i < input.size(); i ++) {
        head->_next =  new list(input[i]);
        head = head->_next;
    }
    return returnPtr;
}
void printList(list* head) {
    while (head != nullptr) {
        head->print();
        head = head->_next;
    }
    cout << endl;
}
list* reverse(list* head) {
    list *prev, *next;
    prev = nullptr;
    if (head == nullptr || head -> _next  == nullptr) return head;
    while  (head != nullptr) {
        next = head -> _next;
        head -> _next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
list* addlists(list* number1, list* number2);

list* addlists(list* number1, list* number2){
    number1 = reverse(number1);
    number2 = reverse(number2);
    printList(number1);
    printList(number2);
    list* result = new list(0);
    list* head_result = result;
    int carry = 0;
    int result_val;

    int sum = 0;
    while(number1 != NULL ||  number2!= NULL){

        int x = (number1 != NULL) ? number1->_data : 0;
        int y = (number2 != NULL) ? number2->_data : 0;
        sum = carry + x + y;

        carry = sum/10;
        result_val = sum%10;

        result->_next = new list(result_val);
        result = result->_next;

        if(number1 != NULL) number1= number1->_next;
        if(number2 != NULL) number2 = number2->_next;
    }

    if(carry > 0){
        result->_next = new list(carry);
    }
    return reverse(head_result->_next);

}
list* addlistsRecursive(list* number1, list* number2) {

}

bool checkLists(list* n1, list* n2) {
    if (n1 == nullptr && n2 == nullptr) return true;
    if (n1 == nullptr || n2 == nullptr) return false;
    if (n1 -> _data != n2 -> _data) return false;
    return (checkLists(n1->_next, n2->_next));
}
int main()
{
    list* number1 = makeSLL({9,5,9});
    list* number2 = makeSLL({7,5,7,0});

    list* requiredResult = makeSLL({8,5,2,9});
    list* result = addlists(number1, number2);
    printList(result);
    assert(checkLists(requiredResult,result));
    cout << "PASSED";
    return 0;
}

/*
 * number1 -    The number one in the form of a single linked list.
 *              Example 959 will be represented as 9 -> 5 -> 9 ->  NULL
 * number2 -    The number two in the form of a single linked list.
 *              Example 7570 will be represented as 7 -> 5 -> 7 -> 0 -> NULL
 * result =     number1 + number2;
 *              959 + 7570 = 8529
 *              Therefore the resultant list will be 8 -> 5 -> 2 -> 9  -> NULL
 *
 */

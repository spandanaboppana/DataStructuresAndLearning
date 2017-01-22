#include "stack.h"
void StackusingArrays()
{
    stackType<int> st(5);
    st.initializeStack();
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);
    st.Push(50);

    cout<<"The elements of stack in array are"<<endl;
    while(!st.isEmptyStack())
    {
        cout<<st.Top()<<" ";
        st.Pop();

    }

    cout <<endl;

}
void StacksusingLinkedLists()
{
    linkedStackType<int> lst;
    lst.initializeStack();
    lst.Push(10);
    lst.Push(20);
    lst.Push(30);
    lst.Push(40);
    lst.Push(50);

    cout<<"The elements of stack in linked list"<<endl;
    while(!lst.isEmptyStack())
    {
        cout<<lst.Top()<<" ";
        lst.Pop();
    }
    cout<<endl;
}

/*template <class Type>
struct advancedStack
{
    stackType<int> mainst();
    stackType<int> minst();
}AdvancedStack;
struct AdvancedStack* advancedStackFunc()
{
    AdvancedStack *as;
  //  int min;

    int A[5] = {2,6,4,1,5};
    AdvancedPush(as.mainst,as.minst,A);
    return as;

   // min = Getminimum(as.minst);
   // cout<<"The minimum number is "<<min;
}
void AdvancedPush(stackType<int> mainst, stackType<int> minst,int A[5])
{
    //stackType<int> mainst(5);
   // stackType<int> minst(5);

    for(int i=0;i<5;i++) {
        mainst.Push(A[i]);
        if (minst.Top() < A[i]) {
            minst.Push(minst.Top());
        } else {
            minst.Push(A[i]);
        }
    }
}

void AdvancedPop(stackType<int> mainst, stackType<int> minst){
    //
    //stackType<int> minst(5);
    int temp;
    if(mainst.isEmptyStack())
    {
        cout<<"The stack is empty";
    }
    else
    {
        mainst.Pop();
        minst.Pop();
    }
}
//Design a Stack such that GetMinimum() should be O(1)
int Getminimum(stackType<int> minst)
{
    return minst.Top();
}
*/
//Given an array of characters a and b,The string is marked with special character X,which represent the middle of list,check whether the string is palindrome or not
bool isPalindrome()
{
    char *A = "aaabaaXaaabaaa";
int i, j;
    i= 0;
    j = strlen(A)-1;
    while(i<j && A[i]==A[j])
    {
        i++;
        j--;
    }
    if(i<j)
    {
        cout<<"The string is not a palindrome";
    }
    else
    {
        cout<<"The string is a palindrome";
    }
}
//The above palindrome problem using stacks
bool isPalindromeusingStacks() {
    char *A = "aaabaaaXaaabaaa";
    int i = 0;
    // int j=0;
    stackType<char> st(0);
    while (A[i] != 'X') {
        st.Push(A[i]);

        i++;
    }
    i = i + 1;
    while(A[i] || ((st.isEmptyStack()) == 0))
    {
        if(A[i])
        {
            if(st.Top() == A[i])
            {
                st.Pop();
                i++;
            }
            else
            {

                cout<<"The string is not a palindrome"<<endl;
                return 0;
            }
        }
        else
        {
            if(st.isEmptyStack() == 0)
            {

                cout<<"The string is not a palindrome"<<endl;
                return 0;
            }
        }

    }
    cout<<"The string is Palindrome"<<endl;
    return 1;
}

//Reversing the elements of a stack using Push and Pop Operations
void ReversetheElementsofStackusingPushandPop()
{
    linkedStackType<int> lst;
    linkedStackType<int> rlst;
    int temp1;
    int temp2;
    lst.Push(10);
    lst.Push(20);
    lst.Push(30);
    lst.Push(40);
    lst.Push(50);

    while(!lst.isEmptyStack())
    {
        int temp1 = lst.Top();
        rlst.Push(temp1);
        lst.Pop();
    }
    while(!rlst.isEmptyStack())
    {
        temp2 = rlst.Top();
        rlst.Pop();
        cout<<temp2 <<" ";

    }
}


//Implementing two stacks using only one array
void twoStacksusingOneArray()
{
    twoStacks ts(5);
    ts.Push1(10);
    ts.Push1(20);
    ts.Push2(30);
    ts.Push2(40);
    ts.Push1(50);

    ts.Top1();
    cout<<"The element popped from stack1"<<" "<<ts.Top1()<<endl;
    ts.Pop1();
    cout<<"The element popped from stack1"<<" "<<ts.Top1()<<endl;
    ts.Pop1();
    cout<<"The element popped from stack2"<<" "<<ts.Top2()<<endl;
    ts.Pop2();
    cout<<"The element popped from stack2"<<" "<<ts.Top2()<<endl;
    ts.Pop2();

}

//Implementing three stacks using only one array
void threeStacksusingOneArray()
{

}
int main() {
    //StackusingArrays();
    //StacksusingLinkedLists();
    //isPalindrome();
    //isPalindromeusingStacks();
    //ReversetheElementsofStackusingPushandPop();
    twoStacksusingOneArray();
    return 0;
}


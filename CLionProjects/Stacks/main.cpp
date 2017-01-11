#include "stack.h"
int main() {
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
    return 0;
}


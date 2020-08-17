#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Tree {
public:
    Tree(int d) : _data(d), _left(nullptr), _right(nullptr) {}
    Tree(int d, Tree *l, Tree *r) : _data(d), _left(l), _right(r) {}
    void show() {
        cout << _data << " ";
    }
    Tree* Left() const {return _left;}
    void setLeft(Tree *l) { _left = l; }
    Tree* Right() const {return _right;}
    int Data() const {return _data;}
    void setRight(Tree *r) { _right = r; }
private:
    int _data;
    Tree *_left;
    Tree *_right;

};

Tree* makeTree_internal(vector<int> input, int low, int high)
{
    if (low == high) return new Tree(input[low]);
    if (low < high) {
        int mid = (low + high) / 2;
        Tree *root = new Tree(input[mid]);
        root->setLeft(makeTree_internal(input, low, mid - 1));
        root->setRight( makeTree_internal(input, mid+1, high));
        return root;
    } else {
        return NULL;
    }
}
Tree* makeTree(vector<int> input) {
    return makeTree_internal(input, 0, input.size()-1);
}
void inOrder_(Tree *root)
{
    if (root == NULL) return;
    inOrder_(root->Left());
    root->show();
    inOrder_(root->Right());
}
void inOrderNonRecursive(Tree *root);
void preOrderNonRecursive(Tree *root);
void postOrderNonRecursive(Tree *root);
void levelOrder(Tree *root);
Tree* inorderSuccessor(Tree *root);
Tree* LCA(Tree *root, Tree *alpha, Tree *beta);
bool compareTrees(Tree* t1, Tree*t2);
bool subtree(Tree* t1, Tree*t2);
void inOrder(Tree *root) {
    inOrder_(root);
    cout << endl;
}
/*
 * Creating this tree for all our problems

               1
          /             \
       2                 3
    /    \           /      \
  4       5        6         7
/  \     / \      / \      /  \
8  9    10 11    12 13    14   5

 // 8 4 9 2 10 5 11 1 12 6 13 3 14 7 5
*/
int main()
{
    {
        Tree *root = makeTree({8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 5});
        Tree *node3 = root->Right();
        Tree *node13 = root->Right()->Left()->Right();
        Tree *node14 = root->Right()->Right()->Left();
        //inOrder(root);
        //inOrderNonRecursive(root);
        //preOrderNonRecursive(root);
        //postOrderNonRecursive(root);
        //levelOrder(root);
        //compareTrees()
        //assert(inorderSuccessor(node3)->Data() == 14); // input is node 3
        //assert(inorderSuccessor(node13)->Data() == 3); // input is node 13
       // assert(LCA(root, node13, node14)->Data() == 3); // LCA of 13 and 14 is 3
    }
     {
        /*
         *          3
         *     6         7
         *  12  13    14   5
         */
        Tree *root = makeTree({12, 6, 13, 3, 14, 7, 5});
        Tree *rootSame = makeTree({12, 6, 13, 3, 14, 7, 5});
        assert(compareTrees(root, rootSame));
    }
     {
        /*
         *          3
         *     6         7
         *  12  13    14   5
         */
        Tree *subsetTree = makeTree({12, 6, 13, 3, 14, 7, 5});
        Tree *mainTree = makeTree({8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 5});
        assert(subtree(mainTree, subsetTree));
    }
        return 0;
}

Tree* LCA(Tree *root, Tree *alpha, Tree *beta) {
    return nullptr;
}

void inOrderNonRecursive(Tree *root)
{
    vector<int>result;
    stack<Tree*> mystack;

    Tree *curr = root;
    while(curr != NULL || !mystack.empty() ) {
        while(curr != NULL) {
            mystack.push(curr);
            curr =  curr->Left();
        }
        curr = mystack.top();
        result.push_back(curr->Data());
        mystack.pop();
        curr = curr->Right();
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i] << " ";
    }
}
void preOrderNonRecursive(Tree *root)
{
    Tree *curr = root;
    stack<Tree*> mystack;
    vector<int>result;

    mystack.push(root);

    while(!mystack.empty()){
        Tree* val = mystack.top();
        result.push_back(val->Data());
        mystack.pop();
        
        if(val->Right()) mystack.push(val->Right());
        if(val->Left()) mystack.push(val->Left());
    }


    for(int i=0;i<result.size();i++){
        cout<<result[i] << " ";
    }
}
void postOrderNonRecursive(Tree *root)
{
    Tree *curr = root;
    stack<Tree*> mystack;
    vector<int>result;

    mystack.push(root);

    while(!mystack.empty()){
        Tree *val = mystack.top();
        result.push_back(val->Data());
        mystack.pop();

        if(val->Left()) mystack.push(val->Left());
        if(val->Right()) mystack.push(val->Right());
    }

    for(int i=result.size()-1;i >= 0;i--){
        cout<<result[i] << " ";
    }


}
void levelOrder(Tree *root)
{
    queue <Tree*> myqueue;
    vector<int> result;
    myqueue.push(root);

    while(!myqueue.empty()) {

        Tree* val = myqueue.front();
        result.push_back(val->Data());

        myqueue.pop();

        if(val->Left()) myqueue.push(val->Left());
        if(val->Right()) myqueue.push(val->Right());

    }

    for(int i =0; i<result.size();i++){
        cout<<result[i]<< " ";
    }

}

bool compareTrees(Tree* t1, Tree*t2) {

    if(t1 == NULL && t2 == NULL)
        return true;

    if(t1 == NULL || t2 == NULL){
        return false;
    }

    if(t1->Data() != t2->Data()){
        return false;
    }

    bool tree_left = compareTrees(t1->Left(), t2->Left());
    bool tree_right = compareTrees(t2->Right(), t2->Right());

    return (tree_left && tree_right);

}
bool subtree(Tree* t1, Tree*t2) {

}

Tree* inorderSuccessor(Tree *root, Tree *node) {
    return nullptr;
}
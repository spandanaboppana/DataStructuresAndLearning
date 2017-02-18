#include "tree.h"
using namespace std;
Tree* CreateSampleCompleteTree() {
    Tree *Llc = new Tree(4);
    Tree *Lrc = new Tree(5);
    Tree *Lb = new Tree(2,Llc,Lrc);
    Tree *Rlc = new Tree(6);
    Tree *Rrc = new Tree(7);
    Tree *rb = new Tree(3,Rlc,Rrc);
    Tree *Root = new Tree(1,Lb, rb);
    return Root;
}
void inOrderRec(Tree *root){
    if(root==NULL) return;

    inOrderRec(root->getLeft());
    root->show();
    inOrderRec(root->getRight());

}
void preOrderRec(Tree *root){
    if(root==NULL) return;
    root->show();
    preOrderRec(root->getLeft());
    preOrderRec(root->getRight());

}

void postOrderRec(Tree *root){
    if(root==NULL) return;

    postOrderRec(root->getLeft());
    postOrderRec(root->getRight());
    root->show();
}

void inOrderIt(Tree *root){
    Tree *current;
    current = root;
    stack<Tree*> treestack;


    while(current != NULL || !treestack.empty())
    {
        if(current != NULL)
        {
            treestack.push(current);
            current = current->getLeft();
        }
        else
        {
            current = treestack.top();
            current->show();
            treestack.pop();
            current = current->getRight();
        }

    }

}
void preOrderIt(Tree *root){
    Tree *current;
    current = root;
    stack<Tree*> treestack;
    while(!treestack.empty() || current!= NULL)
    {
        if(current!= NULL)
        {
            current->show();
            treestack.push(current);
            current = current->getLeft();
        }
        else
        {
            current = treestack.top();
            treestack.pop();
            current = current->getRight();
        }

    }

}
void postOrderIt(Tree *root)
{
    Tree *current;
    current = root;
    stack<Tree*> treestack;
    stack<int> flagstack;
    int v=0;
    if(current == NULL)return;
    if(current!= NULL)
    {
        treestack.push(current);
        v=1;
        flagstack.push(v);
        current = current->getLeft();
    }
    while(!treestack.empty())
    {
        if(current!=NULL && v==0)           //this condition executes when current is at root
        {
            treestack.push(current);
            flagstack.push(v=1);
            current = current->getLeft();
        }
        else
        {
            current = treestack.top();
            treestack.pop();
            v= flagstack.top();
            flagstack.pop();
            if(v==1)                    //this condition executes when after the left node traversal is done
            {
                treestack.push(current);
                flagstack.push(v=2);
                current = current->getRight();
                v=0;
            }
            else
            {
                current->show();
            }
        }
    }
}

Tree* insertIntoABinaryTree(Tree *root, int d) {
    queue<Tree*> store;
    Tree *temp;
    Tree *newNode;
    newNode = new Tree(d);

    if(root == NULL)
    {
        return newNode;
    }
    store.push(root);
    while(!store.empty())
    {
        temp = store.front();
        store.pop();
        temp->show();
        if(temp->getLeft() != NULL)
        {
            store.push(temp->getLeft());
        } else {
            temp->setLeft(newNode);
            return root;
        }
        if(temp->getRight()!=NULL)
        {
            store.push(temp->getRight());
        } else {
            temp->setRight(newNode);
            return root;
        }
    }
}

int heightOfATree(Tree *root) {

if(root==NULL)
{
    return 0;

}
else
{
    return 1 + max(heightOfATree(root->getLeft()),heightOfATree(root->getRight()));
}
}

int heightOfaTreeWithoutRec(Tree *root){
    Tree *temp;
    int level=0;
    queue<Tree*> qStore;

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        qStore.push(root);
    }
    while(!qStore.empty())
    {
        temp = qStore.front();
        qStore.pop();
        if(temp->getLeft()!=NULL)
        {
            qStore.push(temp->getLeft());
        }
        if(temp->getRight()!=NULL)
        {
            qStore.push(temp->getRight());
        }
        if(temp->getLeft()!=NULL || temp->getRight()!=NULL)
        {
            level++;
        }
    }
    return level;
}

int numberOfNodesInATreeRecursive(Tree* root) {
    if(root == NULL)
        return 0;
    else
    {
        return 1+ numberOfNodesInATreeRecursive(root->getLeft())+ numberOfNodesInATreeRecursive(root->getRight());
    }
}

int numberOfNodesInATreeIterative(Tree* root) {
queue<Tree*> store;
    Tree* temp;
    int count=0;
    store.push(root);
    if(root== NULL)
    {
        return 0;
    }
    else
    {
        while(!store.empty()) {
            temp = store.front();
            store.pop();
            count = count + 1;
            if (temp->getLeft() != NULL) {
                store.push(temp->getLeft());
            }
            if (temp->getRight() != NULL) {
                store.push(temp->getRight());
            }
        }

    }
    return count;
}

bool searchInABinaryTreeRe(Tree* root, int value) {
    int temp;
   if(root== NULL)
   {
       return 0;
   }
    else
   {
       if(value == root->getData())
       {
           return 1;
       }
       else
       {
           temp = searchInABinaryTreeRe(root->getLeft(),value);
           if(temp!=0)
           {
               return temp;
           }
           else
           {
               return(searchInABinaryTreeRe(root->getRight(),value));
           }
       }

   }
    return 0;
}

bool searchInABinaryTreeIte(Tree* root,int value){
    queue<Tree*> store;

    Tree* temp;
    if(root==NULL)
        return false;
    else
        store.push(root);

        while(!store.empty()) {
            temp = store.front();
            if (temp->getData() == value) {
                return true;
            }
            store.pop();
            if (temp->getLeft() != NULL) {
                store.push(temp->getLeft());
            }
            if (temp->getRight() != NULL) {
                store.push(temp->getRight());
            }
        }
    return false;
}



int numberOfLeafNodes(Tree* root) {
    queue<Tree*> store;
    store.push(root);
    Tree* temp;
    int count=0;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        while(!store.empty())
        {
        temp = store.front();
        store.pop();
        if(temp->getLeft()==NULL && temp->getRight()==NULL)
        {
            count++;
        }
        else
        {

                if(temp->getLeft()!=NULL)
                {
                    store.push(temp->getLeft());
                }
                if(temp->getRight()!=NULL)
                {
                    store.push(temp->getRight());
                }
        }
        }
    }
    return count;

}

//Mirror of a tree is nothing but all left and right children are being interchanges.
Tree* mirrorOfATree(Tree *root) {
    Tree* current;
    current =root;
    Tree* temp;
    if(current==NULL)
    {
        return 0;
    } else{
        mirrorOfATree(current->getLeft());
        mirrorOfATree(current->getRight());
        temp = current->getLeft();
        current->setLeft(current->getRight());
        current->setRight(temp);
    }
    return root;
}

bool isAMirror(Tree* r1, Tree*r2) {
    if(r1==NULL && r2==NULL)
    {
        return 1;
    }
    if(r1==NULL || r2==NULL)
    {
        return 0;
    }
    if(r1->getData()!=r2->getData())
    {
        return 0;
    }
    else
    {
        return isAMirror(r1->getLeft(),r2->getRight()) && isAMirror(r1->getRight(),r2->getLeft());
    }
}

void printAllRootToLeafPaths(Tree *root) {
    queue<Tree*> store;
    store.push(root);
    Tree* temp;
    if(root==NULL)
    {
        return;
    }
    else
    {
        while(!store.empty())
        {
            temp = store.front();
            store.pop();
            if(temp->getLeft() !=NULL && temp->getRight() !=NULL){
                temp->show();
            }
            if(temp->getLeft()!=NULL)
            {
                store.push(temp->getLeft());
            }
            if(temp->getRight()!=NULL)
            {
                store.push(temp->getRight());
            }
        }
    }

}

//node, in which path diverge into two branches.
Tree* FindLCA(Tree *root,Tree *node1, Tree* node2) {
    if(root==NULL)
    {
        return 0;
    }
    if(root == node1 || root == node2)
    {
        return root;
    }

    Tree *left = FindLCA(root->getLeft(),node1,node2);
    Tree *right = FindLCA(root->getRight(),node1,node2);
    if(left != NULL && right != NULL)
    {
        return root;
    }
    if(left == NULL && right==NULL)
    {
        return NULL;
    }


}
bool compareTwoTrees(Tree* r1, Tree*r2) {

}

void levelOrder(Tree *root){
queue<Tree*> store;
    Tree* temp;
    if(root == NULL)return;
    store.push(root);

    while(!store.empty())
    {
        temp = store.front();
        store.pop();
        temp->show();
        if(temp->getLeft()!= NULL)
        {
            store.push(temp->getLeft());
        }
        if(temp->getRight()!=NULL)
        {
            store.push(temp->getRight());
        }

    }

}

int findingMaxElementinBinaryTreeRec(Tree *root)
{

    int maxFlag=INT_MIN;

    if(root!=NULL)
    {
       maxFlag = max(root->getData(),max(findingMaxElementinBinaryTreeRec(root->getLeft()),findingMaxElementinBinaryTreeRec(root->getRight())));
    }
    return maxFlag;

}
int findingMaxElementinBinaryTreeIte(Tree *root){
    int maxFlag = INT_MIN;
    Tree *temp;

    queue<Tree*> qStore;
    if(root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        qStore.push(root);
    }
    while(!qStore.empty())
    {

       temp = qStore.front();
        qStore.pop();
        if(temp->getData() > maxFlag)
        {
            maxFlag = temp->getData();
        }
        if(temp->getLeft()!=NULL)
        {
            qStore.push(temp->getLeft());
        }
        if(temp->getRight()!=NULL)
        {
            qStore.push(temp->getRight());
        }

    }
    return maxFlag;

}

void reverseABinaryTree(Tree *root){
    queue<Tree*> qStore;
    stack<Tree*> qStack;
    Tree *temp;
    if(root == NULL)
    {
        return;
    }
    else
    {
        qStore.push(root);
    }
    while(!qStore.empty())
    {
        temp = qStore.front();
        qStore.pop();
        qStack.push(temp);
        if(temp->getLeft()!=NULL)
        {
            qStack.push(temp->getLeft());
        }
        if(temp->getRight()!=NULL)
        {
            qStack.push(temp->getRight());
        }

    }

    while(!qStack.empty())
    {
        temp = qStack.top();
        qStack.pop();
        cout<< temp->getData();
    }
}

//For deleting a tree first we have to delete its parents
void deleteABinaryTree(Tree *root){
   if(root == NULL)
   {
       return;
   }
    else
   {
       deleteABinaryTree(root->getLeft());
       deleteABinaryTree(root->getRight());
       free(root);
   }
}
//Finding the deepest node in a binary tree
Tree* findingDeepestNode(Tree *root)
{
    Tree* temp;
    queue<Tree*> qStore;

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        qStore.push(root);
    }
    while(!qStore.empty())
    {
        temp = qStore.front();
        qStore.pop();
        if(temp->getLeft()!=NULL)
        {
            qStore.push(temp->getLeft());
        }
        if(temp->getRight()!=NULL)
        {
            qStore.push(temp->getRight());
        }
    }
    return temp;

}

//Deleting a Element from Binary Tree
//void deleteAnElementFromBinaryTree(Tree *root){
   // Tree *temp;

//}
int main() {
    Tree *root = CreateSampleCompleteTree();
    bool temp;
    int maxValue;
    Tree *temp2;
    cout<<"Inorder : " ; inOrderRec(root); cout <<endl;
    cout<<"preorder : " ; preOrderRec(root); cout <<endl;
    cout<<"postOrder : " ; postOrderRec(root); cout <<endl;
    cout<<"LevelOrder: " ; levelOrder(root);cout <<endl;
    cout<<"InorderIte: " ; inOrderIt(root);cout<<endl;
    cout<<"PreorderIte: "; preOrderIt(root);cout<<endl;
   // cout<<"PostorderIte: "; postOrderIt(root);cout<<endl;
   // cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,8);cout<<endl;
   // cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,9);cout<<endl;
   // cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,10);cout<<endl;
   // cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,11);cout<<endl;
   // cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,12);cout<<endl;
  //  cout<<"InsertinaBinaryTree" ;root = insertIntoABinaryTree(root,13);cout<<endl;
  //  cout<<"LevelOrder: " ; levelOrder(root);cout <<endl;
    cout<<"height of Tree:"<<heightOfATree(root);cout<<endl;
    cout<<"height of a Tree without recursive:"<<heightOfaTreeWithoutRec(root);cout<<endl;
    //cout<<"numberofNodes:" << numberOfNodesInATreeRecursive(root);
    //cout<<"numberofnodesinaTreeinIter"<<numberOfNodesInATreeIterative(root);
    temp = searchInABinaryTreeIte(root,9);cout<<endl;
    cout<<"searchInABinaryTreeIte:"<<temp;
    cout<<endl;
    cout<<"numberofLeafsinBinaryTree:"<<numberOfLeafNodes(root);
    cout<<endl;
   // cout<<"Mirror of Binary Tree";mirrorOfATree(root);cout<<endl;
   // cout<<"Inorder : ";inOrderRec(root); cout <<endl;
   // cout<<"printAllRootToLeafPaths";
   // printAllRootToLeafPaths(root);
    cout<<endl;
    //findingMaxElementinBinaryTree(root);
    cout<<"MaxElementinaBinaryTree:"<<findingMaxElementinBinaryTreeRec(root);
    cout<<endl;
    cout<<"maxElementinaBinaryTreewithoutRecu:"<<findingMaxElementinBinaryTreeIte(root);
    cout<<endl;
    //cout<<"Reverse a Binary Tree";
    cout<<endl;
   // reverseABinaryTree(root);
    cout<<endl;
    temp2=findingDeepestNode(root);
    cout<<"Finding the deepest node:"<<temp2->getData();



    return 0;
}
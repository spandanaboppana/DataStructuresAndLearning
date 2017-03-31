#include "tree.h"

using namespace std;
BinarySTree* CreateSampleBST();
void binarySearchTreeTests();

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
    Tree* temp;
    if(root ==NULL)
    {
        return root;
    } else{
        temp = mirrorOfATree(root->getLeft());
        root->setLeft(root->getRight());
        root->setRight(temp);
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

void printPath(int path[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<path[i];
    }
}

void printAllRootToLeafPaths(Tree *root, int path[],int pathLen) {
    if(root == NULL)
    {
        return;
    }
    path[pathLen]= root->getData();
    pathLen++;

    if(root->getLeft()== NULL && root->getRight()==NULL)
    {
        printPath(path,pathLen);
    }
    else
    {
        printAllRootToLeafPaths(root->getLeft(),path,pathLen);
        printAllRootToLeafPaths(root->getRight(),path,pathLen);
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
void deleteAnElementFromBinaryTree(Tree *root, int data){
    Tree *temp;
    queue<Tree*> qStore;
    int val;
    if(root==NULL)
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
        if(temp->getData() == data)
        {
            val = temp->getData();
        }
        if(temp->getLeft() != NULL)
        {
           qStore.push(temp->getLeft());
        }
        if(temp->getRight() != NULL)
        {
            qStore.push(temp->getRight());
        }

    }



}

//Checking whether trees are structurally identical or not
bool areBothTreeStructurallyIdentical(Tree *root1, Tree *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
       return false;
    if(root1->getData() != root2->getData())
        return false;
    return(areBothTreeStructurallyIdentical(root1->getLeft(),root2->getLeft()) && areBothTreeStructurallyIdentical(root1->getRight(),root2->getRight()));
}

//finding the diameter of a binary tree
int findDiameter(Tree *root, int *h)
{
    int lh=0;
    int rh=0;

    int ldiameter=0;
    int rdiameter=0;

    if(root==NULL)
    {

        *h=0;
        return 0;
    }

    ldiameter = findDiameter(root->getLeft(), &lh);
    rdiameter = findDiameter(root->getRight(), &rh);

    *h = (max(lh,rh)+1);

    return max(lh+rh+1, max(ldiameter,rdiameter));
}

//Finding a level which is having max sum in Binary Tree
int findLevelWithMaxSum(Tree *root)
{
    queue<Tree*> qStore;
    int count;
    int sum;
    Tree *temp;
    int result;
    int maxlevel;
    int currentLevel = 0;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        qStore.push(root);
        result = root->getData();
    }

    while(!qStore.empty())
    {
        count = qStore.size();
        currentLevel++;
        sum=0;
        while(count--)
        {
           temp= qStore.front();
            qStore.pop();

            sum= sum+temp->getData();

            if(temp->getLeft()!=NULL)
            {
                qStore.push(temp->getLeft());
            }
            if(temp->getRight()!=NULL)
            {
                qStore.push(temp->getRight());
            }
        }

        if(sum >= result)
        {
            maxlevel = currentLevel;
            result = sum;
        }

    }
    return maxlevel;
}

//Finding a path in tree for given sum from root to any node is there or not
bool isPathExistsForGivenSum(Tree *root, int sum)
{
    if(root == NULL)
    {
        return (sum == 0);
    }
    if(sum == root->getData())
    {
        return 1;
    }
    if(root->getData() > sum)
    {
        return 0;
    }
    return (root->getLeft(),sum-root->getData() || root->getRight(),sum-root->getData());
}

//Finding the ancestors for a given node
bool findAncestorsOfANode(Tree *root, int node)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->getData() == node)
    {
        return true;
    }

    if( findAncestorsOfANode(root->getLeft(),node) || findAncestorsOfANode(root->getRight(),node))
    {
        cout<<root->getData()<<" ";
        return true;
    }
    return false;

}

//ZigZag Tree Traversal
void zigZagTreeTraversal(Tree *root)
{
    Tree *temp1;
    Tree *temp2;
    if(root == NULL)
    {
        return;
    }

    stack<Tree*> s1; //from right to left
    stack<Tree*> s2; // from left to right

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {

        while(!s1.empty())
        {
            temp1 = s1.top();
            s1.pop();

            cout<<temp1->getData();

            //Here right is pushed before left
            if(temp1->getRight())
            {
                s2.push(temp1->getRight());
            }
            if(temp1->getLeft())
            {
                s2.push(temp1->getLeft());
            }
        }

        while(!s2.empty())
        {
            temp2 = s2.top();
            s2.pop();

            cout<<temp2->getData();

            if(temp2->getLeft())
            {
                s1.push(temp2->getLeft());
            }
            if(temp2->getLeft())
            {
                s1.push(temp2->getRight());
            }
        }
    }



}

void PostOrder(Tree *root)
{
    if(root == NULL)
        return;
    stack<Tree*> qStack;
    while(1)
    {
        while(root != NULL)
        {
            qStack.push(root);
            root = root->getLeft();
        }
        if(qStack.empty())
        {
            break;
        }
        root = qStack.top();
        qStack.pop();

        if(root->visited == 0){
            root->visited = 1;
            qStack.push(root);
            root = root->getRight();
        }else{
            cout<<root->getData();
            root = NULL;
        }

    }
}

void postOrdertest()
{
    Tree *root = CreateSampleCompleteTree();
    PostOrder(root);
}

//binary tree with three pointers
void binaryTreeWithThreePointers(Tree *root)
{
    if(root == NULL)
    {
        return;
    } else{
        queue<Tree *> qStore;


    }
}

void findLevelWithMaxSumTest() {
    Tree *root = CreateSampleCompleteTree();
    root->getLeft()->setData(400);
    cout<<"Max sum level:"<<findLevelWithMaxSum(root);
}

void findDiameterTest()
{
    Tree *root=CreateSampleCompleteTree();
    int height=0;
    cout<<"Diameter of Tree is "<< findDiameter(root,&height);
}
void printAllRootToLeafPathsTest() {
    cout<<"\nprintAllRootToLeafPaths";
    Tree *root = CreateSampleCompleteTree();
    int *store = new int[10];
    memset(store,0,10);
    printAllRootToLeafPaths(root, store, 0);
    delete store;
}

void twoTrees(){
    Tree *root1 = CreateSampleCompleteTree();
    Tree *root2 = CreateSampleCompleteTree();
    root2->getRight()->setData(4);
    cout<<"Are Trees structurally identical "<<(areBothTreeStructurallyIdentical(root1,root2) ? "Yes" : "No");
}

void zigZagTreeTraversalTest()
{
    Tree *root = CreateSampleCompleteTree();
    cout<<"\nPrinting zigzag Traversal ";
    zigZagTreeTraversal(root);
}
void ancestorsTest()
{
    Tree *root = CreateSampleCompleteTree();
    cout<<"Printing all ancestors ";
    findAncestorsOfANode(root, 7);
}

void binaryTreeTests() {
    bool temp;
    int maxValue;
    Tree *temp2;
    Tree *root = CreateSampleCompleteTree();
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
    cout<<"Mirror of Binary Tree";mirrorOfATree(root);cout<<endl;
    // cout<<"Inorder : ";inOrderRec(root); cout <<endl;
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
    printAllRootToLeafPathsTest();
    cout<<endl;
    twoTrees();
    cout<<endl;
    findDiameterTest();
    cout<<endl;
    findLevelWithMaxSumTest();
    cout<<endl;
    ancestorsTest();
    zigZagTreeTraversalTest();
}


int main() {
    // binarySearchTreeTests();
    postOrdertest();
    return 0;
}
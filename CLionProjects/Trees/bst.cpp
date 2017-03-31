//
// Created by Spandana Boppana on 3/11/17.
//

#include "tree.h"

BinarySTree* CreateSampleBST()
{
    BinarySTree *Llc = new BinarySTree(30);
    BinarySTree *Lrc = new BinarySTree(45);
    BinarySTree *Lb = new BinarySTree(40, Llc, Lrc);
    BinarySTree *Rlc = new BinarySTree(55);
    BinarySTree *Rrc = new BinarySTree(70);
    BinarySTree *Rb = new BinarySTree(60, Rlc, Rrc);
    BinarySTree *root = new BinarySTree(50,Lb,Rb);
    return root;
}

bool search(BinarySTree *root,int data)
{
    BinarySTree *current;
     if(root == NULL)
    {
        cout<<"Cannot search the tree the beacuse root doent exixts"<<endl;
        return false;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            if(current->getData() == data)
            {
                cout<<"Element exixts in Tree"<<endl;
                return true;
            }
            else if(current->getData() > data)
            {
                current = current->BinarySTree::getLeft();
            }
            else
            {
                current = current->BinarySTree::getRight();
            }
        }
    }
    cout<<"Element doesnt exixts in Tree "<<endl;
    return false;
}

void insert(BinarySTree *root, int data)
{
    BinarySTree *newNode;
    BinarySTree *current;
    BinarySTree *trailCurrent;
    newNode = new BinarySTree(data);
    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        current = root;
        while(current!=NULL)
        {
            trailCurrent = current;
            if(current->getData() == data)
            {
                cout<<"Cannot insert as data which is to be inserted is already present"<<endl;
                return;
            }
            else if(current->getData() > data)
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }

        }
        if(trailCurrent->getData() > data)
        {
            trailCurrent->setLeft(newNode);

        }
        else
        {
            trailCurrent->setRight(newNode);
        }

    }

}
void BSTSearch()
{
    BinarySTree *bstroot = CreateSampleBST();

    search(bstroot, 45);
}
void inOrderRec(BinarySTree *root){
    if(root==NULL) return;

    inOrderRec(root->getLeft());
    root->show();
    inOrderRec(root->getRight());

}
void PrintingaTree(BinarySTree *bstroot)
{
    cout<<"Inorder : " ; inOrderRec(bstroot); cout <<endl;
}
void deleteTree(BinarySTree *root, int data)
{
    BinarySTree *temp;// pointer to delete the node
    BinarySTree *current;//pointer to traverse the tree
    if(root == NULL)
    {
        cout<<"There is nothing to delete"<<endl;

    }
    else if(root->getLeft() == NULL && root->getRight() == NULL)
    {
        temp = root;
        root = NULL;
        delete temp;
    }
    else if(root->getLeft() == NULL)
    {
        temp = root;
        root = temp->getRight();
        delete temp;

    }
    else if(root->getRight() == NULL)
    {
        temp = root;
        root = temp->getLeft();
        delete temp;
    }
    else
    {

    }


}
void BSTInsert()
{
    BinarySTree *bstroot = CreateSampleBST();
    insert(bstroot, 90);
    PrintingaTree(bstroot);
}

void deleteTree()
{
    BinarySTree *bstroot = CreateSampleBST();
    deleteTree(bstroot, 50);
}



extern void binarySearchTreeTests() {

  //  BSTSearch();
    BSTInsert();


}




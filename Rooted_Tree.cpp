//
// Created by menib on 12/24/2019.
//

#include "Rooted_Tree.h"
using std::cout;
using std::endl;


void Rooted_Tree::findSize(Tree_Node* x){
    if(x==NULL){ return;}
    if(x==root){treeSize=1;}
    treeSize++;
    x=x->leftChild;
    while (x!=NULL){
        findSize(x);
        x=x->rightSibling;
    }
}
int Rooted_Tree::findHeight(Tree_Node * x) {
    if (x==NULL){return -1;}
    int max =0;
    int current=0;
    Tree_Node* i=x->leftChild;
    while(i!=NULL)
    {
        current=findHeight(i)+1;
        max=max<current?current:max;
        i=i->rightSibling;
    }
    x->height = max;
    return x->height;
}
void Rooted_Tree::Print_By_Layer(std::ostream &stream) const {
    Tree_Node* queue[treeSize];
    Tree_Node* currentChild;
    Tree_Node* x=root;
    if(x==NULL){ return;}
    int first=0;
    int last=0;
    queue[last]=x;
    last++;
    stream<<x->Get_key()<<'\n';
    while(queue[first]!=NULL)
    {
        currentChild=queue[first]->leftChild;
        while(currentChild!=NULL)
        {
            if(currentChild->leftChild!=NULL)
            {
                queue[last]=currentChild;
                last++;
            }
            stream<<currentChild->Get_key();
            if(currentChild->rightSibling!=NULL){stream<<',';}
            currentChild=currentChild->rightSibling;
        }
        if(queue[first+1]!=NULL) {
            if (queue[first]->height != queue[first + 1]->height) { stream << '\n'; }
            else { stream << ','; }
        }
        first++;
    }
}
void Rooted_Tree::Preorder_Print(std::ostream &stream) const {
    Tree_Node* queue[treeSize];
    Tree_Node* currentChild;
    Tree_Node* x=root;
    if(x==NULL){ return;}
    int first=0;
    int last=0;
    queue[last]=x;
    last++;
    stream<<x->Get_key()<<'\n';
    while(queue[first]!=NULL)
    {
        currentChild=queue[first]->leftChild;
        while(currentChild!=NULL)
        {
            if(currentChild->leftChild!=NULL)
            {
                queue[last]=currentChild;
                last++;
            }
            stream<<currentChild->Get_key();
            if(currentChild->rightSibling!=NULL){stream<<',';}
            currentChild=currentChild->rightSibling;
        }
        if(queue[first+1]!=NULL) {stream << ','; }
        first++;
    }
}
Rooted_Tree::~Rooted_Tree() {}
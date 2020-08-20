//
// Created by menib on 12/24/2019.
//

#ifndef DS_ALGS_ROOTED_TREE_H
#define DS_ALGS_ROOTED_TREE_H

#include "Graph_Node.h"
#include <iostream>

class Tree_Node:public Graph_Node{
public:
    Tree_Node(unsigned k,Tree_Node* p=NULL):Graph_Node(k),parent(p),leftChild(NULL),
        rightSibling(NULL),height(0){}
    Tree_Node(Graph_Node* node, Graph_Node* p=NULL):parent(p), leftChild(NULL),
        rightSibling(NULL),height(0){}
    void set_LeftChild(Graph_Node* lc){leftChild(Tree_Node(lc)};
    void set_Parent(Graph_Node* p){parent(Tree_Node(p)};
    void set_RightSibling(Graph_Node* rs){rightSibling(Tree_Node(rs))};

private:
    friend class Rooted_Tree;
    friend class Dynamic_Graph;
    Tree_Node* parent;
    Tree_Node* leftChild;
    Tree_Node* rightSibling;
    int height;
};

class Rooted_Tree {
public:
    Rooted_Tree(Tree_Node* r=NULL):root(r),treeSize(0){findSize(r);findHeight(r);}
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;
    Tree_Node* get_Root(){ return root;};
private:
    Tree_Node* root;
    int treeSize;
    int height;
    void findSize(Tree_Node*);
    int findHeight(Tree_Node*);
};


#endif //DS_ALGS_ROOTED_TREE_H

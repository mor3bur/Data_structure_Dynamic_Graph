//
// Created by menib on 12/24/2019.
//

#include "Dynamic_Graph.h"
using std::cout;

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node* newNode= new Graph_Node(node_key,lastGraphNode);
    if(firstGraphNode==NULL){
        firstGraphNode=newNode;
    }
    else{
        lastGraphNode->nextNode=newNode;
    }
    lastGraphNode=newNode;
    numNodes++;
    return newNode;
}
void Dynamic_Graph::Delete_Node(Graph_Node *node) {
    if(node==NULL){ return;}
    if(node->Get_out_Degree()!=0 || node->Get_in_Degree()!=0){return;}
    if(firstGraphNode==node){
        firstGraphNode=node->nextNode;
    }
    if(lastGraphNode==node){
        lastGraphNode=node->beforeNode;
    }
    delete(node);
    numNodes--;
}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node *from, Graph_Node *to) {
    Graph_Edge* newEdge=new Graph_Edge(from,to);
    if(from->firstOutEdge==NULL) {
        from->firstOutEdge = newEdge;
    }else{
        from->lastOutEdge->nextOutEdge=newEdge;
    }
    from->lastOutEdge=newEdge;

    if(to->firstInEdge==NULL) {
        to->firstInEdge = newEdge;
    }else{
        to->lastInEdge->nextInEdge=newEdge;
    }
    to->lastInEdge=newEdge;
    numEdges++;
    return newEdge;
}
void Dynamic_Graph::Delete_Edge(Graph_Edge *edge) {
    if(edge==NULL){ return;}

    if(edge->fromNode->firstOutEdge==edge){
        edge->fromNode->firstOutEdge=edge->nextOutEdge;
    }
    if(edge->fromNode->lastOutEdge==edge){
        edge->fromNode->lastOutEdge=edge->previousOutEdge;
    }
    if(edge->toNode->firstInEdge==edge){
        edge->toNode->firstInEdge=edge->nextInEdge;
    }
    if(edge->toNode->lastInEdge==edge){
        edge->toNode->lastInEdge=edge->previousInEdge;
    }
    delete(edge);
    numEdges--;
}
Dynamic_Graph::~Dynamic_Graph() {
    if(lastGraphNode==NULL){ return;}

    while (lastGraphNode!=NULL){

        while(lastGraphNode->lastOutEdge!=NULL || lastGraphNode->lastInEdge!=NULL){

            if(lastGraphNode->lastOutEdge!=NULL){

               Delete_Edge(lastGraphNode->lastOutEdge);
            }
           if(lastGraphNode->lastInEdge!=NULL){

               Delete_Edge(lastGraphNode->lastInEdge);
           }
        }
        Delete_Node(lastGraphNode);
    }
}
void Dynamic_Graph::Dfs() {
    Graph_Node* iter=firstGraphNode;
    while(iter!=NULL){
        iter->color=WHITE;
        iter->DFSpredecessor=NULL;
        iter=iter->nextNode;
    }
    int time=0;
    iter=lastGraphNode;
    while(iter!=NULL){
        if(iter->color==WHITE){Dfs_Visit(iter,time);}

        iter=iter->beforeNode;
    }
}
void Dynamic_Graph::Dfs_Visit(Graph_Node * current,int &time) {
    time++;
    current->discovery=time;
    current->color=GRAY;
    Graph_Edge* iter=current->lastOutEdge;
    while(iter!=NULL){
        Graph_Node* adj=iter->toNode;
        if(adj->color==WHITE){
            adj->DFSpredecessor=current;
            Dfs_Visit(adj,time);
        }
        iter=iter->previousOutEdge;
    }
    current->color=BLACK;
    time++;
    current->retraction=time;
}
void Dynamic_Graph::printDfs() {
    Dfs();
    Graph_Node* iter=firstGraphNode;
    while(iter!=NULL){
        cout<<iter->Get_key()<<" , discovered "<<iter->discovery<<" , predeccesor ";
        if(iter->DFSpredecessor!=NULL){cout<<iter->DFSpredecessor->Get_key();}else
        {cout<<"Null";}cout<<" , retracted "<<iter->retraction<<" , color "<<iter->color<<
        "\n";
        iter=iter->nextNode;
    }
}

Rooted_Tree* BFS_Initialization(const &Dynamic_Graph G, Graph_Node* source){
    Rooted_Tree* tree = new Rooted_Tree(Tree_Node(source));
    source->COLOR = GRAY;
    source->distance = 0;
    source->BFSpredecessor = NULL;
    return tree;
}

Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
    if (source=NULL){return ;}
    Tree_Node* queue[numNodes];
    unsigned first = 0;
    unsigned last = 0;
    Rooted_Tree* treeptr = BFS_Initialization(this, source);
    Tree_Node* currentNode, tempChild;
    Graph_Edge* currentEdge;
    Tree_Node* currentChild = NULL;
    queue[first]= treeptr->get_Root();
    last++;

    while (queue[first]!=NULL) {
        currentNode = queue[first];
        currentEdge = currentNode->firstOutEdge;
        while (currentNode->leftChild==NULL && currentEdge!=NULL){//first edge goes to leftChild
            if (currentEdge != NULL){
                if (currentEdge->toNode->color == WHITE) {
                    currentChild = new Tree_Node(currentEdge->toNode, currentNode);
                    currentChild->color = GRAY;
                    currentChild->distance = currentNode->distance + 1;
                    currentNode->set_LeftChild(currentChild);
                    if (currentChild->degreeOut > 0) {
                        queue[last] = currentChild; last++;
                    }
                    else {currentChild->color = BLACK;}
                }
                currentEdge = currentEdge->nextOutEdge;
            }
        }

        while (currentEdge != NULL) {
            if (currentEdge->toNode->color == WHITE) {
                tempChild = new Tree_Node(currentEdge->toNode, currentNode);
                currentChild->set_RightSibling(tempChild);
                tempChild->color = GRAY;
                tempChild->distance = currentNode->distance + 1;
                if (tempChild->degreeOut > 0) {
                    queue[last] = tempChild; last++;
                }
                else {tempChild->color = BLACK;}
                currentEdge = currentEdge->nextOutEdge;
                currentChild = tempChild;
            }
        }
        currentNode->color = BLACK;
        first++;
    }
    return treeptr;
}
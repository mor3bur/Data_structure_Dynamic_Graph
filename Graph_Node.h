//
// Created by menib on 12/24/2019.
//

#ifndef DS_ALGS_GRAPH_NODE_H
#define DS_ALGS_GRAPH_NODE_H

#include <cstddef>

class Graph_Edge;

typedef enum {WHITE, GRAY, BLACK} COLOR;

class Graph_Node {
public:

    Graph_Node(unsigned k,Graph_Node* pre=NULL):key(k),degreeOut(0),degreeIn(0),
    beforeNode(pre),nextNode(NULL),firstOutEdge(NULL),lastOutEdge(NULL),firstInEdge(NULL),
    lastInEdge(NULL),color(WHITE),distance(4294967295),BFSpredecessor(NULL),
    DFSpredecessor(NULL),discovery(0),retraction(0){}
    ~Graph_Node() {
        if (beforeNode != NULL) { beforeNode->nextNode = nextNode; }
        if (nextNode != NULL) { nextNode->beforeNode = beforeNode; }
    }
    unsigned Get_out_Degree() const{ return degreeOut;};
    unsigned Get_in_Degree() const { return degreeIn;};
    unsigned Get_key() const{ return key;};
    void Update_out_Degree(bool increase){increase?degreeOut++:degreeOut--;};
    void Update_in_Degree(bool increase){increase?degreeIn++:degreeIn--;};

//protected:
    unsigned key;
    unsigned degreeOut;
    unsigned degreeIn;
    Graph_Node* beforeNode;
    Graph_Node* nextNode;
    Graph_Edge* firstOutEdge;
    Graph_Edge* lastOutEdge;
    Graph_Edge* firstInEdge;
    Graph_Edge* lastInEdge;
    COLOR color ;
    unsigned distance;
    Graph_Node* DFSpredecessor;
    int discovery;
    int retraction;
    friend class Dynamic_Graph;
};

class Graph_Edge {
public:
    Graph_Edge(Graph_Node* f,Graph_Node* t,Graph_Edge* prevOut=NULL,Graph_Edge* prevIn=NULL):
    fromNode(f),toNode(t),previousOutEdge(prevOut),nextOutEdge(NULL),previousInEdge(prevIn),
    nextInEdge(NULL){
        f->Update_out_Degree(true);
        t->Update_in_Degree(true);
    }
    ~Graph_Edge(){
        fromNode->Update_out_Degree(false);
        toNode->Update_in_Degree(false);
        if(nextOutEdge!=NULL){nextOutEdge->previousOutEdge=previousOutEdge;}
        if(previousOutEdge!=NULL){previousOutEdge->nextOutEdge=nextOutEdge;}
        if(nextInEdge!=NULL){nextInEdge->previousInEdge=previousInEdge;}
        if(previousInEdge!=NULL){previousInEdge->nextInEdge=nextInEdge;}
    }
private:
    Graph_Node* fromNode;
    Graph_Node* toNode;
    Graph_Edge* previousOutEdge;
    Graph_Edge* nextOutEdge;
    Graph_Edge* previousInEdge;
    Graph_Edge* nextInEdge;
    friend class Dynamic_Graph;
};

#endif //DS_ALGS_GRAPH_NODE_H

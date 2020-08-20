//
// Created by menib on 12/24/2019.
//

#ifndef DS_ALGS_DYNAMIC_GRAPH_H
#define DS_ALGS_DYNAMIC_GRAPH_H

#include "Rooted_Tree.h"


class Dynamic_Graph {
public:
    Dynamic_Graph():firstGraphNode(NULL),lastGraphNode(NULL),numEdges(0),numNodes(0){}
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    void Dfs_Visit(Graph_Node*,int&);
    void Dfs();
    Rooted_Tree* BFS(Graph_Node* source) const;
    void printDfs();

private:
    Graph_Node* firstGraphNode;
    Graph_Node* lastGraphNode;
    int numEdges;
    int numNodes;
};


#endif //DS_ALGS_DYNAMIC_GRAPH_H

#include <iostream>
#include "Dynamic_Graph.h"
using namespace std;
int main() {
    Dynamic_Graph graph;
    Graph_Node* one=graph.Insert_Node(1);
    Graph_Node* two=graph.Insert_Node(2);
    Graph_Node* three=graph.Insert_Node(3);
    Graph_Edge* edgeone=graph.Insert_Edge(two,one);
    Graph_Edge* edgetwo=graph.Insert_Edge(three,one);
    cout<<one->Get_out_Degree()<<"\n"<<one->Get_in_Degree()<<"\n";
    cout<<two->Get_in_Degree()<<"\n";
cout<<one->nextNode->key<<"\n";
graph.printDfs();
    return 0;
}
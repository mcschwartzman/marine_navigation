#include "Graph.h"

using namespace std;

Node Graph::getNode(int id) {
    return this->node_lookup[id];
}

void Graph::addEdge(int source, int destination) {
    Node s = getNode(source);
    Node d = getNode(destination);
}

bool Graph::has_dfs_path(int source, int destination) {
    Node s = getNode(source);
    Node d = getNode(destination);
    return false;
}
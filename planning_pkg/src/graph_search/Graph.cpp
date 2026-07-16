#include "Graph.h"
#include <iostream>

using namespace std;

Node Graph::getNode(int id) {
    Node s = this->node_lookup[id];
    return this->node_lookup[id];
}

void Graph::print_lookup() {
    for (auto i : this->node_lookup) {
        cout << i.first << " ";
        for (auto j : i.second.adjacent) {
            cout << j.id;
        }
        cout << endl;
    }
}

void Graph::addEdge(int source, int destination) {

    Node s;
    Node d;

    if (this->node_lookup.find(source) != this->node_lookup.end()){
        // if the hashmap DOES have the node
        s = getNode(source);
        cout << "source adjacents: " << s.adjacent.size() << endl;
        
    }
    else {
        s = Node(source);
        
    }

    

    if (this->node_lookup.find(destination) != this->node_lookup.end()){
        // if the hashmap DOES have the node
        d = getNode(destination);
    }
    else {
        d = Node(destination);
        // cout << "node created: " << d.id << endl;
    }

    
    cout << "pushing source adjacent: " << d.id << endl;
    s.adjacent.push_back(d);
    cout << "source adjacents: " << s.adjacent.size() << endl;
    // d.adjacent.push_back(s);

    this->node_lookup.insert({source, s});
    this->node_lookup.insert({destination, d});
    
}

bool Graph::has_dfs_path(int source, int destination) {
    Node s = getNode(source);
    Node d = getNode(destination);
    // cout << "node ids: " << s.id << " and " << d.id << endl; 
    unordered_set<int> visited;
    return has_dfs_path(s, d, visited);
}

bool Graph::has_dfs_path(Node source, Node destination, unordered_set<int> visited) {
    if (visited.find(source.id) != visited.end()) {
        return false;
    }
    visited.insert(source.id);
    if (source.id == destination.id) {
        cout << "source id: " << source.id << " = destination id: " << destination.id << endl;
        return true;
    }
    for (Node child : source.adjacent){
        if (has_dfs_path(child, destination, visited)){
            return true;
        }
    }
    return false;
}
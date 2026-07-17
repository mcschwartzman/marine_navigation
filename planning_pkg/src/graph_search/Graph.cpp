#include "Graph.h"
#include <iostream>

using namespace std;

Node Graph::getNode(int id) {
    return this->node_lookup[id];
}

void Graph::print_lookup() {
    for (auto i : this->node_lookup) {
        cout << i.first << " ";
        for (auto j : i.second.adjacent) {
            cout << j.id << " ";
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
    }
    else {
        s = Node(source);
    }
    // cout << "source adjacents: " << s.adjacent.size() << endl;
    // cout << "destination to push back: " << destination << endl;

    if (this->node_lookup.find(destination) != this->node_lookup.end()){
        // if the hashmap DOES have the node
        // cout << "destination to get: " << destination << endl;
        d = getNode(destination);
    }
    else {
        // cout << "destination to make: " << destination << endl;
        d = Node(destination);
        // cout << "node created: " << d.id << endl;
    }

    s.adjacent.push_back(d);
    // d.adjacent.push_back(s);

    this->node_lookup[source] = s;
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
    cout << "source: " << source.id << ", destination: " << destination.id << endl;
    if (visited.find(source.id) != visited.end()) {
        // if source is already visited
        cout << "source: " << source.id << " is already visited!" << endl;
        return false;
    }
    visited.insert(source.id);
    if (source.id == destination.id) {
        cout << "source: " << source.id << " is destination!" << endl;
        return true;
    }
    for (Node child : source.adjacent){
        cout << "checking child: " << child.id << endl;
        if (has_dfs_path(child, destination, visited)){
            cout << "dfs path exists!" << endl;
            return true;
        }
    }
    cout << "base case" << endl;
    return false;
}
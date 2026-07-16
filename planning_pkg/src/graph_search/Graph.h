#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "Node.cpp"

class Graph {

    public:
        void addEdge(int source, int destination);
        bool has_dfs_path(int source, int destination);

    private:
        std::unordered_map<int, Node> node_lookup;
        Node getNode(int id);

};
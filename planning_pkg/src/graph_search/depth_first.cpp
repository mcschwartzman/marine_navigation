#include <iostream>

#include "Graph.cpp"

using namespace std;

int main(int argc, const char **argv) {

    Graph test_graph;
    test_graph.addEdge(1, 2);
    test_graph.addEdge(2, 3);
    test_graph.addEdge(3, 4);
    test_graph.print_lookup();

    bool has_path = test_graph.has_dfs_path(1, 3);

    cout << "Has path: " << has_path << endl;
    return 0;
}
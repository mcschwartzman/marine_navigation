#include <iostream>
#include <vector>

class Node {

    public:
        Node();
        Node(int id);

    public:
        int id;
        std::vector<Node> adjacent;
        
};
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <vector>
#include "Node.h"

class Graph {
public:
    Graph() = default;
    ~Graph() = default;

    void add_edge(char N1, char N2, unsigned int weight, bool unique_edges);
    unsigned int numEdges(char node);
    void shortestPath(char node);
    bool noPath = false;
    unsigned int pathWeight = 0;
    char currNode;
    std::vector<char> nodePath;

private:
    std::map<char, Node> node_map;

};


#endif

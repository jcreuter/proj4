#include "Graph.h"
#include "Node.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    Graph g;
	std::string fname;
    std::fstream myfile;
    int n1, n2, w8;
    char startNode, endNode;
    char node1, node2;
    unsigned int w;
    bool unique = false;

    if (argc == 3) {
        startNode = atoi(*(argv + 1));
        endNode = atoi(*(argv + 2));
        while (std::cin >> n1 >> n1 >> w8) {
            std::cin >> node1;
            std::cin >> node2;
            std::cin >> w;
            g.add_edge(node1, node2, w, true);
        }
    }
    else if (argc == 4) {
        fname = atoi(*(argv + 1));
        startNode = atoi(*(argv + 2));
        endNode = atoi(*(argv + 3));
        std::ifstream infile(fname);
        while (infile >> n1 >> n1 >> w8) {
            infile >> node1;
            infile >> node2;
            infile >> w;
            g.add_edge(node1, node2, w, true);
        }
    }

    g.currNode = startNode;
    g.nodePath[0] = startNode;

    while (g.currNode != endNode) {
        g.shortestPath(g.currNode);
    }

    if (g.noPath == true) {
        std::cout << "No path exists from " << startNode << "to" << endNode << std::endl;
    }
    else {
        std::cout << g.pathWeight << ": ";
        for (int i = 0; i < g.nodePath.size(); ++i) {
            std::cout << g.nodePath[i] << " ";
        }
        std::cout << std::endl;
    }
        
}
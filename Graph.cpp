#include "Graph.h"
#include <iostream>

void Graph::add_edge(char N1, char N2, unsigned int weight, bool unique_edges) {
	unsigned int w = weight;
	node_map[N1].out_edges.push_back({ N2, w });
	node_map[N2].in_edges.push_back({ N1, w });
	
	if (unique_edges) {
		node_map[N1].in_edges.unique();
		node_map[N1].out_edges.unique();
		node_map[N2].in_edges.unique();
		node_map[N2].out_edges.unique();
	}
}

unsigned int Graph::numEdges(char node) {
	unsigned int numOfEdges;

	numOfEdges = node_map[node].out_edges.size();

	return numOfEdges;
}

void Graph::shortestPath(char node) {
	unsigned int num, min = 0;
	unsigned int ctr = 1;

	num = numEdges(node);

	if (num > 1) {
		unsigned int i = 0, j = 0;

		for (i; i < num; ++i) {
			for (j; j < num; ++j) {
				auto out_edges1 = node_map[node].out_edges.begin();
				auto out_edges2 = node_map[node].out_edges.begin();
				std::advance(out_edges1, i);
				std::advance(out_edges2, j);
				if (out_edges1->second < out_edges2->second) {
					if (min == 0 || out_edges1->second < min) {
						min = out_edges1->second;
					}
				}
				else {
					if (min == 0 || out_edges2->second < min) {
						min = out_edges1->second;
					}
				}
				
			}
		}
		for (unsigned int k = 0; k < num; ++k) {
			auto shortest_out_edge = node_map[node].out_edges.begin();
			std::advance(shortest_out_edge, k);
			if (min == shortest_out_edge->second) {
				currNode = shortest_out_edge->first;
				nodePath[ctr] = currNode;
				ctr = ctr + 1;
			}
		}
	}

	else if (num == 1) {
		min = node_map[node].out_edges.begin()->second;
		currNode = node_map[node].out_edges.begin()->first;
		nodePath[ctr] = currNode;
		ctr = ctr + 1;
	}

	else if (num == 0) {
		noPath = true;
		return;
	}

	pathWeight = pathWeight + min;
}

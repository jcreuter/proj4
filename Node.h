#ifndef NODE_H_
#define NODE_H_

#include <list>

class Node {
public:
	std::list<std::pair<char, unsigned int>> out_edges;
	std::list<std::pair<char, unsigned int>> in_edges;
};
#endif
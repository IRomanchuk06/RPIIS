#pragma once
#include <stdexcept>
#include <vector>
#include <set>
#include <map>
#include <iostream>

class Ngraph {
public:
   	void AddVertex(int a);
	void AddEdge(int a, int b);
	void DeleteVertex(int a);
	void DeleteEdge(int a, int b);
	void DFSTree(int first);

private:
	std::map<int, std::set<int>> graph;
	void DFS(int a, std::map<int, bool>& visited);
	
};

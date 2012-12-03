#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){	
	num_edges = 0;	
	M.resize(num_nodes);
}

MatrixGraph::~MatrixGraph(){}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	bool identical = false;
	  // checks if edge exists
	if (M[u].at(v) == 0 || M[v].at(u) == 0){
		identical = true;
	}
	if ((identical == false) && (0 <= u < M.size()) && (0 <= v < M.size()) && (u != v) && (weight > 0))	{		
		M[u].at(v) = weight;		
		M[v].at(u) = weight;		
		num_edges++;	
	}
}
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{	
	
	if ((0 <= u < M.size()) && (0 <= v < M.size())){		
		return M[u].at(v);		
	}else return 0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{	
	
	std::list<NWPair> adjacents;
	for (int i = 0; i < M[u].size(); i++){				
		if(M[u].at(i) != 0){
			NWPair temp(i, M[u].at(i));
			adjacents.push_back(temp);								
		}
	}return adjacents;	
}

unsigned MatrixGraph::degree(NodeID u) const{

	if (u >= 0 && u < M.size()){		
		return getAdj(u).size();	
	}else return 0;
}

unsigned MatrixGraph::size() const{	
	return M.size();
}

unsigned MatrixGraph::numEdges() const{	
	return num_edges;	
}
#include "ListGraph.h"


ListGraph::ListGraph(int numNodes){	
	num_edges = 0;	
	edgeList.resize(numNodes);	
}

ListGraph::~ListGraph(){
}	
	
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){	
		
	if ((0 <= u < edgeList.size()) && (0 <= v < edgeList.size()) && (u != v) && (weight > 0)){		
		bool identical = false;
                  std::list<NWPair>::const_iterator iter;
	
		//Check if edge already exists in u's list
		for(iter = edgeList[u].begin(); iter != edgeList[u].end(); iter++){
				//http://stdcxx.apache.org/doc/stdlibug/2-2.html and class notes
				
			if((iter->first == v) && (iter->second == weight)){			
				identical = true;			
				}		
		}
			
		if (identical == false){			
			edgeList[u].push_back(std::make_pair(v,weight));	//adds edge to u's list		
			edgeList[v].push_back(std::make_pair(u,weight));	
			//push_back understanding grabbed from http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html though code is different
			num_edges++;		
		}	
	}
} 
	
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{	
	std::list<NWPair>::const_iterator iter;
	//search all u's edges
	for(iter = edgeList[u].begin(); iter != edgeList[u].end(); iter++){			
		if(iter->first == v){				
			return iter->second;			
		}else return 0;	
	}	
}
	
std::list<NWPair> ListGraph::getAdj(NodeID u) const{		
		return edgeList[u];		
}
unsigned ListGraph::degree(NodeID u) const{		
		return getAdj(u).size();
}

unsigned ListGraph::size() const{	
		return edgeList.size();
}
unsigned ListGraph::numEdges() const{	
		return num_edges;
} 
//Progrma to check wether a node there exsist a path between two nodes in a graph or not

#include <bits/stdc++.h>
using namespace std;

class Graph{
int V;
list<int> *adj;
public:
	Graph(int V);
	void add_edge(int u,int v); 
	bool isPath(int u,int v);
};

//constructor function
Graph::Graph(int V){
this->V = V;
this->adj = new list<int>[V];
};

// add edge 
void Graph::add_edge(int u,int v){
	adj[u].push_back(v);
}
//Utility function to check wether path exsist between two nodes or not
bool Graph::isPath(int u,int v){
queue<int> que;
que.push(u);
while(que.empty() == false){
	int top =que.front();
	que.pop();
	if(top == v){
		return true;
	}
	for (auto jt = adj[top].begin(); jt != adj[top].end(); jt++)
	{
		que.push(*jt);	
	}
}
return false;
}



//Driver  function to test above
int main(){

//Building tree
Graph g(5);
//adding new edge 
g.add_edge(0,1);
g.add_edge(1,3);
g.add_edge(3,4);
g.add_edge(4,2);
if(g.isPath(0,4))

	cout<<"path exsist \n";
else
	cout<<"path doesn't exsist\n";
}
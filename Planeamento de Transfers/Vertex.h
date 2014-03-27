#include "Edge.h"

using namespace std;



template <class T>
class Vertex{

public:

	Vertex(string name);
	void addEdge(Vertex *v, int dis);
	string getName();
	vector<Edge<T>> getEdges();

private:

	string name;
	vector <Edge<T>> edges; //arestas ligadas ao vertice
};





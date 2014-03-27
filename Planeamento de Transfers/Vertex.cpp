#include "Vertex.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <class T>
Vertex<T>::Vertex(string name){
	this->name=name;
}


template <class T>
void Vertex<T>::addEdge(Vertex *v, int dis){

		Edge<T> *newEdge(v, dis);
		edges.push_back(*newEdge); //adiciona a aresta ao vector edges
}


template <class T>
string Vertex<T>::getName(){

	return name;
}


template <class T>
vector<Edge<T>> Vertex<T>::getEdges(){

	return edges;
}

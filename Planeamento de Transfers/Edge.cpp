#include "Edge.h"
#include <iostream>

using namespace std;


template <class T>
Edge<T>::Edge(Vertex<T> destino, int distancia){

		//origem=o;
		this->destino=destino;
		this->distancia=distancia;
}

template <class T>
int Edge<T>::getDis(){

	return distancia;
}


template <class T>
Vertex<T> Edge<T>::getDestino(){

		return destino;
}


/*
template <class T>
Vertex Edge<T>::getOrigem(){

		return origem;
	}
*/

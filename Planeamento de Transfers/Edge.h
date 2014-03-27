
template <class T>
class Edge{

public:

	Edge(/*Vertex<T>origem,*/Vertex<T>destino, int distancia);

	Vertex<T>* getDestino();
	//Vertex<T> getOrigem();
	int getDistancia();

private:

	int distancia;//distancia
	Vertex<T> *destino;
	//Vertex<T> *origem;

};


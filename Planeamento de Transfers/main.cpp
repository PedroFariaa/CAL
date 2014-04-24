#include"Graph.h"
#include"Vertex.h"
#include"Edge.h"
#include"Local.h"
#include"Van.h"
#include"Service.h"

using namespace std;

int main(){
	Local Airport("aeroporto");
	Local Hotel1("hotel1");

	Vertex<Local> airport(Airport);
	Vertex<Local> hotel1(Hotel1);
	Edge<Local>(airport, hotel1,1);
}

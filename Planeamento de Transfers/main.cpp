#include "Local.h"
#include "Van.h"
#include "Graph.h"
#include <iostream>

using namespace std;

#define overhead 60 //overhead em minutos

Graph<Local> g;
vector<Local*> locais;
vector<Van> vans;

void Data_Alteration_Menu(Graph<Local*> g);
void Transfer_Plan_Menu(Graph<Local*> g);
void Add_Data_Menu(Graph<Local*> g);
void Remove_Data_Menu(Graph<Local*> g);
void AddVertex(Graph<Local*> g);
void AddEdge(Graph<Local*> g);
void AddVan();
void RemoveVertex(Graph<Local*> g);
void RemoveEdge(Graph<Local*> g);
void RemoveVan();
void ShowAllVan();
bool First_Scenario(Graph<Local*> g);
int convertToTime(double temp);
int TempoViagem(Local* o, Local* d);
void Graph_Display(Graph<Local*> g);


void MainMenu(Graph<Local*> &g){
	cout <<endl << "------------------------" <<endl;
	cout << "PLANEAMENTO DE TRANSFERS" <<endl;
	cout << "------------------------" <<endl;
	cout << "1) Alteracao de Dados" <<endl;
	cout << "2) Planear Transfer" <<endl;
	cout << "3) Visualizar num grafo" <<endl;

	int input;
	cout << endl <<"Escolha uma opcao:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		Data_Alteration_Menu(g);
		break;
	case 2:
		Transfer_Plan_Menu(g);
		break;
	case 3:
		//Graph_Display(g);
		break;
	default:
		cin.clear();
		cin.ignore(10000, '\n');

		cout << endl;
		cout << "Input invalido." << endl;
		cout << "Pressione <Enter> para continuar...";
		cin.get();
		break;
	}
}

//TODO
void Graph_Display(Graph<Local*> &g) {
}

//not completed
void Transfer_Plan_Menu(Graph<Local*> graf) {
	cout <<endl;
	cout << "------------------------" <<endl;
	cout << "   Calculo de Solucoes   " <<endl;
	cout << "------------------------" <<endl;
	cout << "1) 1 Local, 1 carrinha" <<endl;
	cout << "2) Varios Locais, 1 carrinha" <<endl;
	cout << "2) O menor numero de carrinhas para todos os locais" <<endl;

	int input;
	cout << "Escolha uma opcao:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		First_Scenario(graf);
		break;
	case 2:
		//Secind_Scenario();
		break;
	case 3:
		//Third_Scenario();
		break;
	default:
		cin.clear();
		cin.ignore(10000, '\n');

		cout << endl;
		cout << "Input invalido." << endl;
		cout << "Pressione <Enter> para continuar...";
		cin.get();
		break;
	}
}

void Data_Alteration_Menu(Graph<Local*> g) {
	cout <<endl;
	cout << "------------------------" <<endl;
	cout << "   Alteracao de Dados   " <<endl;
	cout << "------------------------" <<endl;
	cout << "1) Adicionar dados" <<endl;
	cout << "2) Remover dados" <<endl;

	int input;
	cout << "Escolha uma opcao:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		Add_Data_Menu(g);
		break;
	case 2:
		Remove_Data_Menu(g);
		break;
	default:
		cin.clear();
		cin.ignore(10000, '\n');

		cout << endl;
		cout << "Input invalido." << endl;
		cout << "Pressione <Enter> para continuar...";
		cin.get();
		break;
	}
}

//not completed
void Add_Data_Menu(Graph<Local*> g) {
	cout <<endl;
	cout << "------------------------" <<endl;
	cout << "       Aldicionar:      " <<endl;
	cout << "------------------------" <<endl;
	cout << "1) Local" <<endl;
	cout << "2) Caminho entre Locais" <<endl;
	cout << "3) Carrinha" <<endl;

	int input;
	cout << "Escolha uma opcao:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		//AddVertex(g);
		break;
	case 2:
		//AddEdge(g);
		break;
	case 3:
		AddVan();
		break;
	default:
		cin.clear();
		cin.ignore(10000, '\n');

		cout << endl;
		cout << "Input invalido." << endl;
		cout << "Pressione <Enter> para continuar...";
		cin.get();
		break;
	}
}

void Remove_Data_Menu(Graph<Local*> g) {
	cout <<endl;
	cout << "------------------------" <<endl;
	cout << "        Remover:        " <<endl;
	cout << "------------------------" <<endl;
	cout << "1) Local" <<endl;
	cout << "2) Caminho entre Locais" <<endl;
	cout << "3) Carrinha" <<endl;

	int input;
	cout << "Escolha uma opcao:" << endl;
	cout << "> ";
	cin >> input;

	switch (input) {
	case 1:
		RemoveVertex(g);
		break;
	case 2:
		RemoveEdge(g);
		break;
	case 3:
		RemoveVan();
		break;
	default:
		cin.clear();
		cin.ignore(10000, '\n');

		cout << endl;
		cout << "Input invalido." << endl;
		cout << "Pressione <Enter> para continuar...";
		cin.get();
		break;
	}
}

//descomentar
int main(){
	Graph<Local*> g;
	Local* Aeroporto = new Local("aeroporto", 0, 0);
	g.addVertex(Aeroporto);
	locais.push_back(Aeroporto);
	Local* Hotel1 = new Local("nomeHotel", 10, 10.0);
	g.addVertex(Hotel1);
	locais.push_back(Hotel1);
	//LoadFromFile(g);

	MainMenu(g);

	return 0;
}


// Adicao de Dados
void ShowAllVertex() {
	for(int i=0; i<locais.size(); i++){
		cout << i+1 << ")" << locais[i] <<endl;
	}
}

//not completed
void AddVan() {
	cout << "Define o numero maximo de passageiro para esta carrinha" <<endl;
	int input;
	cin >> input;
	Van van(input);
	vans.push_back(van);
	//SaveToFile();
}

//not working
void AddEdge(Graph<Local*> g) {
	Local* ls;
	Local* ld;
	ShowAllVertex();
	cout << "Escolha o nome do Local de Origem:" <<endl;
	string input;
	cin >> input;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input)
			ls = locais[i];
	}
	cout << "Escolha o nome do Local de Destino:" <<endl;
	string input2;
	cin >> input2;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input2)
			ld = locais[i];
	}
	cout << "Indique a distância entre os dois:" <<endl;
	int input3;
	cin >> input3;
	//	g.addEdge(*ls, *ld, input3);
	//SaveToFile();
}


//not working
void AddVertex(Graph<Local*> g) {
	cout << "Escolha o nome para o novo Local:" <<endl;
	string nome;
	cin >> nome;
	cout << "A hora a que as pessoas desse local têm de estar de volta ao aeroporto \n Use o separador (.)" <<endl;
	double hora_max;
	cin >> hora_max;
	cout << "Qual o numero de passageiro a ser recolhido ?" <<endl;
	int npass;
	cin >> npass;
	Local* l = new Local(nome, npass, hora_max);
	locais.push_back(l);
	g.addVertex(l);
	//	SaveToFile();
}


// Remocao de Dados

//not tested
void RemoveVertex(Graph<Local*> g) {
	Local* lr;
	ShowAllVertex();
	cout << "Escolha o nome do Local a Apagar:" <<endl;
	string input;
	cin >> input;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input)
			lr = locais[i];
	}
	//	g.removeVertex(*lr);
}

//TODO
void RemoveEdge(Graph<Local*> g){

}

//TODO
void RemoveVan(){

}

bool First_Scenario(Graph<Local*> g){
	Local* l;
	ShowAllVertex();
	cout << "Escolha o nome do Local:" <<endl;
	string input;
	cin >> input;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input){
			l = locais[i];
			break;
		}else{
			return false;
		}
	}

	Van v;
	ShowAllVan();
	cout << "Escolha o numero da Carrinha:" <<endl;
	int input2;
	cin >> input2;

	cout << "Introduza a hora de partida do aeroporto \n Utilize o (.) como separador" <<endl;
	double input3;
	cin >> input3;

	if(l->getN_pass() > vans[input2-1].getN_pass()){
		cout << "A carrinha nao tem lugares suficientes!";
		return false;
	}else if(convertToTime(input3) > convertToTime(l->getHora()) - 2*TempoViagem(locais[0], l) ){
		cout << "O Transfer nao vai ser feito a tempo";
		return false;
	}else if(convertToTime(input3) < convertToTime(l->getHora()) - (2*TempoViagem(locais[0], l)+overhead)){
		cout << "O overhead dos passageiros sera excedido!";
		return false;
	}else{
		cout << "O transfer foi feito com sucesso!";
		return true;
	}

}

vector<Vertex<Local*>> Second_Scenario(Graph<Local*> g){
	
	vector<Vertex<Local*>> v;
	vector<Vertex<Local*>> v_aux;
	Local* l;
	ShowAllVertex();
	cout << "Escolha o nome do Local:" <<endl;
	string input;
	cin >> input;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input){
			l = locais[i];
			break;
		}else{
			return false;
		}
	}

	Van v;
	ShowAllVan();
	cout << "Escolha o numero da Carrinha:" <<endl;
	int input2;
	cin >> input2;

	cout << "Introduza a hora de partida do aeroporto \n Utilize o (.) como separador" <<endl;
	double input3;
	cin >> input3;

	if(l->getN_pass() > vans[input2-1].getN_pass()){
		cout << "A carrinha nao tem lugares suficientes!";
		return false;
	}else if(convertToTime(input3) > convertToTime(l->getHora()) - 2*TempoViagem(locais[0], l) ){
		cout << "O Transfer nao vai ser feito a tempo";
		return false;
	}else if(convertToTime(input3) < convertToTime(l->getHora()) - (2*TempoViagem(locais[0], l)+overhead)){
		cout << "O overhead dos passageiros sera excedido!";
		return false;
	}else{
		cout << "O transfer foi feito com sucesso!";
		return true;
	}
	if(v_aux.size()>v.size()){
		v=v_aux;
	}

	return v;
}

void ShowAllVan(){
	for(int i=0; i<vans.size(); i++){
		cout << i+1 << "Carrinha com " << vans[i].getN_pass() << "lugares" ;
	}
}

int convertToTime(double temp){
	int tempo_min = (int)(temp)*60 + temp-(int)(temp);
	return tempo_min;
}

//Devolve o tempo (double) de viagem entre o Local de origem e o Local de destino
int TempoViagem(Local* o, Local* d){
	int index, index2;
	for(int i=0; i<locais.size(); i++){
		if(locais[i] == o){
			index=i;
		}
	}
	for(int j=0; j<locais.size(); j++){
		if(locais[j] == d){
			index2=j;
		}
	}
	int temp = g.edgeCost(index, index2);
	return temp;
}

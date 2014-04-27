#include "Local.h"
#include "Graph.h"
#include <iostream>

using namespace std;

Graph<Local> g;
vector<Local*> locais;

void Data_Alteration_Menu(Graph<Local> g);
void Add_Data_Menu(Graph<Local> g);
void Remove_Data_Menu(Graph<Local> g);
void AddVertex(Graph<Local> g);
void AddEdge(Graph<Local>& g);

//descomentar
void MainMenu(Graph<Local> &g){
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
void Graph_Display() {
}

//not completed
void Transfer_Plan_Menu(Graph<Local> graf) {
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
		First_Scenario(g);
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

void Data_Alteration_Menu(Graph<Local> g) {
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
void Add_Data_Menu(Graph<Local> g) {
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
		AddVertex(g);
		break;
	case 2:
		AddEdge(g);
		break;
	case 3:
		//AddVan();
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
void Remove_Data_Menu(Graph<Local> g) {
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
		//RemoveVertex(g);
		break;
	case 2:
		//RemoveEdge(g);
		break;
	case 3:
		//RemoveVan();
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

int main(){
	Graph<Local> g;
	//LoadFromFile(g);

	MainMenu(g);

	return 0;
}


// Adicao de Dados
void ShowAllVertex(Graph<Local> g) {
	for(int i=0; i<locais.size(); i++){
		cout << i+1 << ")" << g.getVertexSet()[i] <<endl;
	}
}

//not completed
void AddVan() {
	cout << "Define o numero maximo de passageiro para esta carrinha" <<endl;
	int input;
	cin >> input;
	//Van van(input);
	//SaveToFile();
}

//not working
void AddEdge(Graph<Local*> g) {
	Local* ls;
	Local* ld;
	ShowAllVertex(g);
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
	g.addEdge(ls, ld, input3);
	//SaveToFile();
}

//not working
void AddVertex(Graph<Local*> g) {
	cout << "Escolha o nome para o novo Local:" <<endl;
	string nome;
	cin >> nome;
	cout << "A hora a que as pessoas desse local têm de estar de volta ao aeroporto" <<endl;
	string hora_max;
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
void RemoveVertex(Graph<Local>& g) {
	Local* lr;
	ShowAllVertex(g);
	cout << "Escolha o nome do Local a Apagar:" <<endl;
	string input;
	cin >> input;
	for(int i=0; i<locais.size(); i++){
		if(locais[i]->getNome() == input)
			lr = locais[i];
	}
	g.removeVertex(*lr);
}


bool First_Scenario(Graph<Local> g){
	Local* l;
	ShowAllVertex(g);
	cout << "Escolha o nome do Local a Apagar:" <<endl;
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

	if(l->getN_Pass > v.num_lug){
		return false;
	}else if(){
		return false;
	}else{
		return true;
	}
	
}
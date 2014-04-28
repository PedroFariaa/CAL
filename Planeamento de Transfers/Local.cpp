#include "Local.h"


Local::Local(){
	this->nome="Aeroporto";
	this->n_pessoas=NULL;
	this->hora=0;
}

Local::Local(string nome, int n_pass, double hora){
	this->nome=nome;
	this->n_pessoas=n_pass;
	this->hora=hora;
}

Local::~Local()
{
}

string Local::getNome(){
	return this->nome;
}

int Local::getN_pass(){
	return this->n_pessoas;
}

double Local::getHora(){
	return this->hora;
}
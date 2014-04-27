#include "Local.h"


Local::Local(){
	this->nome="Aeroporto";
	this->n_pessoas=NULL;
	this->hora="";
}

Local::Local(string nome, int n_pass, string hora){
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
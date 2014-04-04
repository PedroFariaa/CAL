
#include "Service.h"

using namespace std;

Service::Service(string dia, string hora, Local recolha, int n_pass, string hora_max_chegada, Van van){
	this->dia=dia;
	this->hora=hora;
	this->recolha=recolha;
	this->n_pass=n_pass;
	this->hora_max_chegada=hora_max_chegada;
	this->van=van;
	this->done=false;
}

	void Service::set_dia(string dia){
		this->dia=dia;
	}
	void Service::set_hora(string hora){
		this->hora=hora;
	}
	void Service::set_recolha(Local recolha){
		this->recolha=recolha;
	}
	void Service::set_n_pass(int n_pass){
		this->n_pass=n_pass;
	}
	void Service::set_hora_max_chegada(string hora_max_chegada){
		this->hora_max_chegada=hora_max_chegada;
	}
	void Service::set_van(Van van){
		this->van=van;
	}
	string Service::get_dia(){
		return this->dia;
	}
	string Service::get_hora(){
		return this->hora;
	}
	Local Service::get_recolha(){
		return this->recolha;
	}
	int Service::get_n_pass(){
		return this->n_pass;
	}
	string Service::get_hora_max_chegada(){
		return this->hora_max_chegada;
	}
	Van Service::get_van(){
		return this->van;
	}
	void Service::do_service(){
		this->done=true;
	}
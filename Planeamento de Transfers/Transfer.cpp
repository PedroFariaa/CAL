#include "Transfer.h"

void Transfer:: setVan(Van van){
	this->carrinha=van;
}

Van Transfer::getVan(){
	return this->carrinha;
}

/*
* Checks if another Service can be made
*/
void Transfer::AddService(){
	if(serv.get_hora_max_chegada <= this->hora_max_chegada && carrinha.getN_Max >= serv.get_n_pass){
		this->hora_max_chegada = serv.get_hora_max_chegada;
		serv_to_do.push_back(serv);
	}
}

void Transfer::AddLocal(Local local){
	this->itenerario.push_back(local);
}

void Transfer::setHora(string hora){
	this->hora_max_chegada=hora;
}

string Transfer::getHora(){
	return this->hora_max_chegada;
}
/*
void Transfer::Do_Service(){
	for(unsigned int i=0; i<this->done_services.size; i++){
		this->done_services[i].do_service;
	}
}*/
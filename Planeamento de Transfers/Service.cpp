
#include "Service.h"

using namespace std;

Service::Service(vector<Local> locais, Van van){
	//this->hora_max_chegada=hora_max_chegada;
	this->van=van;
	this->done=false;
	this->overhead=1;
}
	/*void Service::set_hora_max_chegada(string hora_max_chegada){
		this->hora_max_chegada=hora_max_chegada;
	}*/
	void Service::set_van(Van van){
		this->van=van;
	}
	vector<Local> Service::get_locais(){
		return this->local;
	}
/*	string Service::get_hora_max_chegada(){
		return this->hora_max_chegada;
	}*/
	Van Service::get_van(){
		return this->van;
	}
	void Service::do_service(){
		this->done=true;
	}
	void Service::add_locais( Local nlocal){
		this->local.push_back(nlocal);
	}

	void Service::setOverhead(int overhead){

		this->overhead=overhead;
	}

	int Service::getOverhead(){

		return overhead;
	}

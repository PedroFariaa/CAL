#include <iostream>
#include <string>
#include "Local.h"

using namespace std;

Local::Local(){
	this->name="no_name";
}

Local::Local(string name){
	this->name=name;
}
 string Local::getName(){
	 return this->name;
 }

 void Local::setName(string name){
	 this->name=name;
 }

 void Local::setHoraRecolha(){

	 hora_recolha=get_hora_max_chegada()-;
 }

string Local::getHoraRecolha(){

	 return hora_recolha;
 }

void Local::set_hora_max_chegada(string hora_max_chegada){
		this->hora_max_chegada=hora_max_chegada;
}

string Local::get_hora_max_chegada(){
		return this->hora_max_chegada;
}

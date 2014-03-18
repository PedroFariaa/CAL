#include <iostream>
#include <string>
#include "Local.h"

using namespace std;

Local::Local(string name){
	this->name=name;
}
 string Local::getName(){
	 return this->name;
 }

 void Local::setName(string name){
	 this->name=name;
 }

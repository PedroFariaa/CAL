#include "Van.h"
using namespace std;

Van::Van(){
	this->n_pass_max=0;
}

Van::Van(int n_pass_max){
	this->n_pass_max=n_pass_max;
}

void Van::setN_Max(int n){
	this->n_pass_max=n;
}

int Van::getN_Max(){
	return this->n_pass_max;
}
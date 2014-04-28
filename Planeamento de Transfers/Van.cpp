#include "Van.h"


Van::Van(void)
{
}

Van::Van(int n_pass){
	this->n_pass=n_pass;
}

Van::~Van(void)
{
}

int Van::getN_pass(){
	return this->n_pass;
}

void Van::setN_pass(int n_pass){
	this->n_pass=n_pass;
}

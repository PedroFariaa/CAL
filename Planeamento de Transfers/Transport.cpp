#include <iostream>
#include <string>
#include "Local.h"
#include "Van.h"
#include "Transport.h"

using namespace std;

	void Transport::set_dia(string dia);
	void Transport::set_hora(string hora);
	void Transport::set_recolha(Local recolha);
	void Transport::set_n_pass(int n_pass);
	void Transport::set_hora_max_chegada(string hora_max_chegada);
	void Transport::set_van(Van van);
	string Transport::get_dia();
	string Transport::get_hora();
	Local Transport::get_recolha();
	int Transport::get_n_pass();
	string Transport::get_hora_max_chegada();
	Van Transport::get_van();
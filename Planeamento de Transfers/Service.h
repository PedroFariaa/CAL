
#include <iostream>
#include <string>
#include "Local.h"
#include "Van.h"
#include <vector>

class Service{
public:
	Service(vector<Local> locais, Van van);
	void set_locais(vector<Local> locais);
	void set_van(Van van);
	void add_locais( Local nlocal);
//	void set_hora_max_chegada(string hora);
//	string get_hora_max_chegada();
	vector<Local> get_locais();
	Van get_van();
	void do_service();
	void setOverhead(int overhead);
	int getOverhead();

private:
	vector<Local> local;
	//string hora_max_chegada;
	Van van;
	bool done;
	int overhead;
};



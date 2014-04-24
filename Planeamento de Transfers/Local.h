#include <string>


using namespace std;

class  Local{
public:
	Local();
	Local(string name);
	string getName();
	void setName(string name);
	void setHoraRecolha();
	string getHoraRecolha();
	void set_hora_max_chegada(string hora);
	string get_hora_max_chegada();
	
private:
	string name;
	string cidade;
	string hora_recolha;
	string hora_max_chegada;
};

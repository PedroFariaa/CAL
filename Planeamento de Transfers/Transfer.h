#include "Van.h"
#include "Service.h"
#include <vector>



class Transfer{
private:
	Service serv;
	vector<Service> serv_to_do;
	vector<Local> itenerario;
	Van carrinha;
	string hora_max_chegada;

public:
	void setVan(Van van);
	Van getVan();
	void AddService();
	void AddLocal(Local local);
	void setHora(string hora);
	string getHora();
	void Do_Service();
	
};
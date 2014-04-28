#include <string>

using namespace std;

class Local{
public:
	Local();
	Local(string nome, int n_pass, double hora);
	~Local();
	string getNome();
	int getN_pass();
	double getHora();

private:
	string nome;
	int n_pessoas;
	double hora;
};

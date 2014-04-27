#include <string>

using namespace std;

class Local{
public:
	Local();
	Local(string nome, int n_pass, string hora);
	~Local();
	string getNome();

private:
	string nome;
	int n_pessoas;
	string hora;
};

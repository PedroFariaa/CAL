
class Transport{
public:
	Transport(string dia, string hora, Local recolha, int n_pass, string hora_max_chegada, Van van);
	void set_dia(string dia);
	void set_hora(string hora);
	void set_recolha(Local recolha);
	void set_n_pass(int n_pass);
	void set_hora_max_chegada(string hora_max_chegada);
	void set_van(Van van);
	string get_dia();
	string get_hora();
	Local get_recolha();
	int get_n_pass();
	string get_hora_max_chegada();
	Van get_van();

private:
	string dia;
	string hora;
	Local recolha;
	int n_pass;
	string hora_max_chegada;
	Van van;
};

Transport::Transport(string dia, string hora, Local recolha, int n_pass, string hora_max_chegada, Van van){
	this->dia=dia;
	this->hora=hora;
	this->recolha=recolha;
	this->n_pass=n_pass;
	this->hora_max_chegada=hora_max_chegada;
	this->van=van;
}

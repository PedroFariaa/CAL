using namespace std;

class  Local{
public:
	Local();
	Local(string name);
	string getName();
	void setName(string name);
	string name;

private:

};

Local::Local(){
	this->name="no_name";
}
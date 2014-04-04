#include <string>

using namespace std;

class  Local{
public:
	Local();
	Local(string name);
	string getName();
	void setName(string name);
	
private:
	string name;

};

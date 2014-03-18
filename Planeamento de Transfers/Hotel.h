
#include "Local.h"

using namespace std;

class Hotel: public Local{
public:
	Hotel(string name, string city);

private:
	string city;
};

Hotel::Hotel(string name, string city):Local(name){
	this->name=name;
	this->city=city;
}
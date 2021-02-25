#pragma once
#include <string>
#include <map> 
class Materie;
class Clase;
#include "Clase.h"
#include "Materie.h"
#include <list>
using namespace std;
class Elev
{
public:
	string nume;
	Clase cls;
	map <string, vector<int>> note;
private:
	string CNP;
public:
	Elev();
	void setclasa(Clase cls);
	void AdaugaElev();
	void vezinote(Materie m);
	void AdaugaNota(Materie m);
	void detalii();
	string getCNP();
};



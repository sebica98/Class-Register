#pragma once
#include<vector>
class Elev;
class Materie;
using namespace std;
class Clase
{	public:
		int cls;
		vector<Elev> elevi;
		vector<Materie> materii;
public:
	Clase(int cls);
	Clase();
	void adaugaElev(Elev e);
	void adaugaMaterie(Materie m);
};


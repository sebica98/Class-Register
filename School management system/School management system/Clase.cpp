#include<iostream>
#include<vector>
#include <string>
#include "Clase.h"
#include "Elev.h"
#include "Materie.h"
using namespace std;
Clase::Clase(int cls) {
	this->cls = cls;
}

Clase::Clase() {
	this->cls = 0;
}
void Clase::adaugaElev(Elev e) {
	cout << "Elevul " << e.nume << " a fost adaugat in clasa " << this->cls;
	this->elevi.push_back(e);
}
void Clase::adaugaMaterie(Materie m)
{
	cout << "Materia " << m.Nume << " a fost adaugata clasei " << this->cls;
	this->materii.push_back(m);
}





#include "Materie.h"
#include<iostream>
using namespace std;
Materie::Materie()
{
	this->Nume = "";
}
void Materie::adauganota(Elev e)
{
	if (this->Nume == "") {
		cout << "Nu exista materii" << endl;

	}
	else {
		int n = 0;
		cout << "Pentru materia: " << this->Nume << " se adauga nota: ";
		cin >> n;
		cout << "Nota " << n << " A fost adaugata elevului " << e.nume<<"!";
		
	}
}
void Materie::adaugamaterie()
{
	cout << "Introduceti denumirea materiei: ";
	cin >> this->Nume;
}


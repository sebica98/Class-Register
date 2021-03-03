#include<iostream>
#include <string>
#include <map>
#include "Elev.h"
#include "Clase.h"
#include "Materie.h"
using namespace std;
Elev::Elev() {
	this->nume = "";
	this->CNP = "xxxxxxxxxxxxx";
	this->cls = Clase();
}
void Elev::setclasa(Clase cls2)
{
	this->cls = cls2;
}
void Elev::AdaugaElev() {
	cout << "Introduceti numele elevului: ";
	cin >> this->nume;
	cout << "Introduceti CNP-ul elevului: ";
	cin >> this->CNP;
}

void Elev::vezinote(Materie m) {
	auto itr = this->note.find(m.Nume);
	if (itr != this->note.end())
	{
		int max = itr->second.size();
		for (int i = 0; i < max; i++)
			cout << "Nota: " << itr->second.at(i) << " la disciplina: " << m.Nume << endl;
	}
}
void Elev::AdaugaNota(Materie m) {

		int n = 0;
		auto it = this->note.find(m.Nume);
		if (it != this->note.end())
		{
			cout << "Pentru materia: " << m.Nume << " se adauga nota: ";
			cin >> n;
			while (n > 10 || n < 1)
			{
				cout << "Nota trebuie sa fie cuprinsa intre 1-10 !!!" << endl;
				cin >> n;
			}
			it->second.push_back(n);
		}
		else
		{
			cout << "Pentru materia: " << m.Nume << " se adauga nota: ";
			cin >> n;
			while (n > 10 || n < 1)
			{
				cout << "Nota trebuie sa fie cuprinsa intre 1-10 !!!" << endl;
				cin >> n;
			}
			cout << "Nota " << n << " A fost adaugata elevului " << this->nume << "!";
			pair<string, vector<int>> p;
			vector<int> v = { n };
			p = make_pair(m.Nume, v);
			this->note.insert(p);
		}
	}
void Elev::detalii()
{
	for (auto it=this->note.begin(); it != this->note.end(); it++)
	{
		cout << it->first
			<< ':';
		for (int i = 0; i < it->second.size(); i++)
			cout << it->second.at(i);
			
		cout<< endl;
	}
}
string Elev::getCNP()
{
	return this->CNP;
}

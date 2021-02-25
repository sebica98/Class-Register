#pragma once
#include <string>
#include <vector>
#include "Elev.h"
#include "Clase.h"
using namespace std;
class Materie
{
public:
	string Nume;
public:
	Materie();
	void adauganota(Elev e);
	void adaugamaterie();
};


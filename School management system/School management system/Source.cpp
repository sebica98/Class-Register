using namespace std;
#include <iostream>
#include <algorithm>  
#include <fstream>
#include <vector>
#include "Elev.h"
#include "Materie.h"
#include "Clase.h"
int main()
{
	ofstream elevifile;
	elevifile.open("elevi.txt");
	int opt=0;
	vector<Clase> clase{};
	vector<Elev> EleviNotati;
	vector<Materie> MateriiNotate;
	//citesc din fisier toti elevii
	while (opt != 8)
	{
		cout << "\t\t Bun venit la Catalogul Online!" << endl;
		cout << "\tPuteti alege una dintre urmatoarele variante: ";
		cout << "\n 1.Introducere clasa: ";
		cout << "\n 2.Introducere elev: ";
		cout << "\n 3.Introducere materie: ";
		cout << "\n 4.Introducere nota elev: ";
		cout << "\n 5.Vezi note la o materie";
		cout << "\n 6.Vezi copiii unei clase: ";
		cout << "\n 7.Vezi detalii complete elev";
		cout << "\n 8.Iesire" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{system("cls");
		int ans;
		cout << "Introduceti ce clasa doriti sa adaugati: ";
		cin >> ans;
		Clase cls = Clase(ans);
		cout << "Clasa a " << ans << "-a a fost adaugata!" << endl;
		clase.push_back(cls);
		system("pause");
		break;
		}
		case 2:
		{system("cls");
		int ans;
		Elev x;
		x.AdaugaElev();
		cout << "Alegeti din urmatoarele clase disponibile : " << endl;
		for (int i = 0; i < int(clase.size()); i++)
			cout << "Optiunea " << i + 1 << " : " << clase.at(i).cls << endl;
		cin >> ans;
		ans -= 1;
		clase.at(ans).adaugaElev(x);
		x.setclasa(clase.at(ans));
		system("pause");
		break;
		}
		case 3: system("cls");
		{
			cout << "Va rugam alegeti din urmatoarele clase: " << endl;
			int ans = 0;
			Materie mat;
			for (int i = 0; i < int(clase.size()); i++)
				cout << "Optiunea " << i+1 << " : Clasa " << clase.at(i).cls << endl;
			cin >> ans;
			ans -= 1;
			mat.adaugamaterie();
			clase.at(ans).adaugaMaterie(mat);
			system("pause");
			break;
		}
		case 4:
		{	system("cls");
			int ans, ans2, ans3;
		cout << "\t \t \t Va rugam alegeti din urmatoarele clase: " << endl;
		for (int i = 0; i < int(clase.size()); i++)
			cout << "Optiunea " << i+1 << " Clasa" << clase.at(i).cls << endl;
		cin >> ans;
		ans -= 1;
		cout << "\t \t \t Va rugam alegeti una dintre urmatoarele materii: " << endl;
		Clase cur = clase.at(ans);
		for (int i = 0; i < int(cur.materii.size()); i++)
			cout << "Optiunea " << i + 1 << " : " << cur.materii.at(i).Nume << endl;
		cin >> ans2;
		ans2 -= 1;
		cout << "\t \t \t Va rugam alegeti unul din urmatorii elevi: " << endl;
		for (int i = 0; i < int(cur.elevi.size()); i++)
			cout << "Optiunea " << i + 1 << " " << cur.elevi[i].nume << endl;
		cin >> ans3;
		ans3 -= 1;
		cur.elevi.at(ans3).AdaugaNota(cur.materii.at(ans2));
		MateriiNotate.push_back(cur.materii.at(ans2));
		for (int i = 0; i < EleviNotati.size(); i++)
		{
			if (EleviNotati.at(i).getCNP() == cur.elevi.at(ans3).getCNP())
				EleviNotati.erase(EleviNotati.begin()+i);
		}
			EleviNotati.push_back(cur.elevi.at(ans3));
		system("pause");
		break;
		}
		case 5:
		{	system("cls");
			int ans1, ans2,ans3,ok=0;
			cout << "\t \t \t Alegeti din ce clasa doriti situatia: " << endl;
			for (int i = 0; i < int(clase.size()); i++)
				cout <<"Optiunea "<<i+1<<" : "<< clase.at(i).cls << endl;
			cin >> ans1;
			ans1 -= 1;
			cout << "\t \t \t Alegeti pentru ce elev doriti situatia: " << endl;
			for (int i = 0; i < int(clase.at(ans1).elevi.size()); i++)
				cout << "Elevul " << i + 1 << " : " << clase.at(ans1).elevi.at(i).nume << endl;
			cin >> ans2;
			ans2 -= 1;
			cout << "\t \t \t Alegeti la ce materie doriti sa aflati situatia: " << endl;
			for (int i = 0; i < int(clase.at(ans1).materii.size()); i++)
				cout << "Optiunea " << i+1 << " : " << clase.at(ans1).materii.at(i).Nume << endl;
			cin >> ans3;
			ans3 -= 1;
			system("cls");
			cout << "\t \t \t Elevul " << clase.at(ans1).elevi[ans2].nume << " are urmatoarele note: " << endl;
			for (int i = 0; i < EleviNotati.size(); i++)
			{
				if (EleviNotati.at(i).getCNP() == clase.at(ans1).elevi.at(ans2).getCNP()) 
					/* caut in elevinotati daca a primit vreo nota, daca da, il sterg din clasa si il inlocuiesc.
					* afisez nota la o materie.
						*/																
				{
					ok = 1;
					clase.at(ans1).elevi.erase(clase.at(ans1).elevi.begin() + ans2);
					clase.at(ans1).elevi.push_back(EleviNotati.at(i));
					clase.at(ans1).elevi.back().vezinote(clase.at(ans1).materii.at(ans3));
					break;
				}
				
			}
			if (ok == 0)
				cout << "ELEVUL NU ARE NICI O NOTA!" << endl;
			//clase.at(ans1).elevi.at(ans2).detalii();
			//EleviNotati.at(0).detalii();
			system("pause");
			break;
		}
		case 6: 
		{	system("cls");
		cout << "\t \t \t Va rugam alegeti clasa dorita: " << endl;
		int ans;
		for (int i = 0; i < int(clase.size()); i++)
			{
			cout << "Optiunea " << i + 1 << " : " << clase.at(i).cls << endl;
			}
		cin >> ans;
		ans -= 1;
		for (int i = 0; i < clase.at(ans).elevi.size(); i++)
		{
			cout << "Elevul " << i + 1 << " : " << clase.at(ans).elevi.at(i).nume << endl;
		}
		system("pause");
		break;
		}
		case 7: {
			system("cls");
			int ans1, ans2, ok = 0;
			cout << "\t \t \t Alegeti din ce clasa doriti situatia: " << endl;
			for (int i = 0; i < int(clase.size()); i++)
				cout << "Optiunea " << i + 1 << " : " << clase.at(i).cls << endl;
			cin >> ans1;
			ans1 -= 1;
			cout << "\t \t \t Alegeti pentru ce elev doriti situatia: " << endl;
			for (int i = 0; i < int(clase.at(ans1).elevi.size()); i++)
				cout << "Elevul " << i + 1 << " : " << clase.at(ans1).elevi.at(i).nume << endl;
			cin >> ans2;
			ans2 -= 1;
			for (int i = 0; i < EleviNotati.size(); i++)
			{
				if (EleviNotati.at(i).getCNP() == clase.at(ans1).elevi.at(ans2).getCNP())
					/* caut in elevinotati daca a primit vreo nota, daca da, il sterg din clasa si il inlocuiesc.
					* afisez nota la o materie.
						*/
				{
					ok = 1;
					clase.at(ans1).elevi.erase(clase.at(ans1).elevi.begin() + ans2);
					clase.at(ans1).elevi.push_back(EleviNotati.at(i));
					clase.at(ans1).elevi.back().detalii();
					break;
				}
			}
			if (ok == 0)
				cout << "ELEVUL NU ARE NICI O NOTA!" << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
		system("cls");
	}
	cout << "Ati iesit din meniu cu succes!";
	//adaug in fisier toti elevii
	for (int i = 0; i < clase.size(); i++)
	{
		for (int j = 0; j < clase.at(i).elevi.size(); j++)
		{
			elevifile << clase.at(i).elevi.at(j).nume;
			elevifile << clase.at(i).elevi.at(j).cls.cls;
			for (auto it = clase.at(i).elevi.at(j).note.begin(); it != clase.at(i).elevi.at(j).note.end(); it++)
			{
				elevifile << it->first;
				for (int i = 0; i < it->second.size(); i++)
					elevifile << it->second.at(i);
			}
			for (int k = 0; k < clase.at(i).materii.size(); k++)
				elevifile << clase.at(i).materii.at(k).Nume;
			elevifile << endl;
		}
	}
	elevifile.close();

	return 0;

};

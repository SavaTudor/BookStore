#pragma once
#include "Carte.h"
#include <vector>
using std::vector;
class Cos
{
private:
	vector<pair<Carte, int>> cos{};
public:
	Cos() noexcept{

	}

	//functia elimina cartile din cos
	void goleste_cos();


	/*Functia adauga o carte data in cos
	* Daca deja exista cartea in cos ii incrementeaza cantitatea
	*/
	void adauga_in_cos(const Carte& c);

	void sterge_din_cos(const int id);

	void modifica_in_cos(const Carte& elem);


	/*
	* Returneaza un vector de perechi <Carte, cantitate> reprezentand elementele din cos
	*/
	const vector<pair<Carte, int>>& get_cos() const;

	/*
	*Returneaza numarul total de carti din cos
	*/
	int total() const;

	//destructorul
	~Cos() {
		cos.clear();
	}
};


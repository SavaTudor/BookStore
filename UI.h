#pragma once
#include "Service.h"
class UI
{
public:
	UI(Service& service) :srv{ service }{}

	UI(const UI& ot) = delete;
	/*
		Afiseaza meniul de comanda
	*/
	void ui_meniu();

	/*
		Afiseaza lista actuala de carti
	*/
	void ui_afisare(const vector<Carte>& lista);

	/*
	*	Citeste atributele unei noi carti si o adauga in repository
	*	Ridica exceptie daca elementul exista deja in repository
	*/
	void ui_adauga();

	/*
	*	Citeste un id si sterge din repository cartea cu id-ul respectiv
	*	Ridica exceptie daca nu exista id-ul dat in lista
	*/
	void ui_sterge();

	/*
	*	Citeste atributele unei carti si modifica in repository cartea cu id-ul dat atribuindu-i noile campuri
	*	Ridica exceptie daca nu exista carte cu id-ul dat in lista
	*/
	void ui_modifica();

	/*
	*	Citeste un string si afiseaza cartile din lista care au in titlu stringul dat
	*/
	void ui_filtreaza_titlu();

	/*
	*	Citeste un an si o comanda 1, respectiv 2, si afiseaza cartile care au aparut inainte, respectiv dupa anul dat
	*/
	void ui_filtreaza_an();

	/*
	*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa titlu lexicografic sau invers lexicografic
	*/
	void ui_sorteaza_titlu();

	/*
	*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa autor lexicografic sau invers lexicografic
	*/
	void ui_sorteaza_autor();

	/*
	*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa an si dupa gen crescator sau descrescator
	*/
	void ui_sorteaza_an_gen();

	/*
	*	Citeste doua stringuri, un titlu si un autor, si cauta in repository o carte care are respectivele atribute
	*	Ridica exceptie daca nu exista in repository
	*/
	void ui_cauta();

	/*Adauga 10 elemente in lista
	*/
	void ui_adauga_10();

	/*
	* Functia citeste un numar intreg si apeleaza functia add_cos din service cu parametrul citit
	*/
	void ui_adauga_in_cos();


	/*
	* Functia apeleaza empty_cos din service
	*/
	void ui_goleste_cos();

	/*
	* Functia afiseaza cartile din cos, fiecare cu cantitatea respectiva 
	*/
	void ui_afisare_cos();

	/*
	* Functia citeste un numar natural si apeleaza functia genereaza_cos din service cu param. dat
	*/
	void ui_genereaza_cos();

	/*
	* Functia citeste numele unui fisier si afiseaza elementele cosului sub forma CVS in fisierul dat
	*/
	void ui_exp_cos();


	void ui_afisare_map();

	//functia care executa programul
	void run();


private:
	Service& srv;
};


#pragma once
#include "Repo.h"
#include "ValidatorCarte.h"
#include "Cos.h"
#include <functional>
#include <random>
#include <map>


using std::string;
using std::vector;
using std::function;
using std::map;

class Service
{
private:
	Repo& repo;
	ValidatorCarte& valid;
	Cos& cos;

public:
	Service(Repo& rep, ValidatorCarte& val, Cos& co) : repo{ rep }, valid{ val }, cos{ co }{}

	Service(const Service& ot) = delete;

	//returneaza numarul de elemente din repository
	int lungime() {
		return repo.len();
	}


	//returneaza lista cartilor din repository
	const vector<Carte>& get_all() {
		return repo.all();
	}

	/*Creeaza un nou obiect de tip carte cu atributele date si il adauga in repository
	* Ridica eroare daca elementul exista
	* titlu - un string cu titlul
	* autor - un string
	* gen - un string
	* an - un int
	* id se va da automat
	*/
	void add(const string& titlu, const string& autor, const string& gen,const int an);


	/*Cauta o carte cu id-ul dat
	* titlul cartii cautate - un string
	* autorul cartii cautate - un string
	* Ridica eroare daca elementul nu exista
	*/
	const Carte& search(string titlu, string autor);

	/*Sterge o carte cu id-ul dat
	* id - un intreg
	* Ridica eroare daca elementul nu exista
	*/
	void erase(const int id);

	/*Modifica obiectul cu id-ul dat, modificandu-i campurile titlu, autor, gen si an
	* Ridica eroare daca elementul cu id-ul dat nu exista
	* titlu - un string cu titlul
	* autor - un string
	* gen - un string
	* an - un int
	*/
	void modify(int id, string titlu, string autor, string gen, int an);


	/*O functie generala de filtrare
	* Returneaza un vector cu elementele din repo care indeplinesc functia data ca parametru
	*/
	vector<Carte> filter(function<bool(const Carte&)> fct)const;


	/*Returneaza un vector de carti care contine doar acele elemente care au stringul s in titlu
	* s - un string
	*/
	vector<Carte> filter_title(string s);

	/*Returneaza un vector de carti care contine doar elementele care au anul aparitiei mai mic sau mai mare decat n
	* n - valoarea de referinta ( un intreg )
	* g - true - arata cartile aparute dupa anul n
	*	  false - arata cartile aparute inainte de anul n
	*/
	vector<Carte> filter_year(int n, bool g);

	/*O functie generala de sortare
	* Returneaza un vector cu elementele din repo ordonate dupa functia data
	*/
	vector<Carte> sort(function<bool(const Carte&, const Carte&)> fct);


	/*Returneaza un vector de carti cu elementele din repository ordonate dupa titlu
	* lexico - true - sorteaza lexicografic
	*			false - sorteaza invers lexicografic
	*/
	vector<Carte> sort_title(bool lexico);

	/*Returneaza un vector de carti cu elementele din repository ordonate dupa autor
	* lexico - true - sorteaza lexicografic
	*			false - sorteaza invers lexicografic
	*/
	vector<Carte> sort_autor(bool lexico);

	/*Returneaza un vector de carti cu elementele din repository ordonate dupa an, iar daca 2 carti au acelasi an
	* departajarea se va face dupa gen
	* ord - true - sorteaza crescator, respectiv lexicografic
	*		false - sorteaza descrescator, respectiv invers lexicografic
	*/
	vector<Carte> sort_an_gen(bool ord);


	/*Functia verifica daca exista o carte cu id-ul dat in lista
	* Daca da, preia cartea si apeleaza functia din repo adauga_in_cos cu parametrul cartea gasita
	* Daca nu, ridica RepoError cu mesajul "Cartea aleasa nu exista!\n"
	*/
	void add_cos(int id);

	/*
	* Apeleaza functia din repository goleste_cos()
	*/
	void empty_cos();


	/*
	* Returneaza elementele din cos
	*/
	const vector<pair<Carte, int>>& get_cos();

	/*
	* Functia primeste un numar natural si adauga in cos un numar de carti egal cu numarul dat
	* Cartile adaugate in cos sunt alese aleator
	*/
	void genereaza_cos(int nr);

	/*
	* Returneaza numarul total de carti din cos
	*/
	int total_cos();

	/*
	* Functia exporta cartile din fisier si cantitatea intr-un fisier dat de utilizator sub forma CVS
	* datele vor fi stocate sub forma: id,titlu,autor,gen,an,cantitate
	*/
	void export_cos(const string& fname)const;

	typedef pair<string, int> P;
	map<string, P> get_map();
};


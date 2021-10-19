#pragma once
#include "Carte.h"
#include "MyList.h"
#include<vector>

class Repo
{
public:
	Repo() : size{ 0 } {};

	Repo(const Repo& ot) = delete;

	//returneaza lungimea listei (un intreg)
	int len();

	/*Adauga un nou element de tip carte in repo
	* elem - o noua carte
	* ridica exceptie daca elementul este deja in repo
	*/
	void adauga(const Carte& elem);

	/*Cauta in lista o carte cu id-ul dat
	* id - un numar intreg
	* ridica exceptie daca elementul nu este in lista
	*/
	const Carte& cauta(string titlu, string autor);

	/*Sterge cartea cu id-ul dat din lista
	* id - un numar intreg
	* ridica exceptie daca elementul nu este in lista
	*/
	void sterge(const int id);

	/*Modifica obiectul cu acelasi id ca si al elementului dat ca parametru
	* elem - un obiect de tip carte
	* ridica exceptie daca elementul nu este in lista
	*/
	void modifica(const Carte& elem);
	

	/*
	* Returneaza lista de carti din repository
	*/
	vector<Carte>& all();

	/*Verifica daca exista o carte cu id-ul dat in lista
	* Ridica exceptie RepoError cu mesajul "Cartea aleasa nu exista!\n" daca nu exista id-ul dat in lista
	*/
	const Carte& exists(int id);

private:
	//lista de elemente
	vector<Carte> lista;
	int size;
	
};

class RepoError 
{
	vector<string> msg;
public:
	RepoError(const char* err) :msg{ err } {

	}

	//returneaza un vector de stringuri ce contine erorile
	vector<string> get_err()const {
		return msg;
	}
};
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Carte
{
public:
	Carte():id{ -1 }, titlu{ "" }, autor{ "" }, gen{ "" }, an{ -1 }{
		
	}

	Carte(const Carte& ot) :id{ ot.id }, titlu{ ot.titlu }, autor{ ot.autor }, gen{ ot.gen }, an{ ot.an } {
		//cout << "!!!!!!!!!!!!!!!!!\n";
	}


	//Constructor (id-intreg, titlu-string, autor-string, gen-string, an-intreg)
	Carte(int id, string titlu, string autor, string gen, int an) :id{ id }, titlu{ titlu }, autor{ autor }, gen{ gen }, an{ an } {
	}

	//returneaza id-ul cartii (un intreg)
	int get_id() const noexcept{
		return id;
	}

	//returneaza titlul cartii (un string)
	string get_titlu() const {
		return titlu;
	}

	//returneaza autorul cartii (un string)
	string get_autor() const {
		return autor;
	}


	//returneaza genul cartii (un string)
	string get_gen() const{
		return gen;
	}

	//returneaza anul aparitiei cartii (un intreg)
	int get_an() const noexcept{
		return an;
	}

	//modifica titlul
	void set_titlu(const string& s);

	//modifica autorul
	void set_autor(const string& s);

	//modifica genul
	void set_gen(const string& s);

	//modifica anul
	void set_an(const int& an_nou) noexcept;
	
	//modifica id-ul
	void set_id(const int& id_nou) noexcept;

	//Returneaza un string de forma "id: titlu , autor, gen, an"
	string afisare() const;

	//returneaza true daca obiectul actual este egal cu other
	bool equal(const Carte& other) const ;


	//functia asigneaza atributele lui other obiectului actual
	Carte& operator =(const Carte& other);

	//returneaza o copie a cartii actuale
	Carte copie() const;


private:
	int id;
	string titlu;
	string autor;
	string gen;
	int an;
};


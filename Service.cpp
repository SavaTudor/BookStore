#include "Service.h"
#include <algorithm>
#include <fstream>

/*Creeaza un nou obiect de tip carte cu atributele date si il adauga in repository
* Ridica eroare daca elementul exista
* titlu - un string cu titlul
* autor - un string
* gen - un string
* an - un int
* id se va da automat
*/
void Service::add(const string& titlu, const string& autor, const string& gen,const int an) {
	const int id = lungime() + 1;
	const Carte carte{id, titlu, autor, gen, an };
	valid.validate(carte);
	repo.adauga(carte);
}


/*Cauta o carte cu id-ul dat
* id - un intreg
* Ridica eroare daca elementul nu exista
*/
const Carte& Service::search(string titlu, string autor) {
	/*
	Carte cautat = repo.cauta(titlu, autor);
	return cautat;
	*/
	return repo.cauta(titlu, autor);
}

/*Sterge o carte cu id-ul dat
* id - un intreg
* Ridica eroare daca elementul nu exista
*/
void Service::erase(const int id) {
	repo.sterge(id);
	cos.sterge_din_cos(id);
}


/*Modifica obiectul cu id-ul dat, modificandu-i campurile titlu, autor, gen si an
* Ridica eroare daca elementul cu id-ul dat nu exista
* titlu - un string cu titlul
* autor - un string
* gen - un string
* an - un int
*/
void Service::modify(int id, string titlu, string autor, string gen, int an) {
	Carte carte{ id, titlu, autor, gen, an };
	valid.validate(carte);
	repo.modifica(carte);
	cos.modifica_in_cos(carte);
}


vector<Carte> Service::filter(function<bool(const Carte&)> fct) const {
	vector<Carte> rez(repo.all().size());
	auto it = std::copy_if(repo.all().begin(), repo.all().end(), rez.begin(), fct);
	rez.resize(std::distance(rez.begin(), it));
	return rez;
}

vector<Carte> Service::filter_title(string s) {
	return filter([s](const Carte& c) {
		return c.get_titlu().find(s)!=string::npos;
	});
}

vector<Carte> Service::filter_year(int n, bool g) {
	if (g) {
		//cazul in care ne trebuie cartile aparute dupa anul n
		return filter([n](const Carte& c) {
			return c.get_an() >= n;
		});
	}
	else {
		//cazul in care ne trebuie cartile aparute inainte de anul n
		return filter([n](const Carte& c) {
			return c.get_an() <= n;
		});
	}

}

vector<Carte> Service::sort(function<bool(const Carte&, const Carte&)> fct) {
	vector<Carte> list{ repo.all()};
	std::sort(list.begin(), list.end(), fct);
	return list;
}


vector<Carte> Service::sort_title(bool lexico) {
	if (lexico) {
		return sort([](const Carte& c1, const Carte& c2) {
			return c1.get_titlu().compare(c2.get_titlu()) < 0;
			});
	}
	else {
		return sort([](const Carte& c1, const Carte& c2) {
			return c1.get_titlu().compare(c2.get_titlu()) > 0;
			});
	}
}


vector<Carte> Service::sort_autor(bool lexico) {
	if (lexico) {
		return sort([](const Carte& c1, const Carte& c2) {
			return c1.get_autor().compare(c2.get_autor()) < 0;
			});
	}
	else {
		return sort([](const Carte& c1, const Carte& c2) {
			return c1.get_autor().compare(c2.get_autor()) > 0;
			});
	}
}

vector<Carte> Service::sort_an_gen(bool ord) {
	if (ord) {
		return sort([](const Carte& c1, const Carte& c2) {
			if (c1.get_an() == c2.get_an()) {
				return c1.get_gen().compare(c2.get_gen()) < 0;
			}
			return c1.get_an() < c2.get_an();
			});
	}
	else {
		return sort([](const Carte& c1, const Carte& c2) {
			if (c1.get_an() == c2.get_an()) {
				return c1.get_gen().compare(c2.get_gen()) > 0;
			}
			return c1.get_an() > c2.get_an();
			});
	}
}

void Service::add_cos(int id) {	
	const Carte& c = repo.exists(id);
	cos.adauga_in_cos(c);
}

void Service::empty_cos() {
	cos.goleste_cos();
}

const vector<pair<Carte, int>>& Service::get_cos() {
	return cos.get_cos();
}

void Service::genereaza_cos(int nr) {
	int k = 0;
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> dist(1, repo.all().size() - 1);
	int rndNr{ 0 };// numar aleator intre [0,size-1]
	while (k < nr) {
		rndNr = dist(mt);
		try {
			add_cos(rndNr);
		}
		catch(RepoError){
			k--;
		}
		k++;
	}
}

void Service::export_cos(const string& fname) const {
	ofstream f(fname);
	for (const auto& i : cos.get_cos()) {
		f << i.first.get_id() << ","<< i.first.get_titlu()<<","<< i.first.get_autor()<<","<< i.first.get_gen()<<","<<i.first.get_an()<<","<<i.second<<"\n";
	}
	f.close();
}

int Service::total_cos() {
	return cos.total();
}

typedef pair<string, int> P;
map<string, P> Service::get_map() {
	map<string, P> rez;
	for (const auto& i : repo.all()) {
		if (rez.find(i.get_gen()) == rez.end()) {
			P con{ i.get_gen(), 1 };
			rez.insert(pair<string, P>(i.get_gen(), con));
		}
		else {
			rez[i.get_gen()].second++;
		}
	}
	return rez;
}
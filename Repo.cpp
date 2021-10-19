#include "Repo.h"

//returneaza lungimea listei ( un intreg)
int Repo::len() {
	return size;
}


/*Adauga un nou element de tip carte in repo
* elem - o noua carte
* ridica exceptie daca elementul este deja in repo
*/
void Repo::adauga(const Carte& elem) {
	for (const auto& i:lista) {
		if (i.equal(elem)) {
			throw RepoError("Element existent!\n");
		}
	}
	lista.push_back(elem);
	size++;
}

/*Cauta in lista o carte cu id-ul dat
* id - un numar intreg
* ridica exceptie daca elementul nu este in lista
*/
const Carte& Repo::cauta(string titlu, string autor) {
	//auto it = find_if(lista.begin(), lista.end(), 
	for (const Carte& carte : lista) {
		if (!carte.get_titlu().compare(titlu) && !carte.get_autor().compare(autor)) {
			return carte;
		}
	}
	throw RepoError("Element inexistent!\n");
}

/*Sterge cartea cu id-ul dat din lista
* id - un numar intreg
* ridica exceptie daca elementul nu este in lista
*/
void Repo::sterge(const int id) {
	for (auto& i : lista) {
		if (i.get_id() == id) {
			auto aux = i;
			i = lista.at(0);
			lista.at(0) = aux;
			const auto it = lista.begin();
			this->lista.erase(it);
			size--;
			return;
		}
	}
	throw RepoError("Element inexistent!\n");
}

/*Modifica obiectul cu acelasi id ca si al elementului dat ca parametru
* elem - un obiect de tip carte
* ridica exceptie daca elementul nu este in lista
*/
void Repo::modifica(const Carte& elem) {
	for (auto& i:lista) {
		if (i.get_id() == elem.get_id()) {
			i = elem;
			return;
		}
	}
	throw RepoError("Element inexistent!\n");
}

/*
* Returneaza lista de carti din repository
*/ 
vector<Carte>& Repo::all(){
	return lista;
}

const Carte& Repo::exists(int id) {
	for (const auto& i : lista) {
		if (i.get_id() == id) {
			return i;
		}
	}
	throw RepoError("Cartea aleasa nu exista\n");
}
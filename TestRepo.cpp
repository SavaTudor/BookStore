#include "TestRepo.h"
#include <iostream>

void TestRepo::test_len() {
	Repo repo{};
	assert(repo.len() == 0);
}

void TestRepo::test_adauga() {
	Repo repo{};
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	repo.adauga(carte1);
	vector<Carte> list{ repo.all() };
	assert(list.size() == 1);
	assert(list.at(0).get_id() == 1);

	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	repo.adauga(carte2);
	list = repo.all();
	assert(list.size() == 2);
	assert(list.at(1).get_id() == 2);
	try {
		repo.adauga(carte1);
		assert(false);
	}
	catch (const RepoError& err) {
		assert(!strcmp(err.get_err().at(0).c_str(), "Element existent!\n"));
	}
}

void TestRepo::test_cauta() {
	Repo repo{};
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	repo.adauga(carte1);
	repo.adauga(carte2);
	Carte cautat = repo.cauta("Povestea lui Harap-Alb", "Ion Creanga");
	assert(!cautat.get_titlu().compare("Povestea lui Harap-Alb"));
	assert(!cautat.get_autor().compare("Ion Creanga"));
	assert(!cautat.get_gen().compare("basm"));
	assert(cautat.get_an() == 1863);
	try {
		Carte inex = repo.cauta("", "");
		assert(false);
	}
	catch (const RepoError& err) {
		assert(!strcmp(err.get_err().at(0).c_str(), "Element inexistent!\n"));
	}
}

void TestRepo::test_sterge() {
	Repo repo{};
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	repo.adauga(carte1);
	repo.adauga(carte2);
	repo.sterge(2);
	assert(repo.len() == 1);
	try {
		repo.sterge(2);
		assert(false);
	}
	catch(const RepoError& err){
		assert(!strcmp(err.get_err().at(0).c_str(), "Element inexistent!\n"));
	}
}

void TestRepo::test_modifica() {
	Repo repo{};
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	repo.adauga(carte1);
	repo.adauga(carte2);
	Carte carte3{ 1, "Testament", "Arghezi", "traditionalism", 1918 };
	repo.modifica(carte3);
	vector<Carte> lista;
	lista = repo.all();
	assert(lista.at(0).get_id() == 1);
	assert(!lista.at(0).get_titlu().compare("Testament"));
	assert(!lista.at(0).get_autor().compare("Arghezi"));
	assert(!lista.at(0).get_gen().compare("traditionalism"));
	assert(lista.at(0).get_an() == 1918);
	Carte carte4{ 4, " ", " ", " ", 2020 };
	try {
		repo.modifica(carte4);
		assert(false);
	}
	catch (const RepoError& err) {
		assert(!strcmp(err.get_err().at(0).c_str(), "Element inexistent!\n"));
	}
}

void TestRepo::test_exists() {
	Repo repo{};
	const Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	const Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	repo.adauga(carte1);
	repo.adauga(carte2);
	assert(repo.exists(1).equal(carte1));
	try {
		repo.exists(10);
		assert(false);
	}
	catch(const RepoError& err){
		assert(!strcmp(err.get_err().at(0).c_str(), "Cartea aleasa nu exista\n"));
	}
}

void TestRepo::run_all_tests_repo() {
	test_len();
	test_adauga();
	test_cauta();
	test_sterge();
	test_modifica();
	test_exists();
}
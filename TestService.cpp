#include "TestService.h"
#include "Repo.h"
#include "Carte.h"
#include "Service.h"
#include <assert.h>
#include <fstream>
using namespace std;

void TestService::test_add() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	assert(srv.lungime() == 1);
	vector<Carte> list;
	list = srv.get_all();
	assert(list.at(0).get_id() == 1);
	assert(!list.at(0).get_titlu().compare("Povestea lui Harap-Alb"));
	assert(!list.at(0).get_autor().compare("Ion Creanga"));
	assert(!list.at(0).get_gen().compare("basm"));
	assert(list.at(0).get_an() == 1863);
	try {
		srv.add(titlu, autor, "nuvela", 1900);
		assert(false);
	}
	catch(const RepoError& err){
		assert(!strcmp(err.get_err().at(0).c_str(), "Element existent!\n"));
	}
}

void TestService::test_search() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	assert(srv.lungime() == 1);
	Carte cautat = srv.search("Povestea lui Harap-Alb", "Ion Creanga");
	assert(cautat.get_titlu() == "Povestea lui Harap-Alb");
	assert(cautat.get_autor() == "Ion Creanga");
	assert(cautat.get_gen() == "basm");
	assert(cautat.get_an() == 1863);
	try {
		cautat = srv.search("", "");
		assert(false);
	}
	catch (const RepoError& err) {
		assert(!strcmp(err.get_err().at(0).c_str(), "Element inexistent!\n"));
	}
}

void TestService::test_erase() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu1{ "Moara cu noroc" };
	string autor1{ "Ioan Slavici" };
	string gen1{ "nuvela" };
	const int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	assert(srv.lungime() == 2);
	srv.erase(2);
	assert(srv.lungime() == 1);
	try {
		srv.erase(2);
		assert(false);
	}
	catch(const RepoError& err){
		assert(!strcmp(err.get_err().at(0).c_str() , "Element inexistent!\n"));
	}
}

void TestService::test_modify() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu1{ "Moara cu noroc" };
	string autor1{ "Ioan Slavici" };
	string gen1{ "nuvela" };
	const int an1 = 1888;
	srv.modify(1, titlu1, autor1, gen1, an1);
	vector<Carte> list;
	list = srv.get_all();
	assert(list.at(0).get_id() == 1);
	assert(list.at(0).get_titlu() == "Moara cu noroc");
	assert(list.at(0).get_autor() == "Ioan Slavici");
	assert(list.at(0).get_gen() == "nuvela");
	assert(list.at(0).get_an() == 1888);
	try {
		srv.modify(10, " ", " ", " ", 2020);
		assert(false);
	}
	catch (const RepoError& err) {
		assert(!strcmp(err.get_err().at(0).c_str(), "Element inexistent!\n"));
	}

}

void TestService::test_filter_title() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion Creanga" };
	string gen1{ "basm" };
	const int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	const int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	vector<Carte> filter_list{ srv.filter_title("Harap") };
	assert(filter_list.size() == 2);
	assert(filter_list.at(0).get_titlu() == "Povestea lui Harap-Alb");
	assert(filter_list.at(0).get_autor() == "Ion Creanga");
	assert(filter_list.at(0).get_gen() == "basm");
	assert(filter_list.at(0).get_an() == 1863);
	assert(filter_list.at(1).get_titlu() == "Harap-Alb");
	assert(filter_list.at(1).get_autor() == "Ion Creanga");
	assert(filter_list.at(1).get_gen() == "basm");
	assert(filter_list.at(1).get_an() == 1888);
}

void TestService::test_filter_year() {
	Repo repo{};
	ValidatorCarte valid{};
	Cos cos{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion Creanga" };
	string gen1{ "basm" };
	const int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	const int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	vector<Carte> filter_list{ srv.filter_year(1900, false) };
	assert(filter_list.size() == 2);
	assert(filter_list.at(0).get_titlu() == "Povestea lui Harap-Alb");
	assert(filter_list.at(0).get_autor() == "Ion Creanga");
	assert(filter_list.at(0).get_gen() == "basm");
	assert(filter_list.at(0).get_an() == 1863);
	assert(filter_list.at(1).get_titlu() == "Harap-Alb");
	assert(filter_list.at(1).get_autor() == "Ion Creanga");
	assert(filter_list.at(1).get_gen() == "basm");
	assert(filter_list.at(1).get_an() == 1888);
	vector<Carte>filter_list1{ srv.filter_year(1900, true) };
	assert(filter_list1.size() == 1);
	assert(filter_list1.at(0).get_titlu() == "Plumb");
	assert(filter_list1.at(0).get_autor() == "George Bacovia");
	assert(filter_list1.at(0).get_gen() == "poezie");
	assert(filter_list1.at(0).get_an() == 1918);
}

void TestService::test_sort_title() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	const int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion Creanga" };
	string gen1{ "basm" };
	const int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	const int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	vector<Carte> sorted_list{ srv.sort_title(true) };
	assert(sorted_list.at(0).get_titlu() == "Harap-Alb");
	assert(sorted_list.at(1).get_titlu() == "Plumb");
	assert(sorted_list.at(2).get_titlu() == "Povestea lui Harap-Alb");
	vector<Carte> sorted_list1{ srv.sort_title(false) };
	assert(sorted_list1.at(2).get_titlu() == "Harap-Alb");
	assert(sorted_list1.at(1).get_titlu() == "Plumb");
	assert(sorted_list1.at(0).get_titlu() == "Povestea lui Harap-Alb");
}
void TestService::test_sort_autor() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "basm" };
	int an = 1863;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	vector<Carte> sorted_list{ srv.sort_autor(true) };
	assert(sorted_list.at(0).get_autor() == "George Bacovia");
	assert(sorted_list.at(1).get_autor() == "Ion");
	assert(sorted_list.at(2).get_autor() == "Ion Creanga");
	vector<Carte>sorted_list1{ srv.sort_autor(false) };
	assert(sorted_list1.at(2).get_autor() == "George Bacovia");
	assert(sorted_list1.at(1).get_autor() == "Ion");
	assert(sorted_list1.at(0).get_autor() == "Ion Creanga");
}
#include<iostream>
void TestService::test_sort_an_gen() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{repo, valid, cos};
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	vector<Carte>sorted_list{ srv.sort_an_gen(true) };
	assert(sorted_list.at(0).get_titlu() == "Hopa");
	assert(sorted_list.at(1).get_titlu() == "Povestea lui Harap-Alb");
	assert(sorted_list.at(2).get_titlu() == "Harap-Alb");
	assert(sorted_list.at(3).get_titlu() == "Plumb");
	vector<Carte>sorted_list1{ srv.sort_an_gen(false) };
	assert(sorted_list1.at(3).get_titlu() == "Hopa");
	assert(sorted_list1.at(2).get_titlu() == "Povestea lui Harap-Alb");
	assert(sorted_list1.at(1).get_titlu() == "Harap-Alb");
	assert(sorted_list1.at(0).get_titlu() == "Plumb");
}

void TestService::test_add_cos() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	assert(srv.get_cos().size() == 0);
	srv.add_cos(1);
	srv.add_cos(2);
	srv.add_cos(1);
	assert(srv.get_cos().size() == 2);
}

void TestService::test_empty_cos() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	srv.add_cos(1);
	srv.add_cos(2);
	srv.add_cos(1);
	assert(srv.get_cos().size() == 2);
	srv.empty_cos();
	assert(srv.get_cos().size() == 0);
}

void TestService::test_cos_all() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	srv.add_cos(1);
	srv.add_cos(2);
	srv.add_cos(1);
	vector<pair<Carte, int>>t{ srv.get_cos() };
	assert(t.at(0).first.get_id() == 1);
	assert(t.at(0).second == 2);
	assert(t.at(1).first.get_id() == 2);
}

void TestService::test_genereaza_cos(){
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	srv.erase(2);
	srv.genereaza_cos(4);
	int t{ 0 };
	for (const auto& i : srv.get_cos()) {
		t += i.second;
	}
	assert(t == 4);
	srv.genereaza_cos(3);
	t = 0;
	for (const auto& i : srv.get_cos()) {
		t += i.second;
	}
	assert(t == 7);
}

void TestService::test_total() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	assert(srv.total_cos() == 0);
	srv.add_cos(1);
	srv.add_cos(2);
	srv.add_cos(3);
	assert(srv.total_cos() == 3);
	srv.add_cos(2);
	srv.add_cos(2);
	assert(srv.total_cos() == 5);
}

void TestService::test_export() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	srv.add_cos(1);
	srv.add_cos(2);
	srv.export_cos("testexport.csv");
	ifstream f("testexport.csv");
	int id;
	f >> id;
	assert(id == 1);
	f.close();
}

void TestService::test_map() {
	Repo repo{};
	Cos cos{};
	ValidatorCarte valid{};
	Service srv{ repo, valid, cos };
	string titlu{ "Povestea lui Harap-Alb" };
	string autor{ "Ion Creanga" };
	string gen{ "Basm" };
	int an = 1888;
	srv.add(titlu, autor, gen, an);
	string titlu2{ "Plumb" };
	string autor2{ "George Bacovia" };
	string gen2{ "poezie" };
	int an2 = 1918;
	srv.add(titlu2, autor2, gen2, an2);
	string titlu1{ "Harap-Alb" };
	string autor1{ "Ion" };
	string gen1{ "basm" };
	int an1 = 1888;
	srv.add(titlu1, autor1, gen1, an1);
	string titlu3{ "Hopa" };
	string autor3{ "ohn" };
	string gen3{ "Aasm" };
	int an3 = 1888;
	srv.add(titlu3, autor3, gen3, an3);
	auto map = srv.get_map();
	
}

void TestService::run_all_tests_service() {
	test_add();
	test_search();
	test_erase();
	test_modify();
	test_filter_title();
	test_filter_year();
	test_sort_title();
	test_sort_autor();
	test_sort_an_gen();
	test_add_cos();
	test_empty_cos();
	test_cos_all();
	test_genereaza_cos();
	test_total();
	test_export();
}

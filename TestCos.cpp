#include "TestCos.h"

void TestCos::test_adauga_cos() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	assert(cos.get_cos().size() == 0);
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	assert(cos.get_cos().size() == 2);
	cos.adauga_in_cos(carte2);
	assert(cos.get_cos().size() == 2);
}

void TestCos::test_get_cos() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	vector<pair<Carte, int>>t{ cos.get_cos() };
	assert(t.at(0).first.equal(carte1));
	assert(t.at(1).first.equal(carte2));
}

void TestCos::test_goleste_cos() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	assert(cos.get_cos().size() == 0);
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	assert(cos.get_cos().size() == 2);
	cos.goleste_cos();
	assert(cos.get_cos().size() == 0);
}

void TestCos::test_total() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	assert(cos.total() == 0);
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	assert(cos.total() == 2);
	cos.adauga_in_cos(carte1);
	assert(cos.total() == 3);
}

void TestCos::test_sterge() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	assert(cos.total() == 2);
	cos.sterge_din_cos(1);
	assert(cos.total() == 1);
	cos.sterge_din_cos(2);
	assert(cos.total() == 0);
}

void TestCos::test_modifica() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	Cos cos{};
	cos.adauga_in_cos(carte1);
	cos.adauga_in_cos(carte2);
	assert(cos.get_cos().at(0).first.get_titlu() == "Povestea lui Harap-Alb");
	cos.modifica_in_cos(Carte{ 1, "a", "a", "a", 1 });
	assert(cos.get_cos().at(0).first.get_titlu() == "a");
	assert(cos.get_cos().at(0).first.get_autor() == "a");
	assert(cos.get_cos().at(0).first.get_gen() == "a");
	assert(cos.get_cos().at(0).first.get_an() == 1);
}

void TestCos::run_all_tests_cos() {
	test_adauga_cos();
	test_get_cos();
	test_goleste_cos();
	test_total();
	test_sterge();
	test_modifica();
}
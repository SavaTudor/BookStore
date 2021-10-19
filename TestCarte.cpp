#include "TestCarte.h"
#include <iostream>

void TestCarte::test_getteri() {
	Carte carte_test{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	assert(carte_test.get_id() == 1);
	assert(!carte_test.get_autor().compare("Ion Creanga"));
	assert(!carte_test.get_titlu().compare("Povestea lui Harap-Alb"));
	assert(!carte_test.get_gen().compare("basm"));
	assert(carte_test.get_an() == 1863);
}

void TestCarte::test_afisare() {
	Carte carte_test{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	string s = carte_test.afisare();
	assert(!s.compare("1: Povestea lui Harap-Alb | Ion Creanga | basm | 1863\n"));
}

void TestCarte::test_egal() {
	Carte carte_test1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte_test2{ 2, "Povestea lui Harap-Alb", "Ion Creanga", "altceva", 1900 };
	Carte carte_test3{ 3, "Moara cu noroc", "Ioan Slavici", "nuvela", 1888 };
	assert(carte_test1.equal(carte_test2));
	assert(!(carte_test1.equal(carte_test3)));
}

void TestCarte::test_setteri() {
	Carte carte_test{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	carte_test.set_id(2);
	carte_test.set_titlu("Harap-Alb");
	carte_test.set_autor("Creanga");
	carte_test.set_gen("necunoscut");
	carte_test.set_an(1900);
	assert(carte_test.get_id() == 2);
	assert(!carte_test.get_autor().compare("Creanga"));
	assert(!carte_test.get_titlu().compare("Harap-Alb"));
	assert(!carte_test.get_gen().compare("necunoscut"));
	assert(carte_test.get_an() == 1900);
}

void TestCarte::test_copy() {
	Carte carte_test{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte copie = carte_test.copie();
	assert(copie.get_id() == 1);
	assert(!copie.get_autor().compare("Ion Creanga"));
	assert(!copie.get_titlu().compare("Povestea lui Harap-Alb"));
	assert(!copie.get_gen().compare("basm"));
	assert(copie.get_an() == 1863);
	assert(&carte_test != &copie);
}

void TestCarte::test_asign() {
	Carte carte1{ 1, "Povestea lui Harap-Alb", "Ion Creanga", "basm", 1863 };
	Carte carte2{ 2, "Plumb", "Bacovia", "simbolism", 1914 };
	carte1 = carte2;
	assert(!carte1.get_titlu().compare("Plumb"));
	assert(!carte1.get_autor().compare("Bacovia"));
	assert(!carte1.get_gen().compare("simbolism"));
	assert(carte1.get_an() == 1914);
}
void TestCarte::run_all_tests_domain() {
	test_getteri();
	test_afisare();
	test_egal();
	test_setteri();
	test_copy();
	test_asign();
}
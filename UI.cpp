#include "UI.h"
#include <iostream>
#include "MyList.h"
#include<vector>
#include <string>
using namespace std;

/*
*	Afiseaza lista actuala de carti
*/
void UI::ui_afisare(const vector<Carte>& lista) {
	if (lista.size() == 0) {
		cout << "Nu exista elemente in lista!\n";
		return;
	}
	string s;
	for (const auto& i:lista) {
		s = i.afisare();
		std::cout << s;
	}
}

/*
*	Citeste atributele unei noi carti si o adauga in repository
*	Ridica exceptie daca elementul exista deja in repository
*/
void UI::ui_adauga() {
	char line[100];
	int an;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti titlul!\n>>>";
	cin.getline(line, 100);
	string titlu{ line };
	cout << "Introduceti autorul!\n>>>";
	cin.getline(line, 100);
	string autor{ line };
	cout << "Introduceti genul!\n>>>";
	cin.getline(line, 100);
	string gen{ line };
	cout << "Introduceti anul aparitiei!\n>>>";
	cin >> an;
	this->srv.add(titlu, autor, gen, an);
}

/*
*	Citeste un id si sterge din repository cartea cu id-ul respectiv
*	Ridica exceptie daca nu exista id-ul dat in lista
*/
void UI::ui_sterge() {
	int id;
	cout << "Introduceti id-ul cartii care va fi stearsa\n>>>";
	cin >> id;
	this->srv.erase(id);
}

/*
*	Citeste atributele unei carti si modifica in repository cartea cu id-ul dat atribuindu-i noile campuri
*	Ridica exceptie daca nu exista carte cu id-ul dat in lista
*/
void UI::ui_modifica() {
	int id, an;
	char line[100];
	cout << "Introduceti id-ul cartii care va fi modificata\n>>>";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti noul titlu!\n>>>";
	cin.getline(line, 100);
	string titlu{ line };
	cout << "Introduceti noul autor!\n>>>";
	cin.getline(line, 100);
	string autor{ line };
	cout << "Introduceti noul gen!\n>>>";
	cin.getline(line, 100);
	string gen{ line };
	cout << "Introduceti noul an al aparitiei!\n>>>";
	cin >> an;
	this->srv.modify(id, titlu, autor, gen, an);
}



/*
* Citeste un string si afiseaza cartile din lista care au in titlu stringul dat 
*/
void UI::ui_filtreaza_titlu() {
	char line[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti secventa cautata!\n>>>";
	cin.getline(line, 100);
	string s{ line };
	vector<Carte> rez;
	string st;
	rez = srv.filter_title(s);
	ui_afisare(rez);
}


/*
* Citeste un an si o comanda 1, respectiv 2, si afiseaza cartile care au aparut inainte, respectiv dupa anul dat
*/
void UI::ui_filtreaza_an() {
	char line[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti anul!\n>>>";
	cin.getline(line, 100);
	int an = {atoi(line)};
	char g;
	cout << "1-pre\n2-post\n>>>";
	cin >> g;
	string s{};
	if (g == '1') {
		/*
		for (const auto& c : srv.filter_year(an, false)) {
			s = c.afisare();
			std::cout << s;
		}*/
		ui_afisare(srv.filter_year(an, false));
		//rez = srv.filter_year(an, false);
	}
	else {
		if (g == '2') {
			/*
			for (const auto& c : srv.filter_year(an, true)) {
				s = c.afisare();
				std::cout << s;
			}*/
			ui_afisare(srv.filter_year(an, true));
			//rez = srv.filter_year(an, true);
		}
		else {
			cout << "Comanda invalida!\n";
			return;
		}
	}
}


/*
*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa titlu lexicografic sau invers lexicografic
*/
void UI::ui_sorteaza_titlu() {
	vector<Carte> rez;
	cout << "1-lexicografic\n2-invers lexicografic\n>>>";
	char l;
	cin >> l;
	string s{};
	if (l == '1') {
		/*
		for (const auto& c : srv.sort_title(true)) {
			s = c.afisare();
			std::cout << s;
		}*/
		ui_afisare(srv.sort_title(true));
		//rez = srv.sort_title(true);
	}
	else {
		if (l == '2') {
			/*
			for (const auto& c : srv.sort_title(false)) {
				s = c.afisare();
				std::cout << s;
			}*/
			ui_afisare(srv.sort_title(false));
			//rez = srv.sort_title(false);
		}
		else {
			cout << "Comanda invalida!\n";
			return;
		}
	}
}

/*
*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa autor lexicografic sau invers lexicografic
*/
void UI::ui_sorteaza_autor() {
	vector<Carte> rez;
	cout << "1-lexicografic\n2-invers lexicografic\n>>>";
	char l;
	cin >> l;
	string s{};
	if (l == '1') {
		/*
		for (const auto& c : srv.sort_autor(true)) {
			s = c.afisare();
			std::cout << s;
		}*/
		ui_afisare(srv.sort_autor(true));
		//rez = srv.sort_autor(true);
	}
	else {
		if (l == '2') {
			/*
			for (const auto& c : srv.sort_autor(false)) {
				s = c.afisare();
				std::cout << s;
			}*/
			ui_afisare(srv.sort_autor(false));
			//rez = srv.sort_autor(false);
		}
		else {
			cout << "Comanda invalida!\n";
			return;
		}
	}
}


/*
*	Citeste o comanda 1 sau 2 si afiseaza cartile din lista ordonate dupa an si dupa gen crescator sau descrescator
*/
void UI::ui_sorteaza_an_gen() {
	vector<Carte> rez;
	cout << "1-crescator\n2-descrescator\n>>>";
	char l;
	cin >> l;
	string s{};
	if (l == '1') {
		/*
		for (const auto& c : srv.sort_an_gen(true)) {
			s = c.afisare();
			std::cout << s;
		}*/
		ui_afisare(srv.sort_an_gen(true));
		//rez = srv.sort_an_gen(true);
	}
	else {
		if (l == '2') {
			/*
			for (const auto& c : srv.sort_an_gen(false)) {
				s = c.afisare();
				std::cout << s;
			}*/
			ui_afisare(srv.sort_an_gen(true));
			//rez = srv.sort_an_gen(false);
		}
		else {
			cout << "Comanda invalida!\n";
			return;
		}
	}
}


/*
*	Citeste doua stringuri, un titlu si un autor, si cauta in repository o carte care are respectivele atribute
*	Ridica exceptie daca nu exista in repository
*/
void UI::ui_cauta() {
	char line[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti titlul cautat!\n>>>";
	cin.getline(line, 100);
	string titlu{ line };
	cout << "Introduceti autorul cautat!\n>>>";
	cin.getline(line, 100);
	string autor{ line };
	//Carte cautat{ this->srv.search(titlu, autor) };
	string s{ this->srv.search(titlu, autor).afisare() };
	cout << s;
}

void UI::ui_adauga_10() {
	this->srv.add("Povestea lui Harap-Alb", "Ion Creanga", "Basm", 1877);
	this->srv.add("Plumb", "George Bacovia", "Basm", 1916);
	this->srv.add("Ion", "Liviu Rebreanu", "Roman", 1920);
	this->srv.add("Ultima noapte de dragoste, intaia noapte de razboi", "Camil Petrescu", "Roman", 1930);
	this->srv.add("O scrisoare pierduta", "I. L. Caragiale", "Comedie", 1884);
	this->srv.add("Baltagul", "Mihail Sadoveanu", "Basm", 1930);
	this->srv.add("Riga Crypto si lapona Enigel", "Ion Barbu", "Poezie moderna", 1924);
	this->srv.add("Iona", "Marin Sorescu", "Parabola dramatica", 1968);
	this->srv.add("Moara cu noroc", "Ioan Slavici", "Basm", 1881);
	this->srv.add("Maitreyi", "Mircea Eliade", "Roman", 1933);
}

void UI::ui_adauga_in_cos() {
	int id;
	cout << "Introduceti id-ul cartii care va fi adaugata in cos\n>>>";
	cin >> id;
	srv.add_cos(id);
	cout << "\nNumarul de carti din cos este: " << srv.total_cos() << "\n";
}

void UI::ui_goleste_cos() {
	srv.empty_cos();
	cout << "\nNumarul de carti din cos este: " << srv.total_cos() << "\n";
}

void UI::ui_afisare_cos() {
	if (srv.get_cos().size() == 0) {
		cout << "Cosul este gol!\n";
		return;
	}
	for (const auto& i : srv.get_cos()) {
		cout << i.first.afisare() << "Cantitate: " << i.second << "\n\n";
	}
	cout << "\nNumarul de carti din cos este: " << srv.total_cos() << "\n";

}

void UI::ui_genereaza_cos() {
	int nr;
	cout << "Introduceti numarul de carti care va fi adaugat in cos\n>>>";
	cin >> nr;
	if (nr <= 0) {
		cout << "Numarul dat nu este valid!\n";
		return;
	}
	srv.genereaza_cos(nr);
	cout << "\nNumarul de carti din cos este: " << srv.total_cos() << "\n";

}

void UI::ui_exp_cos() {
	char line[100];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Introduceti numele fisierului\n>>>";
	cin.getline(line, 100);
	string fname{ line };
	srv.export_cos(fname);
	cout << "\nNumarul de carti din cos este: " << srv.total_cos() << "\n";

}


void UI::ui_afisare_map() {
	for (const auto& i : srv.get_map()) {
		cout << i.first << " de " << i.second.second << " ori\n";
	}
}

/*
Afiseaza meniul de comanda
*/
void UI::ui_meniu() {
	cout << "\nMeniu:\n1. Adauga\n2. Afisare\n3. Sterge\n4. Cauta\n5. Modifica\n6. Filtreaza titlu\n";
	cout << "7. Filtreaza an\n8. Sorteaza dupa titlu\n9. Sorteaza dupa autor\n10. Sorteaza dupa an/gen\n";
	cout << "11. Adauga 10\n12. Adauga in cos\n13. Goleste cos\n14. Genereaza cos\n15. Afisare cos\n16.Export cos\n";
	cout<< "17. Afisare map\n0.Exit\n>>>";
}

//functia care executa programul
void UI::run() {
	ui_meniu();
	int cmd;
	cin >> cmd;
	while (cmd != 0) {
		if (cmd == 1) {
			try {
				ui_adauga();
			}
			catch (const RepoError& err) {
				cout << err.get_err();
			}
			catch (const ValidError& err) {
				cout << err.get_err();
			}
		}
		if (cmd == 2) {
			ui_afisare(srv.get_all());
		}
		if (cmd == 3) {
			try {
				ui_sterge();
			}
			catch (const RepoError& err) {
				cout << err.get_err();
			}
		}
		if (cmd == 4) {
			try {
				ui_cauta();
			}
			catch(const RepoError& err){
				cout << err.get_err();
			}
		}
		if (cmd == 5) {
			try {
				ui_modifica();
			}
			catch (const RepoError& err) {
				cout << err.get_err();
			}
			catch (ValidError err) {
				cout << err.get_err();
			}
		}
		if (cmd == 6) {
			ui_filtreaza_titlu();
		}
		if (cmd == 7) {
			ui_filtreaza_an();
		}
		if (cmd == 8) {
			ui_sorteaza_titlu();
		}
		if (cmd == 9) {
			ui_sorteaza_autor();
		}
		if (cmd == 10) {
			ui_sorteaza_an_gen();
		}
		if (cmd == 11) {
			try {
				ui_adauga_10();
			}
			catch (const char* err) {
				cout << err;
			}
		}
		if (cmd == 12) {
			try {
				ui_adauga_in_cos();
			}
			catch (const RepoError& err) {
				cout << err.get_err();
			}
		}
		if (cmd == 13) {
			ui_goleste_cos();
		}
		if (cmd == 14) {
			ui_genereaza_cos();
		}
		if (cmd == 15) {
			ui_afisare_cos();
		}
		if (cmd == 16) {
			ui_exp_cos();
		}
		if (cmd == 17) {
			ui_afisare_map();
		}
		//ui_meniu();
		cout << ">>>";
		cin >> cmd;
	}
	cout << "Program finished!";
}
#include "Carte.h"

/*modifica titlul
* s - un string reprezentand noul titlu
*/
void Carte::set_titlu(const string& s) {
	this->titlu.assign(s);
}

/*modifica autorul
* s - un string reprezentand noul autor
*/
void Carte:: set_autor(const string& s) {
	this->autor.assign(s);
}

/*modifica genul
* s - un string reprezentand noul gen
*/
void Carte::set_gen(const string& s) {
	this->gen.assign(s);
}

/*modifica anul
* an_nou - un intreg reprezentand noul an
*/
void Carte::set_an(const int& an_nou) noexcept {
	this->an = an_nou;
}

void Carte::set_id(const int& id_nou) noexcept{
	this->id = id_nou;
}

//Returneaza un string de forma "id: titlu | autor | gen | an"
string Carte::afisare() const {
	string s{};
	s = s + to_string(id) + ": " + titlu + " | " + autor + " | " + gen + " | " + to_string(an) + "\n";
	return s;
}

//verifica daca doua obiecte de tipul carte sunt egale
bool Carte::equal(const Carte& other) const {
	if (this->titlu.compare(other.titlu) || this->autor.compare(other.autor)) {
		return false;
	}
	return true;
}

Carte& Carte::operator=(const Carte& other) {
	this->id = other.id;
	this->set_titlu(other.titlu);
	this->set_autor(other.autor);
	this->set_gen(other.gen);
	this->set_an(other.an);
	return *this;
}

//returneaza o copie a cartii actuale
Carte Carte::copie() const{
	Carte copy{ this->get_id(), this->get_titlu(),
				this->get_autor(), this->get_gen(), this->get_an() };
	return copy;
}

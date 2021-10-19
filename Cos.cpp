#include "Cos.h"

void Cos::goleste_cos() {
	cos.clear();
}

void Cos::adauga_in_cos(const Carte& c) {
	for (auto& i : cos) {
		if (i.first.equal(c)) {
			i.second++;
			return;
		}
	}
	pair<Carte, int> p{ c, 1 };
	cos.push_back(p);
}


const vector<pair<Carte, int>>& Cos::get_cos() const{
	return cos;
}

int Cos::total()const {
	int t{ 0 };
	for (const auto& i : cos) {
		t += i.second;
	}
	return t;
}

void Cos::sterge_din_cos(const int id) {
	for (auto& i : cos) {
		if (i.first.get_id() == id) {
			auto aux = i;
			i = cos.at(0);
			cos.at(0) = aux;
			const auto it = cos.begin();
			cos.erase(it);
			return;
		}
	}
}

void Cos::modifica_in_cos(const Carte& elem) {
	for (auto& i : cos) {
		if (i.first.get_id() == elem.get_id()) {
			i.first = elem;
			return;
		}
	}
}
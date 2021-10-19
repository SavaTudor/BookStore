#include "ValidatorCarte.h"

void ValidatorCarte::validate(const Carte& c) {
	vector<string> msg;
	if (!c.get_titlu().compare("")) {
		msg.push_back("Titlu invalid!\n");
	}
	if (!c.get_autor().compare("")) {
		msg.push_back("Autor invalid!\n");
	}
	if (!c.get_gen().compare("")) {
		msg.push_back("Gen invalid!\n");
	}
	if (c.get_an() < 0) {
		msg.push_back("An invalid!\n");
	}
	if (msg.size() > 0) {
		throw ValidError(msg);
	}
}

ostream& operator<<(ostream& out, const ValidError& ex) {
	for (const auto& ms : ex.msg) {
		out << ms;
	}
	return out;
}
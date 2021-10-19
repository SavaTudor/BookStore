#pragma once
#include "Carte.h"
#include <vector>
using std::vector;

class ValidError {
	vector<string> msg;
public:
	ValidError(const vector<string>& err) :msg{ err } {}
	friend ostream& operator<<(ostream& out, const ValidError& err);
	vector<string> get_err() const{
		return msg;
	}
};

ostream& operator<<(ostream& out, const ValidError& err);


class ValidatorCarte
{
public:
	void validate(const Carte& c);
};


#include "TestValidator.h"
#include <assert.h>
#include <sstream>

void TestValidator::run_all_test_validator() {
	Carte rea{1, "", "", "", -1 };
	Carte buna{ 2, "Harap-Alb", "Creanga", "Basm", 1883 };
	ValidatorCarte v;
	try {
		v.validate(rea);
		assert(false);
	}
	catch (const ValidError& err) {
		std::stringstream sout;
		sout << err;
		const vector<string> e{ err.get_err() };
		const auto mesaj = sout.str();
		assert(mesaj.find("Titlu") >= 0);
		assert(mesaj.find("Autor") >= 0);
		assert(mesaj.find("Gen") >= 0);
		assert(mesaj.find("An") >= 0);
	}
	v.validate(buna);
}
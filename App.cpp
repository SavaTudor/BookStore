#include <iostream>
#include "Tests.h"
#include "UI.h"

using namespace std;


void start() {
	ValidatorCarte valid{};
	Repo repo{};
	Cos cos{};
	Service srv{ repo , valid, cos };
	UI ui{ srv };
	ui.run();
}

int main() {
	{
		
//		Tests tests;
//		tests.run_all_tests();
		
		start();


	}
	return 0;
}

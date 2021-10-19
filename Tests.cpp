#include <iostream>
#include "Tests.h"

void Tests::run_all_tests() {
	run_all_tests_domain();
	run_all_tests_repo();
	run_all_tests_service();
	run_all_test_validator();
	run_all_tests_cos();
	std::cout << "Testele au rulat cu succes\n";
}
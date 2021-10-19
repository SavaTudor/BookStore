#pragma once
#include "Carte.h"
#include "Repo.h"
#include <assert.h>
class TestRepo
{
public:
	void test_len();
	void test_adauga();
	void test_cauta();
	void test_sterge();
	void test_modifica();
	void test_exists();
	void run_all_tests_repo();
};


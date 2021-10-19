#pragma once
#include "TestCarte.h"
#include "TestRepo.h"
#include "TestService.h"
#include "TestValidator.h"
#include "TestCos.h"
class Tests : public TestCarte, public TestRepo, public TestService, public TestValidator, public TestCos
{
public:
	void run_all_tests();
};


#pragma once
#include <exception>
class RepoException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Repo Error!\n";
	}
};
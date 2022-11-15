#include <iostream>
#include "options.h"


void ViewAccounts(std::vector<user>* users)
{
	std::cout << "format: username password\n\n";
	std::cout << "==========\n";
	for (user user : *users)
	{
		std::cout << user.u_name << " " << user.u_password << "\n";
	}
	std::cout << "==========\n\n";
}


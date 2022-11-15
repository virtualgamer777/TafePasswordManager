#include <iostream>

#include "options.h"

void Login(std::vector<user>* users)
{
	std::string u_name;
	std::string u_password;

	while (1)
	{
		std::cout << "Username: ";
		std::cin >> u_name;
		user account;

		for (user user : *users)
		{
			std::cout << user.u_name;
			if (strcmp(u_name.c_str(), user.u_name.c_str())) { account = user; }
		}
		if (account.u_name.empty())
		{
			std::cout << "username doesn't exist\n";
			continue;
		}
		std::cout << "Password: ";
		std::cin >> u_password;
		if (!strcmp(u_password.c_str(), account.u_password.c_str()))
		{
			std::cout << "password incorrect";
			continue;
		}
		std::cout << "welcome" << account.u_name << " " << account.u_password << std::endl;

	}

}
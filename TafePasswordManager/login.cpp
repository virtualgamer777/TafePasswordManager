#include <iostream>

#include "options.h"

void Login(std::vector<user>* users)
{
	std::string u_name;
	std::string u_password;

	//just ask for username and password
	while (1)
	{
		std::cout << "Username: ";
		std::cin >> u_name;
		user account;
		std::cout << account.u_name;

		for (user user : *users)
		{
			if (u_name == user.u_name) { account = user; }
		}
		if (account.u_name == "")
		{
			std::cout << "username doesn't exist\n";
			continue;
		}
		std::cout << "Password: ";
		std::cin >> u_password;
		if (u_password != account.u_password)
		{
			std::cout << "password incorrect";
			continue;
		}
		std::cout << "welcome" << " " << account.u_name << std::endl;
		return;
	}

}
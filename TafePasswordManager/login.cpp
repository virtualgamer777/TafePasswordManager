/*
	Benjamin Bale
	29/11/22
	This application is to manage user accounts including logging in, registering and viewing all accounts
*/

#include <iostream>

#include "options.h"

void Login(std::vector<user>* users)
{
	std::string u_name;
	std::string u_password;

	//just ask for username and password
	while (1)
	{
		std::cout << "(type BACK in all caps to go back to the menu)\nUsername: ";
		std::cin >> u_name;
		if (u_name == "BACK") return;
		user account;
		std::cout << account.u_name;

		//compare username with existing usernames
		for (user user : *users)
		{
			if (u_name == user.u_name) { account = user; }
		}
		if (account.u_name == "")
		{
			std::cout << "username doesn't exist\n";
			continue;
		}
		//if it exists ask for password
		std::cout << "Password: ";
		std::cin >> u_password;
		if (u_password != account.u_password)
		{
			std::cout << "password incorrect";
			continue;
		}
		//welcome the user
		std::cout << "welcome " << account.u_name << std::endl;
		return;
	}

}
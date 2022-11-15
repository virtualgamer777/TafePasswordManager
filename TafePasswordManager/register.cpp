#include "options.h"
#include <iostream>

void Register(std::vector<user>* users)
{
	//list of characters
	std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string numbers = "1234567890";
	std::string specialCharacters = "!@#$%^&*()`~-_=+[{]{|;:',<.>/?";


	//get username
	user newUser;
	std::cout << "new username: ";
	std::cin >> newUser.u_name;
	std::string answer;

	//create/generate password (it is hell)
	while (1)
	{
		std::cout << "would you like us to generate a password? (y\\n): ";
		std::cin >> answer;
		if (answer == "n" || answer == "N")
		{
			std::cout << "new password: ";
			std::cin >> newUser.u_password;
			break;
		}
		else if (answer == "y" || answer == "Y")
		{
			std::cout << "would you like to use numbers? (y\\n)";
			std::cin >> answer;
			while (1)
			{
				if (answer == "y" || answer == "Y")
				{
					validChars = validChars + numbers;
				}
				else if (answer == "n" || answer == "N")
				{
					break;
				}
				else
				{
					std::cout << "input a valid option\n";
				}
			}
			std::cout << "would you like to use special characters? (y\\n)";
			std::cin >> answer;
			while (1)
			{
				if (answer == "y" || answer == "Y")
				{
					validChars = validChars + specialCharacters;
				}
				else if (answer == "n" || answer == "N")
				{
					break;
				}
				else
				{
					std::cout << "input a valid option\n";
				}
			}

			break;
		}
		else
		{
			std::cout << "input a valid option\n";
		}
	}

	//write to file and push to the current list
	std::ofstream f;
	f.open("users.txt", std::ofstream::app);
	if (f.is_open())
	{
		f << "\n" << newUser.u_name << " " << newUser.u_password;
	}
	users->push_back(newUser);
	f.close();
}
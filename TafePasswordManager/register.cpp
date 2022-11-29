#include <iostream>
#include "options.h"

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
	//read couts to determin what the application is doing from this point forward
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
			
			while (1)
			{
				std::cout << "would you like to use numbers? (y\\n)";
				std::cin >> answer;
				if (answer == "y" || answer == "Y")
				{
					validChars = validChars + numbers;
					break;
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
			
			while (1)
			{
				std::cout << "would you like to use special characters? (y\\n)";
				std::cin >> answer;
				if (answer == "y" || answer == "Y")
				{
					validChars = validChars + specialCharacters;
					break;
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
			
			while (1)
			{
				std::cout << "How long should the password be? (between 10 and 20 characters)";
				std::cin >> answer;
				int answeri = -1;
				try
				{
					answeri = std::stoi(answer);
				}
				catch (std::exception e)
				{
					std::cout << "input a number\n";
				}
				if (answeri <= 20 && answeri >= 10)
				{
					srand((unsigned int)time(0));
					for (int i = 0; i < answeri; i++)
					{
						newUser.u_password += validChars[rand() % validChars.size()];
						std::cout << newUser.u_password << "\n";
					}
					break;
				}
				std::cout << "the number " << answeri << " is outside of the range we allow. please specify a number between 10 and 20\n";
			}

			break;
		}
		else
		{
			std::cout << "input a valid option\n";
		}
	}

	//write new user file and push to the currently instantiated array
	std::ofstream f;
	f.open("users.txt", std::ofstream::app);
	if (f.is_open())
	{
		f << "\n" << newUser.u_name << " " << newUser.u_password;
	}
	users->push_back(newUser);
	f.close();
}
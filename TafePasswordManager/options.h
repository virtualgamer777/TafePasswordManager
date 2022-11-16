#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct user
{
	std::string u_name;
	std::string u_password;
};

void Login(std::vector<user>* users);
void Register(std::vector<user>* users);
void ViewAccounts(std::vector<user>* users);
void GetUsers(std::vector<user> *users);


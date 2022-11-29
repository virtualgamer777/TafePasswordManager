/*
    Benjamin Bale
    29/11/22
    This application is to manage user accounts including logging in, registering and viewing all accounts
*/

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


//the user data
struct user
{
	std::string u_name;
	std::string u_password;
};


//declare functions ahead of time
void Login(std::vector<user>* users);
void Register(std::vector<user>* users);
void ViewAccounts(std::vector<user>* users);
void GetUsers(std::vector<user> *users);


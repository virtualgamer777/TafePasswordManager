#include "options.h"
#include <iostream>

void GetUsers(std::vector<user>* users)
{
	// open file
	std::ifstream userfile;
	userfile.open("users.txt");
	std::string line;
	
	//read line by line
	while (std::getline(userfile, line))
	{
		std::string fields[2];
		int i = 0;
		std::stringstream ssin(line);
		// seperate by spaces into fields variable
		while (ssin.good() && i < 2) 
		{
			ssin >> fields[i];
			++i;
		}
		//create & push new user to the users vector
		user u;
		u.u_name = fields[0];
		u.u_password = fields[1];
		users->push_back(u);

	}
	userfile.close();
	
}
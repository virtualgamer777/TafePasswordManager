/*
    Benjamin Bale
    29/11/22
    This application is to manage user accounts including logging in, registering and viewing all accounts
*/


//include libraries
#include <iostream>
#include <string>
#include <ctime>
//local includes
#include "options.h"

//main function
int main(int argc, char** argv)
{

    std::time_t t = std::time(0);
#ifdef win32
    char time[26];
    ctime_s(time, sizeof(time), &t);
#else
    char* time = ctime(&t);
#endif
        std::cout << "current time is: " << time << "\n\n\n";

    bool comeBack = true;
    std::vector<user> users;
    GetUsers(&users);
    //output options
    while (1)
    {
        if (comeBack)
        {
            std::cout << "please choose an option:\n"
                << "\t(1) login\n"
                << "\t(2) register\n"
                << "\t(3) view accounts\n"
                << "\t(4) exit\n";
            comeBack = false;
        }

        //read input
        int choice = -1;
        std::string choiceAsStr;
        std::cin >> choiceAsStr;
        try
        {
            choice = std::stoi(choiceAsStr);
        }
        catch(const std::exception &e)
        {
            std::cout << "please input a number\n" << e.what() << "\n";
            continue;
        }

        //do things
        switch (choice)
        {
        case 1:
            comeBack = true;
            Login(&users);
            break;
        case 2:
            comeBack = true;
            Register(&users);
            break;
        case 3:
            comeBack = true;
            ViewAccounts(&users);
            break;
        case 4:
            comeBack = true;
            printf("chose exit\n");
            return 0;
            break;
        default:
            printf("please input a valid option\n");
            break;
        }
    }

}

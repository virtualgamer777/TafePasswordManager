//include libraries
#include <iostream>
#include <string>
//local includes
#include "options.h"

//main function
int main(int argc, char** argv)
{
    std::vector<user> users;
    GetUsers(&users);
    std::cout << users[0].u_name << "\n" << users[0].u_password << "\n";
    //output options
    std::cout << "please choose an option:\n"
        << "\t(1) login\n"
        << "\t(2) register\n"
        << "\t(3) view accounts\n"
        << "\t(4) exit\n";


    while (1)
    {
        //read input
        int choice = -1;
        std::string choiceAsStr;
        std::cin >> choiceAsStr;
        try
        {
            choice = std::stoi(choiceAsStr);
        }
        catch (std::exception e)
        {
            std::cout << "please input a number\n";
            continue;
        }

        //do things
        switch (choice)
        {
        case 1:
            printf("chose login\n");
            Login(&users);
            break;
        case 2:
            printf("chose register\n");
            break;
        case 3:
            printf("chose view accounts\n");
            break;
        case 4:
            printf("chose exit\n");
            return 0;
            break;
        default:
            printf("please input a valid option\n");
            break;
        }
    }

}

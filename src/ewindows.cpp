#include <conio.h>
#include <iostream>
#include <string>
#include "save.hpp"
#include <cctype>

bool contains(std::string g, char b)
{
    for(int i = 0; i < int(g.length()); i++)
    {
        if(g[i] == b)
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return false;
}
int main()
{
    char i;
    bool b = false;
    std::string g, k, g2;
    system("cls");
    std::cout << "Ewindows(Emacs ripoff) version release 1.0" << std::endl << "------------------------------------------" << std::endl;
    for(i = getch(); i != 0x13; i = getch())
    {
        g2 = g;
    	if(i == 0x08)
        {
            if(g == "")
            {
                continue;
            }
            else
            {
                system("cls");
                g = "";
                std::cout << "Ewindows(Emacs in Windows) version release 1.0" << std::endl << "------------------------------------------" << std::endl;
                for(int i = 0; i < int(g2.length()) - 1; ++i)
                {
                    std::cout << g2[i];
                    g.push_back(g2[i]);
                }
            }
        }
        else if(i == 0x09)
        {
            std::cout << '\t';
            g.push_back('\t');
        }
        else if(i == 0x0d)
        {
            system("cls");
            std::cout << "Ewindows(Emacs in Windows) version release 1.0" << std::endl << "------------------------------------------" << std::endl;
            for(int i = 0; i < int(g.length()); i++)
            {
                std::cout << g[i];
            }
            std::cout << std::endl;
            g.push_back('\n');
        }
        else if(i == 0x05)
        {
            b = true;
            system("cls");
            break;
        }
    	else if((i >= 'A' && i <= 'z') || (i <= '9' && i >= '0') || (contains(std::string("!@#$%^&*()_-+={[}]:;\"\'\\|,<>.?/ "), i)))
        {
            g.push_back(i);
            std::cout << i;
        }
    }
    if(b == true)
    {
        return 0;
    }
    else
    {
        system("cls");
        std::cout << "Enter name of file, EXIT to exit: ";
        std::cin >> k;
        if(k == "EXIT")
        {
            system("cls");
            return 0;
        }
        else
        {
            save(k, g);
        }
        system("cls");
    }
}
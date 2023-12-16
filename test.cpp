#include "Account.cpp"
#include "Menu.cpp"
#include <limits>
#include <iostream>
using namespace std;

int main()
{
    Account account;
    Menu menu;

    //=========================Use this Account to test the program===============================
    //Test Account: 1aPGJK9Lvk
    //Test Pin: 123456
    //============================================================================================
    
    while(true)
    {
        menu.displayMenu();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "=====================Invalid Choice=================" << endl;
        }
        else
        {
            if(menu.getChoice() == '1')
            {
                menu.login();
                account.setIsLoggedIn(menu.getIsLoggedIn());
                while(account.isLoggedIn())
                {
                    account.setId(menu.getId());
                    account.displayMenu();
                    if (account.getChoice() == '1')
                    {
                        account.accountInformation();
                    }
                    else if (account.getChoice() == '2')
                    {
                        account.withdraw();
                    }
                    else if (account.getChoice() == '3')
                    {
                        account.deposit();
                    }
                    else if (account.getChoice() == '4')
                    {
                        account.transfer();
                    }
                    else if (account.getChoice() == '5')
                    {
                        account.logout();
                    }
                    else
                    {
                        cout << endl << "=====================Invalid Choice=================" << endl;
                    }
                }
            }
            else if(menu.getChoice() == '2')
            {
                menu.create();
            }
            else if(menu.getChoice() == '3')
            {
                menu.exitProgram();
            }
            else
            {
                cout << endl << "=====================Invalid Choice=================" << endl;
            }
        }
    }
    return 0;
}
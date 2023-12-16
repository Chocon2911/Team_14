#include "Account.cpp"
#include "Menu.cpp"
using namespace std;

int main()
{
    Account account;
    Menu menu;

    while(true)
    {
        menu.displayMenu();
        if (cin.fail())
        {

            cin.clear();
            cin.ignore(1000, '\n');
            cout << "=====================Invalid Choice=================" << endl;
        }
        else
        {
            if(menu.getChoice() == 1)
            {
                menu.login();
                account.setIsLoggedIn(menu.getIsLoggedIn());
                while(account.isLoggedIn())
                {
                    account.setId(menu.getId());
                    account.displayMenu();
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << endl << "==================invalid choice================" << endl;
                    }
                    else
                    {
                        if (account.getChoice() == 1)
                        {
                            account.accountInformation();
                        }
                        else if (account.getChoice() == 2)
                        {
                            account.withdraw();
                        }
                        else if (account.getChoice() == 3)
                        {
                            account.deposit();
                        }
                        else if (account.getChoice() == 4)
                        {
                            account.transfer();
                        }
                        else if (account.getChoice() == 5)
                        {
                            account.logout();
                        }
                    }
                }
            }
            else if(menu.getChoice() == 2)
            {
                menu.create();
            }
            else if(menu.getChoice() == 3)
            {
                menu.exitProgram();
            }
        }
    }
    return 0;
}
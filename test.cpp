#include "Account.cpp"
#include "Menu.cpp"
using namespace std;

int main()
{
    Account account;
    Menu menu;

    // account.setId("3hyxVbnKyg");
    // account.setIsLoggedIn(true);

    while(true)
    {
        menu.displayMenu();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "===============================Invalid Choice=============================";
        }
        else
        {
            if(menu.getChoice() == '1')
            {
                menu.login();
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
                    }
                }
            }
            else if(menu.getChoice() == '2')
            {
                menu.create();
            }
            else if(menu.getChoice())
            {
                menu.exitProgram();
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "===============================Invalid Choice=============================";
            }
        }
    }
    return 0;
}
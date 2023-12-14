#include<iostream>
#include<string>
#include "Account.cpp"
using namespace std;

void shit(int a)
{
    a = 5;
}

int main()
{
    Account account;

    account.setId("3hyxVbnKyg");
    account.setIsLoggedIn(true);

    while(account.isLoggedIn())
    {
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
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "==================invalid choice================" << endl;
        }
    }
    return 0;
}
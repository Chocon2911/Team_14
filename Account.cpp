#include "Account.hpp"
#include<fstream>

//================================================================================================
//=======================================Account Constructor======================================
//================================================================================================
Account::Account()
{
    id = "";
    loggedIn = false;
    choice = 0;
}

Account::Account(string id_, bool loggedIn_, char choice_)
{
    id = id_;
    loggedIn = loggedIn_;
    choice = choice_;
}

Account::~Account()
{

}



//===============================================================================================
//=====================================Getters and Setters=======================================
//===============================================================================================
string Account::getId()
{
    return id;
}

bool Account::isLoggedIn()
{
    return loggedIn;
}

char Account::getChoice()
{
    return choice;
}

int Account::getPin()
{
    return pin;
}

float Account::getBalance()
{
    return balance;
}

vector<string> Account::getFriendList()
{
    return friendList;
}

void Account::setId(string id_)
{
    id = id_;
}

void Account::setIsLoggedIn(bool loggedIn_)
{
    loggedIn = loggedIn_;
}

void Account::setChoice(char choice_)
{
    choice = choice_;
}

void Account::setPin(int pin_)
{
    pin = pin_;
}

void Account::setBalance(float balance_)
{
    balance = balance_;
}

void Account::setFriendList(vector<string> friendList_)
{
    friendList = friendList_;
}



//================================================================================================
//==========================================other functions=======================================
//================================================================================================
void Account::readFile(string id_)
{
    ifstream file("data/" + id_ + ".txt");
    if (file.good())
    {
        file >> pin;
        file >> balance;
        string friendId;
        while (file >> friendId)
        {
            friendList.push_back(friendId);
        }
    }
    else
    {
        cout << "File not found" << endl;
        exit(0);
    }
    file.close();
}

void Account::writeFile(int pin_, float balance_, vector<string> friendList_)
{
    ofstream file("data/" + id + ".txt");
    file << pin_ << " " << balance_ << endl;
    for (int i = 0; i < friendList_.size(); i++)
    {
        file << friendList_[i] << endl;
    }
    file.close();
}

//================================================================================================
//==========================================Account Menu==========================================
//================================================================================================
void Account::displayMenu()
{
    cout << endl;
    cout << "========Account Menu========" << endl;
    cout << "===1. Account information===" << endl;
    cout << "===2. Withdraw money========" << endl;
    cout << "===3. Deposit money=========" << endl;
    cout << "===4. Transfer money========" << endl;
    cout << "===5. Logout================" << endl;
    cout << "============================" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;
}



//================================================================================================
//=======================================Account Information======================================
//================================================================================================
void Account::accountInformation()
{
    Account::readFile(getId());
    cout << endl;
    cout << "========Account Information==========" << endl;
    cout << "Your ID: " << Account::getId() << endl;
    cout << "Your PIN: " << Account::getPin() << endl;
    cout << "Your Balance: " << Account::getBalance() << endl;
    cout << "Your Friend List: " << endl;
    for (int i = 0; i < Account::getFriendList().size(); i++)
    {
        cout << i + 1 << ". " << Account::getFriendList()[i] << endl;
    }
    cout << "====================================" << endl;
}



//================================================================================================
//=============================================Withdraw===========================================
//================================================================================================
void Account::withdraw()
{
    cout << endl;
    cout << "========Withdraw==========" << endl;
    cout << "===1. 10==================" << endl;
    cout << "===2. 20==================" << endl;
    cout << "===3. 50==================" << endl;
    cout << "===4. 100=================" << endl;
    cout << "===5. other===============" << endl;
    cout << "===6. back================" << endl;
    cout << "==========================" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;
    if (getChoice() == '1')
    {
        Account::withdrawAmount(10);
    }
    else if (getChoice() == '2')
    {
        Account::withdrawAmount(20);
    }
    else if (getChoice() == '3')
    {
        Account::withdrawAmount(50);
    }
    else if (getChoice() == '4')
    {
        Account::withdrawAmount(100);
    }
    else if (getChoice() == '5')
    {
        float amount;
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        if (cin.fail())
        {
            cout << "==================Invalid amount!==================" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            Account::withdrawAmount(amount);
        }
    }
    else if (getChoice() == '6')
    {
        return;
    }
    else
    {
        cout << "==================Invalid choice!==================" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void Account::withdrawAmount(float amount_)
{
    Account::readFile(getId());

    if (amount_ < 0)
    {
        cout << "==================Invalid amount!==================" << endl;
    }

    if (Account::getBalance() < amount_)
    {
        cout << "==================Not enough money!===============" << endl;
    }
    else
    {
        Account::setBalance(Account::getBalance() - amount_);
        Account::writeFile(Account::getPin(), Account::getBalance(), Account::getFriendList());
        cout << "your new balance is: " << Account::getBalance() << endl;
        cout << "==================Withdraw success!===============" << endl;
    }
}



//================================================================================================
//=============================================Deposit============================================
//================================================================================================
void Account::deposit()
{
    float amount;
    cout << endl;
    cout << "============Deposit==========" << endl;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    if (cin.fail())
    {
        cout << "==================Invalid amount!==================" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else
    {
        Account::depositAmount(amount);
    }
}

void Account::depositAmount(float amount_)
{
    Account::readFile(getId());
    if (amount_ < 0)
    {
        cout << "==================Invalid amount!==================" << endl;
    }
    else
    {
        Account::setBalance(Account::getBalance() + amount_);
        Account::writeFile(Account::getPin(), Account::getBalance(), Account::getFriendList());
        cout << "your new balance is: " << Account::getBalance() << endl;
        cout << "==================Deposit success!===============" << endl;
    }
}



//================================================================================================
//=============================================Transfer===========================================
//================================================================================================
void Account::transfer()
{
    Account::readFile(getId());
    int choice_;
    cout << endl;
    cout << "==================Transfer==================" << endl;
    for(int i = 0; i < Account::getFriendList().size(); i++)
    {
        cout << i + 1 << ". " << Account::getFriendList()[i] << endl;
    }
    cout << Account::getFriendList().size() + 1 << ". add new friend" << endl;
    cout << Account::getFriendList().size() + 2 << ". back" << endl;
    cout << "Enter your choice: ";
    cin >> choice_;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "==================Invalid choice!==================" << endl;
    }
    else
    {
        if (choice_ == Account::getFriendList().size() + 1)
        {
            Account::addFriend();
        }
        else if (choice_ == Account::getFriendList().size() + 2)
        {
            return;
        }
        else
        {
            ifstream file("data/" + getFriendList()[choice_ - 1] + ".txt");
            if (!file.good())
            {
                file.close();
                cout << "==================Friend not found!==================" << endl;
            }
            else
            {
                file.close();
                Account::chooseFriendToTransfer(choice_);
            }
        }
    }
}

void Account::chooseFriendToTransfer(int choice_)
{
    float amount_;
    string friendId_ = Account::getFriendList()[choice_ - 1];
    cout << "Enter the amount you want to transfer: ";
    cin >> amount_;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "==================Invalid amount!==================" << endl;
    }
    else
    {
        Account::transferAmount(amount_, friendId_);
    }
}

void Account::transferAmount(float amount_, string friendId_)
{
    Account::readFile(getId());
    if (amount_ < 0)
    {
        cout << "==================Invalid amount!==================" << endl;
    }

    else if (Account::getBalance() < amount_)
    {
        cout << "==================Not enough money!===============" << endl;
    }

    else
    {
        Account::setBalance(Account::getBalance() - amount_);
        Account::writeFile(Account::getPin(), Account::getBalance(), Account::getFriendList());
        Account::readFile(friendId_);
        Account::setBalance(Account::getBalance() + amount_);
        Account::writeFile(Account::getPin(), Account::getBalance(), Account::getFriendList());
        cout << "you have transferred " << amount_ << " to " << friendId_ << endl;
        cout << "your new balance is: " << Account::getBalance() << endl;
        cout << "==================Transfer success!===============" << endl;
    }
}

void Account::addFriend()
{
    string friendId_;
    cout << "Enter the ID that you want to add to your friend list: ";
    cin >> friendId_;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "==================Invalid ID!==================" << endl;
    }
    else
    {
        ifstream file("data/" + friendId_ + ".txt");
        if(file.good())
        {
            Account::readFile(getId());
            friendList.push_back(friendId_);
            writeFile(Account::getPin(), Account::getBalance(), friendList);
        }
        else
        {
            cout << "============Friend's ID not valid!=============" << endl;
        }
    }
}



//================================================================================================
//=============================================Logout=============================================
//================================================================================================
void Account::logout()
{
    Account::setIsLoggedIn(false);
}
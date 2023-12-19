#include "Account.hpp"
#include<fstream>

//================================================================================================
//=======================================Account Constructor======================================
//================================================================================================
Account::Account()
{
    loggedIn = false;
}

Account::Account(string id_)
{
    id = id_;
    loggedIn = false;
}

Account::~Account()
{

}



//===============================================================================================
//=====================================Getters and Setters=======================================
//===============================================================================================
const string Account::getId()
{
    return id;
}

const bool Account::isLoggedIn()
{
    return loggedIn;
}

const string Account::getChoice()
{
    return choice;
}

const int Account::getPin()
{
    return pin;
}

const float Account::getBalance()
{
    return balance;
}

const vector<string> Account::getFriendList()
{
    return friendList;
}

const void Account::setId(string id_)
{
    id = id_;
}

const void Account::setIsLoggedIn(bool loggedIn_)
{
    loggedIn = loggedIn_;
}

const void Account::setChoice(char choice_)
{
    choice = choice_;
}

const void Account::setPin(int pin_)
{
    pin = pin_;
}

const void Account::setBalance(float balance_)
{
    balance = balance_;
}

const void Account::setFriendList(vector<string> friendList_)
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
        vector<string> list_;
        while (file >> friendId)
        {
            list_.push_back(friendId);
        }
        friendList = list_;
    }
    else
    {
        cout << "File not found" << endl;
        exit(0);
    }
    file.close();
}

void Account::writeFile(string id_, int pin_, float balance_, vector<string> friendList_)
{
    ofstream file("data/" + id_ + ".txt");
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
    if (getChoice() == "1")
    {
        Account::withdrawAmount(10);
    }
    else if (getChoice() == "2")
    {
        Account::withdrawAmount(20);
    }
    else if (getChoice() == "3")
    {
        Account::withdrawAmount(50);
    }
    else if (getChoice() == "4")
    {
        Account::withdrawAmount(100);
    }
    else if (getChoice() == "5")
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
    else if (getChoice() == "6")
    {
        return;
    }
    else
    {
        cout << endl << "==================Invalid choice!==================" << endl;
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
        Account::writeFile(Account::getId(), Account::getPin(), Account::getBalance(), Account::getFriendList());
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
        Account::writeFile(Account::getId(), Account::getPin(), Account::getBalance(), Account::getFriendList());
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
        else if (choice_ <= Account::getFriendList().size() && choice_ > 0)
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
        else
        {
            cout << "==================Invalid choice!==================" << endl;
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
        Account::writeFile(Account::getId(), Account::getPin(), Account::getBalance(), Account::getFriendList());
        Account::readFile(friendId_);
        Account::setBalance(Account::getBalance() + amount_);
        Account::writeFile(friendId_, Account::getPin(), Account::getBalance(), Account::getFriendList());
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
            writeFile(Account::getId(), Account::getPin(), Account::getBalance(), Account::getFriendList());
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
    cout << "===================You have logout=================" << endl;
    Account::setIsLoggedIn(false);
}
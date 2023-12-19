#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Account
{
    public:
    Account();
    Account(string id_);
    ~Account();

    void displayMenu();
    void accountInformation();
    void withdraw();
    void deposit();
    void transfer();
    void logout();

    const string getId();
    const bool isLoggedIn();
    const string getChoice();
    const void setId(string id_);
    const void setIsLoggedIn(bool loggedIn_);
    const void setChoice(char choice_);

    private:
    string id;
    bool loggedIn;
    string choice;

    int pin = 0;
    float balance = 0;
    vector<string> friendList;
    const int getPin();
    const float getBalance();
    const vector<string> getFriendList();
    const void setPin(int pin_);
    const void setBalance(float balance_);
    const void setFriendList(vector<string> friendList_);

    void withdrawAmount(float amount);

    void depositAmount(float amount);

    void transferAmount(float amount, string friendId);
    void addFriend();
    void chooseFriendToTransfer(int choice);

    void readFile(string id);
    void writeFile(string id,int pin, float balance, vector<string> friendList);
};
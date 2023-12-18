#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Account
{
    public:
    Account();
    Account(string id_, bool loggedIn_, string choice_);
    ~Account();

    void displayMenu();
    void accountInformation();
    void withdraw();
    void deposit();
    void transfer();
    void logout();

    string getId();
    bool isLoggedIn();
    string getChoice();
    void setId(string id_);
    void setIsLoggedIn(bool loggedIn_);
    void setChoice(char choice_);

    private:
    string id;
    bool loggedIn;
    string choice;

    int pin = 0;
    float balance = 0;
    vector<string> friendList;
    int getPin();
    float getBalance();
    vector<string> getFriendList();
    void setPin(int pin_);
    void setBalance(float balance_);
    void setFriendList(vector<string> friendList_);

    void withdrawAmount(float amount);

    void depositAmount(float amount);

    void transferAmount(float amount, string friendId);
    void addFriend();
    void chooseFriendToTransfer(int choice);

    void readFile(string id);
    void writeFile(string id,int pin, float balance, vector<string> friendList);
};
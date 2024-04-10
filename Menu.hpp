#pragma once
#include<iostream>
#include<string>
using namespace std;

class Menu
{
    public:
    Menu();
    Menu(string id);
    ~Menu();

    void displayMenu();
    void login();
    void create();
    void exitProgram();

    const string getId();
    const bool getIsLoggedIn();
    const string getChoice();
    const void setId(string id);
    const void setIsLoggedIn(bool isLoggedIn);
    const void setChoice(char choice);

    void randomRunRequire();

    private:
    string id;
    int pin;
    bool isLoggedIn;
    string choice;
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    const int getPin();
    const void setPin(int pin);

    void checkLogin(string id, int pin);

    string getRandomId();
    void createRandomIdFile(int pin);
};
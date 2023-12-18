#pragma once
#include<iostream>
#include<string>
using namespace std;

class Menu
{
    public:
    Menu();
    Menu(string id, bool isLoggedIn, string choice);
    ~Menu();

    void displayMenu();
    void login();
    void create();
    void exitProgram();

    string getId();
    bool getIsLoggedIn();
    string getChoice();
    void setId(string id);
    void setIsLoggedIn(bool isLoggedIn);
    void setChoice(char choice);

    private:
    string id;
    bool isLoggedIn;
    string choice;
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    void checkLogin(string id, int pin);

    string getRandomId();
    void randomRunRequire();
    void createRandomIdFile(int pin);
};
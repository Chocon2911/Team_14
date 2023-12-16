#pragma once
#include "Menu.hpp"
#include<fstream>
#include<cstdlib>
#include<ctime>

//================================================================================================
//=====================================Menu Constructors==========================================
//================================================================================================
Menu::Menu()
{
    id = "";
    isLoggedIn = false;
    choice = 0;
}

Menu::Menu(string id_, bool isLoggedIn_, int choice_)
{
    id = id_;
    isLoggedIn = isLoggedIn_;
    choice = choice_;
}

Menu::~Menu()
{

}



//================================================================================================
//=====================================Getters and Setter=========================================
//================================================================================================
string Menu::getId()
{
    return id;
}
bool Menu::getIsLoggedIn()
{
    return isLoggedIn;
}
char Menu::getChoice()
{
    return choice;
}
void Menu::setId(string id_)
{
    id = id_;
}
void Menu::setIsLoggedIn(bool isLoggedIn_)
{
    isLoggedIn = isLoggedIn_;
}



//================================================================================================
//=======================================Other Functions==========================================
//================================================================================================
void Menu::randomRunRequire()
{
    srand(time(0));
}

string Menu::getRandomId()
{
    string id_;
    for(int i = 0; i < 10; i++)
    {
        id_ += CHARACTERS[rand() % CHARACTERS.length()];
    }
    return id_;
}



//================================================================================================
//========================================Display Menu============================================
//================================================================================================
void Menu::displayMenu()
{
    cout << endl;
    cout << "==================Menu================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Exit" << endl;
    cout << "======================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
}



//================================================================================================
//============================================Login===============================================
//================================================================================================
void Menu::login()
{
    int pin_ = 0;
    cout << endl;
    cout << "==================Login===============" << endl;
    cout << "Enter your ID: ";
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid PIN!" << endl;
    }
    else
    {
        cout << "Enter your PIN: ";
        cin >> pin_;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid PIN!" << endl;
        }
        else
        {
            Menu::checkLogin(id, pin_);
        }
    }
}

void Menu::checkLogin(string id_, int pin_)
{
    ifstream file("data/" + id +".txt");
    if (file.good())
    {
        Menu::setIsLoggedIn(true);
    }
    else
    {
        Menu::setIsLoggedIn(false);
        cout << "==============================Login failed!===============================" << endl;
    }
}



//================================================================================================
//========================================Create Account=========================================
//================================================================================================
void Menu::create()
{
    int pin_ = 0;
    cout << endl;
    cout << "===============Create Account=============" << endl;
    cout << "Enter your PIN (6 digit numbers): ";
    cin >> pin_;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "==========================Invalid PIN!=========================" << endl;
    }
    else
    {
        if (pin_ >= 100000 && pin_ <= 999999)
        {
            createRandomIdFile(pin_);
            cout << "==========================================" << endl;
        }
        else
        {
            cout << "===========6 digit numbers only!==========" << endl;
        }
    }
}

void Menu::createRandomIdFile(int pin_)
{
    string id_ = getRandomId();
    ofstream file("data/" + id_ + ".txt");
    file << pin_ << " " << 0;
    file.close();
    cout << "====================your account has been created!==================" << endl;
    cout << "Your Random ID is: " << id_ << endl;
    cout << "Your PIN is: " << pin_ << endl;
}



//================================================================================================
//============================================Exit================================================
//================================================================================================
void Menu::exitProgram()
{
    exit(0);
}
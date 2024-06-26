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
    isLoggedIn = false;
}

Menu::Menu(string id_)
{
id = id_;
isLoggedIn = false;
pin = 0;
}

Menu::~Menu()
{
    
}



//================================================================================================
//=====================================Getters and Setter=========================================
//================================================================================================
const string Menu::getId()
{
    return id;
}
const bool Menu::getIsLoggedIn()
{
    return isLoggedIn;
}
const string Menu::getChoice()
{
    return choice;
}
const int Menu::getPin()
{
    return pin;
}
const void Menu::setId(string id_)
{
    id = id_;
}
const void Menu::setIsLoggedIn(bool isLoggedIn_)
{
    isLoggedIn = isLoggedIn_;
}
const void Menu::setPin(int pin_)
{
    pin = pin_;
}



//================================================================================================
//=======================================Other Functions==========================================
//================================================================================================
void Menu::randomRunRequire()
{
    srand(time(NULL));
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
    file >> pin;
    if (file.good() && pin_ == Menu::getPin())
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
            Menu::createRandomIdFile(pin_);
            cout << "==========================================" << endl;
        }
        else
        {
            cout << endl << "===========6 digit numbers only!==========" << endl;
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
    cout << "====================Thank you for using our Application!=====================" << endl;
    exit(0);
}

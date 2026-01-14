#include <iostream>
#include <thread>
#include <chrono>
#include "ux.hpp"
using namespace std;

void welcome() // Coded by KONG WEI HANG
{
    cout << "______________________________________________________" << endl;
    cout << " __    __    ___  _        __   ___   ___ ___    ___  " << endl;
    cout << "|  |__|  |  /  _]| |      /  ] /   \\ |   |   |  /  _] " << endl;
    cout << "|  |  |  | /  [_ | |     /  / |     || _   _ | /  [_  " << endl;
    cout << "|  |  |  ||    _]| |___ /  /  |  O  ||  \\_/  ||    _] " << endl;
    cout << "|  `  '  ||   [_ |     /   \\_ |     ||   |   ||   [_  " << endl;
    cout << " \\      / |     ||     \\     ||     ||   |   ||     | " << endl;
    cout << "  \\_/\\_/  |_____||_____|\\____| \\___/ |___|___||_____| " << endl;
    cout << "______________________________________________________" << endl;     
    cout << "Welcome dear valued customers to our shopping list system site!"         << endl;
    cout << "We highly value the performance of our system in bringing our users: "                << endl;
    cout << "\t\t\t     THE BEST!!!"                                                                                  << endl;
    cout << "\t\t\t     THE SAFEST!!!"                                                                                 << endl;
    cout << "\t\t\t     THE SMOOTHEST!!!"                                                                               << endl;
    cout << "____________________________GROUP 44____________________________" << endl;
    cout << "" << endl;
};

void exitmessage()// Coded by KONG WEI HANG
{
    cout << " ________________________________________________________________" << endl;
    cout << "|                                                                |" << endl;
    cout << "|     Thanks For Using Shopping List ! Goodbye!                  |" << endl;
    cout << "|________________________________________________________________|" << endl;
    cout << "" << endl;
    cout << "" << endl;
}

void sleep(int time){
    this_thread::sleep_for(chrono::milliseconds(time*1000));
};

void sc_refresh(){
    cout << "\033[2J\033[1;1H";
};
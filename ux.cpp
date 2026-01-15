#include <iostream>
#include <thread>
#include <chrono>
#include "main.hpp"
using namespace std;

void welcome(){    // Coded by KONG WEI HANG
    int totalWidth = 124;
    string yellow = "\033[1;33m";
    string reset = "\033[0m";
    cout << "____________________________________________________________________________________________________________________________" << endl << endl;

    string paddingArt = string(30, ' ');
    cout << yellow; 
    cout << paddingArt << " __    __    _____  ___        ___    ____   _________  _____  " << endl;
    cout << paddingArt << "|  |__|  |  /  _ _] | |       /   ]  /     \\ |   |   | /  _ _] " << endl;
    cout << paddingArt << "|  |  |  |  |  [_ | |        /  /    |     | | _   _ | |  [_  " << endl;
    cout << paddingArt << "|  |  |  |  |    _] | |___  /  /     |  O  | |  \\_/  | |    _] " << endl;
    cout << paddingArt << "|  `  '  |  |   [_  |     | |   \\_   |     | |   |   | |   [_  " << endl;
    cout << paddingArt << "\\        /  |     | |     |  \\     | |     | |   |   | |     | " << endl;
    cout << paddingArt << " \\_/  \\_/   |_____| |_____|   \\____|  \\___/  |___|___| |_____| " << endl;
    cout << reset;
    cout << "____________________________________________________________________________________________________________________________" << endl << endl;

    cout << string(52, ' ') << yellow << "Shopping List System" << reset << endl;
    cout << string(45, ' ') << "A EEE123 mini project by Group 44" << endl << endl;
    cout << string(35, ' ') << "Group Leader : Kenny anak Sirai" << endl;
    cout << string(35, ' ') << "Group members: Raveen A/L Anbunathan" << endl;
    cout << string(35, ' ') << "               Huang Qi He" << endl;
    cout << string(35, ' ') << "               Kong Wei Hang" << endl;
    cout << string(35, ' ') << "               Muhammad Azrol Adli Bin Mohd Azerilakmar" << endl << endl;
    cout << "____________________________________________________________GROUP 44________________________________________________________" << endl;
    cout << endl;
}

void exitmessage() // Coded by KONG WEI HANG
{
    int totalWidth = 124;
    string red = "\033[1;31m";
    string reset = "\033[0m";
    string padding = string(29, ' ');
    cout << endl << endl;
    cout << padding << " ________________________________________________________________ " << endl;
    cout << padding << "|                                                                |" << endl;
    cout << padding << "|         " << "From Group 44:" << reset << "                                         |" << endl;
    cout << padding << "|         " << red << "Thanks for using our Shopping List! Goodbye!" << reset << "           |" << endl;
    cout << padding << "|________________________________________________________________|" << endl;
    cout << endl << endl;
}

void sleep(int time){                                  //sleep function to create delay in seconds
    this_thread::sleep_for(chrono::milliseconds(time*1000));
};

void sc_refresh(){                                     //clear screen function
    cout << "\033[2J\033[1;1H";
};


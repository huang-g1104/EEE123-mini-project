#include<iostream>
#include<cstring>
#include <thread>
#include<ctime>
using namespace std;

void sleep(int time){
    this_thread::sleep_for(chrono::milliseconds(time*100));
}

void sc_refresh(){
    cout << "\033[2J\033[1;1H";
}


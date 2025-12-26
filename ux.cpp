#include<iostream>
#include<cstring>
#include <thread>
#include<ctime>
using namespace std;

void sleep(int time){
    this_thread::sleep_for(chrono::milliseconds(time*1000));
}

void sc_refresh(){
    cout << "\033[2J\033[1;1H";
}


int thee() {
    // ANSI escape codes to set text color
    std::cout << "\033[31mThis is red text\033[0m" << std::endl;  // Red text
    std::cout << "\033[32mThis is green text\033[0m" << std::endl;  // Green text
    std::cout << "\033[33mThis is yellow text\033[0m" << std::endl;  // Yellow text
    std::cout << "\033[34mThis is blue text\033[0m" << std::endl;  // Blue text
    std::cout << "\033[1;35mThis is bold magenta text\033[0m" << std::endl;  // Bold Magenta text

    return 0;
}

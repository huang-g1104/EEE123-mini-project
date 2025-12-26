#include <iostream>
#include <ctime>
#include <thread>
#include "function.cpp"
using namespace std;

int main()
{

welcome();
this_thread::sleep_for(chrono::milliseconds(30000));
cout << "\033[2J\033[1;1H";

    
    return 0;
}

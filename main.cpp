#include <iostream>
#include <ctime>
#include <thread>
using namespace std;
#include "function.cpp"
int main()
{

welcome();
this_thread::sleep_for(chrono::milliseconds(30000));
cout << "\033[2J\033[1;1H";

    
    return 0;
}

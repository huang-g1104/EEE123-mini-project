#include <iostream>
#include <ctime>
#include <thread>
#include "function.cpp"
#include "list_interface.cpp"
#include "ux.cpp"

using namespace std;
vector<vector<string>>item;
void printTable() {
    header();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(5) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]     // Age
                 << endl;
        }
};


int main()
{
welcome();
this_thread::sleep_for(chrono::milliseconds(3000));
cout << "\033[2J\033[1;1H";
item.push_back({"Apple", "2024-05-15", "5"});
printTable();
    
    return 0;
}



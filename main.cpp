#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "function.cpp"
#include "list_interface.cpp"
#include "ux.cpp"
using namespace std;
vector<vector<string>>item;
string row[3]={"","",""};

int a;

void printTable() {
    sc_refresh();
    header();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]     // Age
                 << endl;
        }
};


int main(){
welcome();
sleep(5);
printTable();
cin>>a;
if(a=1){
        vector<string> personData(3);

        cout << "\nEnter item to be added:\n";
        cout << "Name: ";
        string name="";
        int X=sizeof(name);
        while (X=0){
        cin>>name; 
        }
        personData[0]=name;

        auto now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);
        tm* local_time = localtime(&now_c);
        char buffer[11];  
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
        string current_date = buffer;
        personData[1]=current_date;
        cout << "Quantity: ";
        getline(cin, personData[2]);

        item.push_back(personData);
        printTable();
    }
}





//item.push_back({"Apple", "2024-05-15", "5"});
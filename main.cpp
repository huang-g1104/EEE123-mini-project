#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "function.cpp"
#include "list_interface.cpp"
#include "ux.cpp"
using namespace std;
vector<vector<string>>item;
string row[3]={"","",""};
int a,b,refnumber;
string name;
int quantity;
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

void additem(){
    vector<string> personData(3);
    cout << "\nEnter item to be added:\n";
    cout << "Enter the name and the quantity of item:"<<"\n";

    cin>>name>>quantity;
       
    personData[0]=name;

    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_c);
    char buffer[11];  
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
    string current_date = buffer;
    personData[1]=current_date;
    string quantitystr=to_string(quantity);
    personData[2]=quantitystr;

    cout<<name<<quantity;
    item.push_back(personData);
        printTable();
}

int main(){
item.push_back({"Apple", "2024-05-15", "5"});
for(;;){
//welcome();
//sleep(5);
printTable();
cin>>a;

if(a=1 && a<2){
    additem();
    a=0;
    }
else if(a=2){
    cout<<"Press 1 to remove entire object"<<"\n";
    cout<<"Press 2 to remove a certain quantity of the object"<<"\n";
    b=0;
    cin>>b;
    if(b=1){
        cout<<"Which item to remove?";
        cin>>refnumber;
        item.erase(item.begin() + (refnumber)-1);
        printTable();
    }
    else{}
    }
else if(a=3){

}
else{
    
}
}
}
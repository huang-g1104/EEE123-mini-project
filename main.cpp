#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "function.cpp"
#include "list_interface.cpp"
#include "ux.cpp"
using namespace std;
                                                 //variable declarations
vector<vector<string>>item;
int a,b,c,refnumber;
string name, tempquan;
int quantity;
                                                 //function declarations
void printTable() {
    sc_refresh();
    toolbar();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]     // Age
                 << endl;
        }
};

void printAdditem() {
    sc_refresh();
    additem_mode();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]     // Age
                 << endl;
        }
};

void printRemoveitem() {
    sc_refresh();
    removeitem_mode();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]     // Age
                 << endl;
        }
};

void printChecklist(){
    sc_refresh();
    checklist_mode();
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
    printAdditem();
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
    quantity=0;
    item.push_back(personData);
    printTable();
}

void removeitem(){
    printRemoveitem();
    b=0;
    cin>>b;
    if(b==1){
        printRemoveitem();
        cout<<"Which item to remove?";
        cin>>refnumber;
        item.erase(item.begin() + (refnumber)-1);
        printTable();
        refnumber=0;
    }
    else if(b==2) {
        printRemoveitem();
        cout<<"Which item to remove?"<<"\n";
        cin>>refnumber;
        printRemoveitem();
        cout<<"Enter the quantity of the item to remove"; 
        cin>>quantity;
        tempquan=item[refnumber-1][2];
        quantity=atoi(tempquan.c_str())-quantity;
        string quantitystr=to_string(quantity);
        if(quantity>0){
            item[refnumber-1][2]= quantitystr;
        }
        else{
            item.erase(item.begin() + (refnumber-1));
        }
        refnumber=0;
        printTable();
    }
    else {
        cout<<"Enter a valid input";
        printTable;
    }
};

void checklist(){
    c=sizeof(item);
    b=3;
    while(c!=0 && b!=0){
        printChecklist();
        cin>>b;
        if(b!=0){
        item.erase(item.begin() + (b)-1);
        }
        else{
            break;
        }
    }
}

                                                 //main()
int main(){
item.push_back({"Apple", "2024-05-15", "5"});
item.push_back({"Orange", "2024-06-09", "20"});
item.push_back({"Pear", "2025-09-10", "4"});

welcome();
sleep(2);

a=10;
for(;;){
    b=0;
    if(a!=0){                                          //the loop starts here
        printTable();
        cin>>a;                                           //cue for functions
        if(a==1){
            additem();
            }
        else if(a==2){
            removeitem();
            b=0;
            }
        else if(a==3){
            cout<<"har";
        }
        else if(a==4){
            checklist();
        }
        else{

        }
    }
    else{
        sleep(1);
        exitmessage();
        sleep(3);
        return 0;
    }
}
}
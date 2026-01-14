#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include "list_array.hpp"
#include "ui.cpp"
using namespace std;

int refnumber, b, quantity; 
string tempquan;
double price;

void additem(){

    vector<string> waiter(4);
    string name="";

    printAdditem();
    cout << "Enter the name of the item:"<<"\n";
    cin>>name>>price>>quantity;
    waiter[0]=name;
    
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_c);
    char buffer[11];  
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
    string current_date = buffer;
    waiter[1]=current_date;
    
    string quantitystr=to_string(quantity);
    waiter[2]=quantitystr;

    price=price*quantity;
    ostringstream out;
    out<<fixed<<setprecision(2)<<price;
    string total_price=out.str();
    waiter[3]=total_price;
    quantity=0;
    item.push_back(waiter);
    
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
    int c=sizeof(item);
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
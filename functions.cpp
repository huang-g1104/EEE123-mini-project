#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
#include <limits>
#include "main.hpp"

using namespace std;

long long quantity;
int refnumber, b;
string tempquan;
long double price=0;

void additem(){
    vector<string> waiter(4);
    string name;
    printAdditem();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "the name of the item: ";
        cin >> name;
    if(name=="0"){
        printTable();
        return;
    }
    else if (name.empty()){
        cout<<"Item name cannot be empty. Please try again."<<"\n";
        return;
    }
    else if(name.length()>1 && name.length()<30 ){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "the quantity of the item: ";
        cin >> quantity;
        cout << "the price of the item ";
        cin >> price;
        if (cin.fail()&& price<0&& quantity<0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Invalid price input. Please enter a valid number for the price and quantity"<<"\n";
            return;
        }
        else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        price=0;
        item.push_back(waiter);
        printTable();
        }
    }
    else{
        cout<<"Item name must be between 1 and 30 characters. Please try again."<<"\n";
    }
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
        printTable();
    }
};

void checklist(){
    int c=item.size();
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

void clearlist(){
    printClearlist();
    cout<< "Are you sure you want to CLEAR the shopping list?"<<"\n";
    cout<< "Enter 5 to proceed"<<"\n";
    b=4;
    while(b!=0){
        cin>>b;
        if(b==5){
            printClearlist();
            cout<<"Clearing the shopping list."<<"\n";
            sleep(1.5);
            printClearlist();
            cout<<"Clearing the shopping list.."<<"\n";
            sleep(1.5);
            printClearlist();
            cout<<"Clearing the shopping list..."<<"\n";
            sleep(1.5);
            printClearlist();
            item.clear();
            printTable();
            break;
        }
        else if(b==0){
            break;
        }
        else{
            cout<<"Please enter a valid input"<<"\n";
        }
    }
}

void checkforschedule() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_c);
    char buffer[11];    
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);    
    string current_date = buffer;
    for (int i = schedule.size() - 1; i >= 0; i--) {

        if (schedule[i][1] > current_date) { 
            item.push_back(schedule[i]);
            schedule.erase(schedule.begin() + i);
        }
    }
}

void scheduleitem(){
    vector<string> waiter(4);
    string name;
    char schedule_date[11];
    printScheduleitem();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "the name of the item: ";
        cin >> name;
    if(name=="0"){
        printTable();
        return;
    }
    else if (name.empty()){
        cout<<"Item name cannot be empty. Please try again."<<"\n";
        return;
    }
    else if(name.length()>1 && name.length()<30 ){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "the quantity of the item: ";
        cin >> quantity;
        cout << "the price of the item ";
        cin >> price;
        if (cin.fail()&& price<0&& quantity<0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Invalid price input. Please enter a valid number for the price and quantity"<<"\n";
            return;
        }
        else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        waiter[0]=name;
        cout << "Enter the scheduled date (YYYY-MM-DD): ";
        cin>>schedule_date;
        waiter[1]=schedule_date;
    
        string quantitystr=to_string(quantity);
        waiter[2]=quantitystr;
        price=price*quantity;
        ostringstream out;
        out<<fixed<<setprecision(2)<<price;
        string total_price=out.str();
        waiter[3]=total_price;
        quantity=0;
        price=0;
        schedule.push_back(waiter);
        cout<<"Item scheduled successfully!"<<"\n";
        sleep(2);
        printTable();
        }
    }
    else{
        cout<<"Item name must be between 1 and 30 characters. Please try again."<<"\n";
    }
}
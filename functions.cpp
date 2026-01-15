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
    vector<string> waiter(4);     //temporary vector to hold item details   //key concepts: get data for each information of data
    string name;                                                            //add all the data to temporary vector then add to shopping list vector
    printAdditem();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
        cout << "Enter the name of the item to be added: ";
        getline(cin, name,'\n');
    if(name=="0"){      //exit condition
        printTable();
        return;
    }
    else if (name.empty()){
        cout<<"Item name cannot be empty. Please try again."<<"\n";
        return;
    }
    else if(name.length()>1 && name.length()<30 ){       //name length validation
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the quantity of the item to be added: ";
        cin >> quantity;
        cout << "Enter the price of the item to be added: ";
        cin >> price;
        if (cin.fail()|| price<0||quantity<0) {          //input validation
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout<<"Invalid price input. Please enter a valid number for the price and quantity"<<"\n";
            return;
        }
        else{
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        waiter[0]=name;  //assign name of item to temporary vector

        auto now = chrono::system_clock::now();      //get current date
        time_t now_c = chrono::system_clock::to_time_t(now);
        tm* local_time = localtime(&now_c);
        char buffer[11];  
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);
        string current_date = buffer;
        waiter[1]=current_date;           //get current date as string then assign to temporary vector
    
        string quantitystr=to_string(quantity);
        waiter[2]=quantitystr;            //assign quantity to temporary vector

        price=price*quantity;             //calculate total price of the item
        ostringstream out;
        out<<fixed<<setprecision(2)<<price;
        string total_price=out.str();
        waiter[3]=total_price;            //assign total price to temporary vector
        quantity=0;
        price=0;
        item.push_back(waiter);           //add temporary vector to shopping list vector
        printTable();                      //refresh table display
        }
    }
    else{
        cout<<"Item name must be between 1 and 30 characters. Please try again."<<"\n";
    }
}

void removeitem(){
    printRemoveitem();
    b=0;
    cin>>b;                                //cue for remove functions
    if(b==1){
        printRemoveitem();
        cout<<"--Remove entire item--"<<"\n";
        cout<<"Enter the index number of the item to be removed: ";
        cin>>refnumber;
        item.erase(item.begin() + (refnumber)-1);           //remove item from vector (entire row)
        printTable();
        refnumber=0;
    }
    else if(b==2) {
        printRemoveitem();
        cout<<"--Remove by quantity--"<<"\n";
        cout<<"Enter the index number of the item to be removed: "<<"\n";
        cin>>refnumber;
        printRemoveitem();
        cout<<"--Remove by quantity--"<<"\n";
        cout<<"Enter the quantity of the item to be removed: "; 
        cin>>quantity;
        tempquan=item[refnumber-1][2];                     //store original quantity in temp variable
        quantity=atoi(tempquan.c_str())-quantity;          //calculate new quantity after removal
        string quantitystr=to_string(quantity);
        if(quantity>0){
            item[refnumber-1][2]= quantitystr;              //update quantity if still greater than 0
        }
        else{
            item.erase(item.begin() + (refnumber-1));       //remove entire item if quantity is 0 or less
        }
        refnumber=0;
        printTable();
    }
    else {
        cout<<"Enter a valid input";
        printTable();
    }
};

void checklist(){                                       //remove by item made into a function
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
    cout<< "\033[31mAre you sure you want to CLEAR the entire shopping list?\033[0m"<<"\n";
    cout<< "Enter 5 to proceed"<<"\n";
    b=4;
    while(b!=0){
        cin>>b;
        if(b==5){
            printClearlist();
            cout<<"Clearing the shopping list."<<"\n";              //clearing animation
            sleep(1.5);
            printClearlist();
            cout<<"Clearing the shopping list.."<<"\n";
            sleep(1.5);
            printClearlist();
            cout<<"Clearing the shopping list..."<<"\n";
            sleep(1.5);
            printClearlist();
            item.clear();                                          //clear the shopping list vector
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

void checkforschedule() {                     //check for scheduled items whose date is today or earlier
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_c);
    char buffer[11];    
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", local_time);    
    string current_date = buffer;
    for (int i = schedule.size() - 1; i >= 0; i--) {                //iterate backwards to safely remove items
        if (schedule[i][1] > current_date) { 
            item.push_back(schedule[i]);                //add scheduled item to shopping list
            schedule.erase(schedule.begin() + i);       //remove item from schedule list
        }
        else {
            continue;
        }
    }
}

void scheduleitem(){                                    //similar to additem function but adds to schedule vector instead
    vector<string> waiter(4);                           //items scheduled will be added to shopping list via iteration in checkforschedule function 
    string name;
    char schedule_date[11];
    printScheduleitem();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter the name of the item to be scheduled: ";
        getline(cin, name,'\n');
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
        cout << "Enter the quantity of the item to be scheduled: ";
        cin >> quantity;
        cout << "Enter the index number of the item to be scheduled: ";
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
        cout<<"Adding the item to schedule."<<"\n";
        sleep(1.5);
        printScheduleitem();
        cout<<"Adding the item to schedule.."<<"\n";
        sleep(1.5);
        printScheduleitem();
        cout<<"Adding the item to schedule..."<<"\n";
        sleep(1.5);
        cout<<"Item scheduled successfully!"<<"\n";
        sleep(1);
        printTable();
        }
    }
    else{
        cout<<"Item name must be between 1 and 30 characters. Please try again."<<"\n";
    }
}
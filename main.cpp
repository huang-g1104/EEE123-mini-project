#include <iostream>
#include <fstream>
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
string tempquan;
int quantity;
double price;
                                                 //function declarations
void printTable() {
    sc_refresh();
    toolbar();
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   // Row number (1-based index)
                 << setw(80) << item[i][0]     // Name
                 << setw(20) << item[i][1]     // Height
                 << setw(10) << item[i][2]
                 << setw(10) << item[i][3]     // Age
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
                 << setw(10) << item[i][2]
                 << setw(10) << item[i][3]     // Age
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
                 << setw(10) << item[i][2]
                 << setw(10) << item[i][3]     // Age
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
                 << setw(10) << item[i][2]
                 << setw(10) << item[i][3]     // Age
                 << endl;
    }
};

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

ifstream input("shoppinglist.txt");
string line;

while (getline(input, line)) {
    stringstream ss(line);
    vector<string> row;
    string field;

        // Extract exactly 4 fields
    for (int i = 0; i < 4; i++) {
        if (getline(ss, field, '|')) {
                row.push_back(field);
        }
    }
        // Safety check: only push valid rows
    if (row.size() == 4) {
        item.push_back(row);
    }
}

    input.close();




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
    ofstream output;
    output.open("shoppinglist.txt");
    for (size_t i = 0; i < item.size(); i++){
        output<<item[i][0]<<"|"<<item[i][1]<<"|"<<item[i][2]<<"|"<<item[i][3]<<endl;
    }
    output.close();
        sleep(1);
        exitmessage();
        sleep(3);
        return 0;
    }
}
}
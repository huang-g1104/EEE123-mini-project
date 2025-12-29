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
string row[3]={"","",""};
int a,b,refnumber;
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
void printEditList() {
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

void additem(){                //to add item into the list
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

void removeitem(){                 //to remove item from the list
    printRemoveitem();
    cout<<"Press 1 to remove entire object"<<"\n";
    cout<<"Press 2 to remove a certain quantity of the obje1ct"<<"\n";
    cout<<"Press 0 to exit" <<"\n"; 
    b=0;
    cin>>b;
    if(b==1){
        printRemoveitem();
        cout<<"Which item to remove?" <<"\n"; 
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
}
    void edititem(){            //to edit item in the list
    int b = 3;
    printTable();

    cout << "Which item do you want to edit? ";
    cin >> refnumber;

    if(refnumber < 1 || refnumber > item.size()){   // Validate index
        cout << "Invalid item number!";
        sleep(2);
        return;
    }

    cout << "[1] Edit name\n";
    cout << "[2] Edit quantity\n";
    cout << "[0] Cancel\n";
    cout << "Choose: ";
    cin >> b;

    cin.ignore(); // important for getline

    if(b == 1){
        string newName;
        cout << "Enter new name: ";
        getline(cin, newName);
        item[refnumber - 1][0] = newName;
    }
    else if(b == 2){
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        item[refnumber - 1][2] = to_string(newQuantity);
    }

    
    else {
        cout<<"Enter a valid input";
        printTable;
    }
    }
    
;

                                                 //main()
int main(){
item.push_back({"Apple", "2024-05-15", "5"});
item.push_back({"Orange", "2024-06-09", "20"});
item.push_back({"Pear", "2025-09-10", "4"});
welcome();
sleep(5);

for(;;){                                          //the loop starts here
a=b=0;
printTable();
cin>>a;                                           //cue for functions
cin.clear();
cin.ignore(1000, '\n');

if(a==1){
    additem();
    a=0;
    }
else if(a==2){
    removeitem();
    a=0;
    b=0;
    }
else if(a==3){
    edititem();
    a=0;
}

else if(a==4){
    //checklist mode
}
else if(a==5){
     exitmessage();
    sleep(4);
    break;
}
else{
    cout<<"Invalid Input, Please Try Again"<<endl;
    sleep(2);
}
}
}
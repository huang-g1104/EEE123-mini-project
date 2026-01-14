#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include "list_array.hpp"
#include "ui.hpp"
#include "ux.hpp"
using namespace std;
int i;
char borderline[125]="____________________________________________________________________________________________________________________________";

void toolbar(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[6]{"[1] Add Item", "[2] Remove Item", "[3] Edit Item", "[4] Checklist mode","[5] Clear list","[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]
    << setw(23) << toolbar[5]         
    << endl;
cout<<borderline<<endl;
string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]         
    << setw(20) << hder[2]        
    << setw(10) << hder[4]
    << setw(10) << hder[4]         
    << endl;
};

void additem_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;32mADD ITEM\033[0m","", "", "", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]         
    << setw(20) << hder[2]        
    << setw(10) << hder[3]
    << setw(10) << hder[4]        
    << endl; 
}

void removeitem_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;31mREMOVE ITEM\033[0m","[1] Remove by item", "[2] Remove item by quantity","", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]
    << setw(20) << hder[2]
    << setw(10) << hder[3]
    << setw(10) << hder[4]
    << endl; 
}

void checklist_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;34mCHECKLIST MODE\033[0m", "", "", "", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]
    << setw(20) << hder[2]
    << setw(10) << hder[3]
    << setw(10) << hder[4]
    << endl; 
}

void clearlist_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;34mCLEAR SHOPPING LIST\033[0m", "", "", "", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]
    << setw(20) << hder[2]
    << setw(10) << hder[3]
    << setw(10) << hder[4]
    << endl; 
}

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

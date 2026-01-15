#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include "main.hpp"

using namespace std;
int i;
char borderline[127]="______________________________________________________________________________________________________________________________";


void header(){                                                                      //table header
    string hder[5]{"No.", "| items", "| Date added", "| Quantity","| Price"};
    cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]
    << setw(20) << hder[2]
    << setw(10) << hder[4]
    << setw(10) << hder[4]
    << endl;
}

void printlist(){                                                                   //print shopping list table 
    for (size_t i = 0; i < item.size(); i++) {
            cout << left << setw(7) << (i + 1)   //Row number (1-based index)
                 << setw(80) << item[i][0]       //item name
                 << setw(20) << item[i][1]       //time added
                 << setw(10) << item[i][2]       //quantity
                 << setw(10) << item[i][3]       //price
                 << endl;
    }
    for (int j=0;j<(20-item.size());j++){
        cout<<endl;
    }
    cout<<borderline<<endl;
    cout<<"Total: "<<right<<fixed<<setprecision(2)<<setw(112)<<"RM "<<totalprice()<<endl;
    cout<<borderline<<endl;

}

void toolbar(){                                                                     //main toolbar display                                           
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[6]{"[1] Add Item", "[2] Remove Item", "[3] Schedule", "[4] Checklist Mode","[5] Clear list","[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]
    << setw(23) << toolbar[5]         
    << endl;
cout<<borderline<<endl;
header();
};

void additem_mode(){                                                                //additem toolbar display
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
header();
}

void removeitem_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;35mREMOVE ITEM\033[0m","[1] Remove by item", "[2] Remove item by quantity","", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
header();
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
header();
}

void clearlist_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;31mCLEAR SHOPPING LIST\033[0m", "", "", "", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
header();
}

void scheduleitem_mode(){
cout<<"\033[1;33mShopping List System\033[0m"<<"      "<<"\033[33mby Group 44\033[0m"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"\033[1;38mSCHEDULE AN ITEM\033[0m", "", "", "", "[0] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
header();
}

void printTable() {                                                                  //print main toolbar with shopping list
    sc_refresh();
    toolbar();
    printlist();
    
};

void printAdditem() {
    sc_refresh();
    additem_mode();
    printlist();
};

void printRemoveitem() {
    sc_refresh();
    removeitem_mode();
    printlist();
};

void printChecklist(){
    sc_refresh();
    checklist_mode();
    printlist();
};

void printClearlist(){
    sc_refresh();
    clearlist_mode();
    printlist();
};

void printScheduleitem(){
    sc_refresh();
    scheduleitem_mode();
    printlist();
};
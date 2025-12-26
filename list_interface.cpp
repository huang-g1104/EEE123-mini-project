#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int i;
char borderline[116]="___________________________________________________________________________________________________________________";

void header(){
cout<<"Shopping List System       by Group 44"<<endl;
cout<<borderline<<endl;
string toolbar[5]{"[1] Add Item", "[2] Delete Item", "[3] Edit Item", "[4] Checklist mode", "[5] Exit"};
cout<< left << setw(23) << toolbar[0]
    << setw(23) << toolbar[1]         
    << setw(23) << toolbar[2]        
    << setw(23) << toolbar[3]
    << setw(23) << toolbar[4]         
    << endl;
cout<<borderline<<endl;
string hder[4]{"No.", "| items", "| Date added", "| Quantity"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]         
    << setw(20) << hder[2]        
    << setw(10) << hder[3]         
    << endl;
};

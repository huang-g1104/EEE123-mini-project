#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int i;

void borderline(){
    while(i<115){cout<<"_"; i++;}
    cout<<endl;
}

void header(){
string hder[4]{"No.", "| items", "| Date added", "| Quantity"};
cout<< left << setw(5) << hder[0]
    << setw(80) << hder[1]         
    << setw(20) << hder[2]        
    << setw(10) << hder[3]         
    << endl;
};

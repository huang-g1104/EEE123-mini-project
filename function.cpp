#include <iostream>
using namespace std;


void welcome() // Coded by KONG WEI HANG
{
    cout << "______________________________________________________" << endl;
    cout << " __    __    ___  _        __   ___   ___ ___    ___  " << endl;
    cout << "|  |__|  |  /  _]| |      /  ] /   \\ |   |   |  /  _] " << endl;
    cout << "|  |  |  | /  [_ | |     /  / |     || _   _ | /  [_  " << endl;
    cout << "|  |  |  ||    _]| |___ /  /  |  O  ||  \\_/  ||    _] " << endl;
    cout << "|  `  '  ||   [_ |     /   \\_ |     ||   |   ||   [_  " << endl;
    cout << " \\      / |     ||     \\     ||     ||   |   ||     | " << endl;
    cout << "  \\_/\\_/  |_____||_____|\\____| \\___/ |___|___||_____| " << endl;
    cout << "______________________________________________________" << endl;     
    cout << "Welcome dear valued customers to our shopping list system site!"         << endl;
    cout << "We highly value the performance of our system in bringing our users: "                << endl;
    cout << "\t\t\t     THE BEST!!!"                                                                                  << endl;
    cout << "\t\t\t     THE SAFEST!!!"                                                                                 << endl;
    cout << "\t\t\t     THE SMOOTHEST!!!"                                                                               << endl;
    cout << "_______________________GROUP 44 WELCOME U_______________________" << endl;
    cout << "" << endl;
}

string add_item(){
    string mtrow[3]={0,0,0};
    string item_name,item_date,item_quantity;
    cout<<"\033[2J\033[1;1H";
    cout<<"\033[1;32ADD ITEM\033[0m"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter the name of item to be added" && cin>>item_name;
    mtrow[0]=item_name;
    cout<<"Enter the name of item to be added" && cin>>item_date;
    mtrow[1]=item_date;
    cout<<"Enter the name of item to be added" && cin>>item_quantity;
    mtrow[2]=item_quantity;
    return mtrow[3];
}
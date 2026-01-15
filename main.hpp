#ifndef UI_H
#define UI_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

extern long long quantity;  //from fucntions.cpp
extern int refnumber, b;
extern long double price;

void additem();
void removeitem();
void checklist();
void clearlist();

void loadfromfile(string filename); //from io_functions.cpp
void savetofile(string filename); 

extern vector<vector<string>>item; //from list_array.cpp
long double totalprice();

void toolbar(); //from ui.cpp
void additem_mode();
void removeitem_mode();
void checklist_mode();
void clearlist_mode();
void printTable();
void printAdditem();
void printRemoveitem();
void printChecklist();
void printClearlist();

void welcome(); //from ux.cpp
void exitmessage();
void sleep(int);
void sc_refresh();

#endif
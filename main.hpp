#ifndef UI_H
#define UI_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

extern long long quantity;                                                     //from fucntions.cpp
extern int refnumber, b;
extern long double price;

void additem();
void removeitem();
void checklist();
void clearlist();
void checkforschedule();
void scheduleitem();

void loadfromfile(string filename, vector<vector<string>>& targetVector);   //from io_functions.cpp
void savetofile(string filename);
void savetoschedule(string filename);

extern vector<vector<string>>item;                                          //from list_array.cpp
extern vector<vector<string>>schedule;
long double totalprice();

void toolbar();                                                             //from ui.cpp
void additem_mode();
void removeitem_mode();
void checklist_mode();
void clearlist_mode();
void scheduleitem_mode();

void printTable();
void printAdditem();
void printRemoveitem();
void printChecklist();
void printClearlist();
void printScheduleitem();

void welcome();                                                              //from ux.cpp
void exitmessage();
void sleep(int);
void sc_refresh();

#endif
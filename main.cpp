#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "main.hpp"

using namespace std;
int a;
                                                 //variable declaration
int main(){

loadfromfile("shoppinglist.txt",item);
loadfromfile("schedule.txt",schedule);
sc_refresh();
welcome();
sleep(2);
checkforschedule();

a=10;
for(;;){
    b=0;
    printTable();
    for (size_t i = 0; i < schedule.size(); i++) {
        cout << left << setw(7) << (i + 1)   //Row number (1-based index)
        << setw(80) << schedule[i][0]       //schedule name
        << setw(20) << schedule[i][1]       //time added
        << setw(10) << schedule[i][2]       //quantity
        << setw(10) << schedule[i][3]       //price
        << endl;  
    }                                  //the loop starts here
    cin>>a;                                           //cue for functions
    if(a==1){
        additem();
        a=10;
    }
    else if(a==2){
        removeitem();
        b=0;
        a=10;
    }
    else if(a==3){
        scheduleitem();
        a=10;    
    }
    else if(a==4){
        checklist();
        a=10;
    }
    else if (a==5){
        clearlist();
        a=10;
    }
    else if(a==0){
        savetofile("shoppinglist.txt");
        savetoschedule("schedule.txt");
        exitmessage();
        sleep(3);
        return 0;
    }
    else{
        cout<<"Please enter a valid input"<<"\n";
        a=10;
    }   

}
}
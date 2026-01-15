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
    printTable();                                                       //the loop starts here
    cin>>a;                                                              //cue for functions
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
        savetofile("shoppinglist.txt");                   //save shopping list to file upon exit
        savetoschedule("schedule.txt");                   //save schedule list to file upon exit 
        exitmessage();
        sleep(3);
        return 0;
    }
    else{
        cout<<"Please enter a valid input"<<"\n";           //invalid input handling
        a=10;
    }   

}
}
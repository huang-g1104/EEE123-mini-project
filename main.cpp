#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "functions.hpp"
#include "list_array.hpp"
#include "io_functions.hpp"
#include "ux.hpp"
#include "ui.hpp"

int a;
using namespace std;
                                                 //variable declaration
int main(){

loadfromfile("shoppinglist.txt");

welcome();
sleep(2);

a=10;
for(;;){
    b=0;
    if(a!=0){                                          //the loop starts here
        printTable();
        cin>>a;                                           //cue for functions
        if(a==1){
            additem();
            }
        else if(a==2){
            removeitem();
            b=0;
            }
        else if(a==3){
            cout<<"har";
        }
        else if(a==4){
            checklist();
        }
        else{

        }
    }
    else{
        savetofile("shoppinglist.txt");
        sleep(1);
        exitmessage();
        sleep(3);
        return 0;
    }
}
}
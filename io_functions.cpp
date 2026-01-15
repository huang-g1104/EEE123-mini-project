#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "main.hpp"
using namespace std;    

void loadfromfile(string filename, vector<vector<string>>& targetVector) {  //generalized load function for both shopping list and schedule
    targetVector.clear(); 
    ifstream input(filename);
    string line;
    if (!input.is_open()) return; 

    while (getline(input, line)) {
        stringstream ss(line);
        vector<string> row;
        string field;
        for (int i = 0; i < 4; i++) {
            if (getline(ss, field, '|')) {
                row.push_back(field);
            }
        }
        if (row.size() == 4) {
            targetVector.push_back(row); // Saves to the vector you passed in
        }
    }
    input.close();
}

void savetofile(string filename){                           //save shopping list to external file
    ofstream output;
    output.open(filename);
    for (size_t i = 0; i < item.size(); i++){
        output<<item[i][0]<<"|"<<item[i][1]<<"|"<<item[i][2]<<"|"<<item[i][3]<<endl;
    }
    output.close();
}

void savetoschedule(string filename) {                        //save schedule list to external file
    ofstream output(filename);
    // Use schedule.size(), not item.size()
    for (size_t i = 0; i < schedule.size(); i++) {
        output << schedule[i][0] << "|" 
               << schedule[i][1] << "|" 
               << schedule[i][2] << "|" 
               << schedule[i][3] << endl;
    }
    output.close();
}
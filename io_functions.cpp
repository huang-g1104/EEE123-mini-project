#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "list_array.hpp"
#include "io_functions.hpp"
using namespace std;    


void loadfromfile( string filename){
    ifstream input(filename);
    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        vector<string> row;
        string field;

        // Extract exactly 4 fields
        for (int i = 0; i < 4; i++) {
            if (getline(ss, field, '|')) {
                    row.push_back(field);
            }
        }
        // Safety check: only push valid rows
        if (row.size() == 4) {
            item.push_back(row);
    }
}
    input.close();
}

void savetofile(string filename){
    ofstream output;
    output.open(filename);
    for (size_t i = 0; i < item.size(); i++){
        output<<item[i][0]<<"|"<<item[i][1]<<"|"<<item[i][2]<<"|"<<item[i][3]<<endl;
    }
    output.close();
}
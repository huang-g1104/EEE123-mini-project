#include <vector>
#include <string>
#include "main.hpp"
using namespace std;    

vector<vector<string>>item;          //shopping list vector
vector<vector<string>>schedule;      //schedule list vector

long double totalprice(){            //calculate total price of shopping list
    long double sum=0;
    long double x=0.0;
    for (size_t i = 0; i < item.size(); i++){
        x=stod(item[i][3]);                  //x is price converted to double for calculation 
        sum=sum +x;
        x=0;    
    }
    return sum;
    sum=0;
}


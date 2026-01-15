#include <vector>
#include <string>
#include "main.hpp"
using namespace std;    

vector<vector<string>>item;
vector<vector<string>>schedule;

long double totalprice(){
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


#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus

using namespace std;

typedef vector<int> vi;

void calculate(vector< vector<int> > nums,int size){        
    for(int i= 0;i<size;i++){
        
    }
}


int main(){

    int vals,cels;
    cin >> vals;
    cin >> cels;
    vector< vector<int> > nums;
    vi row;
    for(int j=0;j<cels;j++){
        int time,x,y;
        cin >> time;
        cin >> x;
        cin >> y;
        row.push_back(time);
        row.push_back(y);
        row.push_back(x);
        nums.push_back(row);
        row.clear();
    }
    calculate(nums,cels);
}

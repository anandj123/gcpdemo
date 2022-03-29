#include<iostream>
#include<vector>
#include <numeric>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int v;
        cin >> v;
        if (v == 1) {
            cout << 0 << endl;
            continue;
        }

        /*
           1 = 0,
           2 = 1
           3 = 2
           4 = 2
           5 = 3
           6 = 3
           7 = 4
           8 = 4
           9 = 5
           10 = 5
           11 = 6
           12 = 6
           13 = 7
           14 = 7
           15 = 8
           16 = 8
           17 = 9
           18 = 9
           19 = 10
           20 = 10
           21 = 11
           22 = 11

        */

        int sq = ceil(sqrt(v));        
        int copy = (int) v / sq;
        int remainder = v % sq;
        if (remainder > 0)  {
            remainder = 1;
        }
        cout <<  sq - 1 + copy - 1  + remainder << endl;
    }
}
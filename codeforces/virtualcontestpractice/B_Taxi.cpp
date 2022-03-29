#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int output = 0;
    int n;
    int buckets[3] = {};
    cin >> n;
    
    for (int i=0;i<n;i++){
        int val;
        cin >> val;
        output += val/4;
        int rem = val % 4;
        if (rem == 0) continue;

        if (buckets[3-rem] > 0){
            buckets[3-rem]--;
            output++;
        } else {
            buckets[rem-1] ++;
            
        }
    }
    
    if (buckets[0] - buckets[2] < 0) buckets[0] = 0; // singles and 3 group paired
    output += buckets[1] / 2; // 2 person groups paired
    buckets[1] %= 2;
    if (buckets[1] > 0) {
        buckets[1] = 1;
        buckets[0] -= 2 * buckets[1]; // 2 singles can be paired with a 2 person group
        if (buckets[0] < 0) buckets[0] = 0;
    }
    
    output += buckets[0] /4;
    buckets[0] %= 4;
    if (buckets[0] > 0) {
        buckets[0] = 1;
    }
    
    for(int i=0;i<3;i++){
        output += buckets[i];
    }
   
    cout << output;
    
}
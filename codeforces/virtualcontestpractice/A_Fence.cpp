#include<iostream>
#include<cmath>

using namespace std;

void calculate(int val[]){
    int diff = abs(val[0] - val[1]); 
    int ans = ceil(sqrt(pow(diff,2) + pow(val[2],2)));
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int val[3] = {};
        cin >> val[0];
        cin >> val[1];
        cin >> val[2];
        calculate(val);
    }
}

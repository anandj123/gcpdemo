#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int n;
    cin >> n;
    int output=0;
    for(int i=0;i<n;i++){
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        int sum = 0;
        sum = accumulate(a,a+3,sum);
        if (sum >= 2) {
            output++;
        }
    }
    cout << output;
}
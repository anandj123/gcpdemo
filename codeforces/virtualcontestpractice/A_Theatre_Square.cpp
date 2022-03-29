#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long unsigned n,m,a;
    cin >> n >> m >> a;
    long long x = (n+a-1)/a;
    long long y = (m+a-1)/a;
    cout << x * y;
}
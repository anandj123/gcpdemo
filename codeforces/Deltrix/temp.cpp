#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n = 1410165407;
    for(long long i = 200000;i>2;--i){
        if (n%i == 0) cout << i<< endl;
    }
}
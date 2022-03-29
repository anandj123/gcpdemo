#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

bool isPrime(int n){
    for(int i=2;i*i<=n;++i) if (n%i == 0) return false;
    return true;
}
int main(){
    vector<int> a = {5, 6, 7, 8, 9, 10};
    for (int i=0;i<(int) a.size(); ++i) {
        cout << a[i] << " : " << isPrime(a[i]) << endl;
    }
}
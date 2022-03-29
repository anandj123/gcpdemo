#include <iostream>
#include <string>
#include <algorithm>
#define out(x) cerr << #x << " " << (x) << "\n"; 
using namespace std;
int main(){
    int k;
    cin >>k;
    for(int i=0;i<k;i++){

        int n=0,output=0;
        cin >> n;
        string s;
        cin >> s;
        int l=0,m=0;
        
        for(int j=0;j<n;j++){
            if(s.at(j) == '>') ++l;
            if(s.at(j) == '<') ++m;
        }
        //out(l);
        //out(m);
        if(l == n or m == n) {
            cout << n << '\n';
            continue;
        }
        if(l ==0 or m ==0) {
            cout << n << "\n";
            continue;
        }
        for(int j=0;j<n;j++){
            int L,R;
            if(j-1 < 0){
                L = j-1+n;
            } else {
                L = j-1;
            }
            R = j;
            if(s.at(L) == '-' or s.at(R) == '-') {
                output++;
                continue;
            }
        }
        cout << output << '\n';
        
    }
}
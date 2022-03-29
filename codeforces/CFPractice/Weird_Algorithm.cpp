#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {
    long long n;
    cin >> n;
    cout << n << " ";
    while(n != 1){
        if(n%2 != 0) {
            n = n * 3 + 1;
            cout << n << " ";
        } else {
            n = n / 2;
            cout << n << " ";
        }
    }
}

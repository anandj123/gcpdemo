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
    int t;
    cin >> t;
    REP(i,0,t){
        int n;
        cin >> n;
        vi v (n);
        REP(j,0,n){
            cin >> v[j];
        }
        int output=0,run=0;
        bool f = false, s = false;
        REP(j,0,n){
            if(v[j] == 1) f = true;
            if (f and v[j] == 0) run++;
            if(f and v[j] == 1) {
                output += run;
                run = 0;
            }
        }
        cout << output << "\n";
    }
}

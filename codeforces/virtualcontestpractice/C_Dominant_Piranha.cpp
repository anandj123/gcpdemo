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
    REP(N,0,t){
        int n;
        cin >> n;
        vi val(n);
        REP(i,0,n){
            cin >> val[i];
        }
        int m = 0;
        REP(j,0,n){
            m = max(m,val[j]);
        }
        
        int output = -1;
        if (n == 1){
            cout << 1 << "\n";
            continue;
        }
        REP(j,0,n){
            if(val[j] == m){
                if(j>0 and val[j-1] < val[j]){
                    output = j + 1;
                    break;
                }
                if(j<n-1 and val[j+1] < val[j]){
                    output = j + 1;
                    break;
                }
            }
        }
        cout << output << "\n";

    }
}

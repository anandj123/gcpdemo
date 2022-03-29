#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)
#define endl "\n"

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
int INF = 1e9;

void calculate(int a, int b, string s) {
    int len = s.length();
    vector<int> dp1(len,0);
    vector<int> dp2(len,0);
    // debug(s);
    // debug(len);
    int first = a;
    REP(i,0,len){
        //debug(dp1[i-1]);
        //debug(dp2[i-1]);
        if(s[i] == '1') {
            
            dp1[i] = min((i>0?dp1[i-1]:0) + a, (i>0?dp1[i-1]:0) + (i>0?dp2[i-1]:0)+first);
            dp2[i] = 0;
            first = 0;
        } else {
            dp1[i] = (i>0?dp1[i-1]:0);
            dp2[i] = (i>0?dp2[i-1]:0)+ b;
        }

        // debug(dp1[i]);
        // debug(dp2[i]);
        // debug(i);
    }

    cout << dp1[len-1] << endl;
}
int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int a, b;
        string s;
        cin >> a >> b >> s;
        calculate(a,b,s);
    }
}

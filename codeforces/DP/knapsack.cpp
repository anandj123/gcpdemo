#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
#include<cmath>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {
    int W = 10;
    int N = 4;
    vector<int> val = {10,40,30,50};
    vector<int> w = {5,4,6,3};
    int ans = 90;
    vector< vector<int> > dp (N+1, vector<int>(W+1));

    for(int i = 0; i<N;i++){
        for(int j = 0;j<=W; j++){
            int included = 0;
            if (j < w[i]) {
                included = 0;
            } else {
                included = dp[(i<1? 0:i-1)][j-w[i]] + val[i];
            }
            
            int notincluded = dp[(i<1?0:i-1)][j];
            dp[i][j] = max(included, notincluded); 
        }
    }
    for(int i=0; i<N;i++){
        for(int j =0;j<W; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";        
    }
    cout << "\n";

}

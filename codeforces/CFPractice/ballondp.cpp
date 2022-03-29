#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {
    int A[] = {3,1,5,8};

    vector< vector<int> > dp(4, vector<int>(4));

    for(int L=3;L>=0;L--){
        for (int R=L;R<4;R++){
            for (int i=L; i<=R;i++){
                dp[L][R] = max(dp[L][R],
                                (L?A[L-1]:1)*A[i]*(R>=3?1:A[R+1]) +
                                (L<=i-1?dp[L][i-1]:0) +
                                (i+1<=R?dp[i+1][R]:0)
                            );
            }
        }
    }
    cout << dp[0][3] << endl;

}

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
    int T;
    cin >> T;
    for(int k=0;k<T;k++){
        int n,m;
        cin >> n >> m;
        int sum = 0;
        for(int i=0;i<n;i++){
            int v;
            cin >> v;
            sum += v;
        }
        if(sum == m){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

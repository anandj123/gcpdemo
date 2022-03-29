#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
int INF = 1e9;
int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int N, X;
        cin >> N >> X;
        vector<int> a(N),b(N);

        for(int i=0;i<N;i++){
            cin >> a[i];
        }
        for(int i=0;i<N;i++){
            cin >> b[i];
        }
        int ans = true;
        for(int i=0;i<N;i++){
            if(a[i] + b[N-i-1] > X) {
                ans = false;
                break;
            }
        }
            
        if (ans) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
        
    }
}

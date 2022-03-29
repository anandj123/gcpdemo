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
    for(int kk=0;kk<T;kk++){
        int n, x;
        cin >> n >> x;
        int ans = 1;
        if (n <=2){
            cout << 1 << endl;
            continue;
        }
        n -=2; //first floor
        if (n % x > 0) {
            ans += 1;
        } 
        ans += n / x ;
        cout << ans << endl;
    }
}

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
    while (T-- > 0){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max (a+b, c+d) << "\n";
    }
}

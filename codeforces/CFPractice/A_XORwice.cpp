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
    while(T-- >0){
        int a, b;
        cin >> a >> b;

        // value that will make the sum minimum is (a and b)
        int num = a & b;

        int ans = (a ^ num) + (b ^ num);

        // a xor b = (a and not b) or (b and not a)
        // a xor b = a * ~b + b * ~a
        // if we multiply a * b to it and simplify we get the following expression
        ans = (~a & b) + (~b & a);

        cout << ans << endl;
    }
}

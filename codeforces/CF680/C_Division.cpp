#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>


using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        long long p,q;
        cin >> p >> q;
        int g = __gcd(p,q);

        int n = p/g;
        //debug(__lcm(p,q));
        //long long a = sqrt(p);
        for(int i=n;i>1;i--){
            debug(i);
            debug(g);
            if (p  % (i*g) == 0 and (i *g) % q > 0) {
                cout << i *g << "\n";
                break;
            }
        }
    }
}

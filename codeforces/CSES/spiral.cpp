#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<set>
#include<assert.h>
#include<queue>
#include<stack>
#include<unordered_set>
#include<fstream>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define REP(i,a,b) for(int i=a; i<b;++i)
#define endl "\n"
#define F first
#define S second
#define MP make_pair 
#define PB push_back
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c,x) != c.end())

typedef pair< int,int > ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vvi;
int INF = 1e9;

ll ringN(ll y, ll x) {
    if (y >= x) return y;
    return x;
}
pair<ll, ll> ringStartEnd(ll ring){
    if (ring == 1) return MP(1,1);

    ll size = 2 * ring - 1;
    
    ll start = (ring - 1) * (ring - 1) + 1;
    ll end = start + size - 1;
    
    debug() << imie(size) imie(start) imie(end);
    return MP(start, end);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//     {
//         ifstream test("/Users/anandjain/Downloads/test_output.txt");
//         ifstream user("/Users/anandjain/Downloads/user_output.txt");
//         if (!test){
//             cout << "Cannot open test file" << endl;
//         }
//         if (!user){
//             cout << "Cannot open user output file" << endl;
//         }
//         string a, b;
//         int counter = 0;
//         while( getline( test, a ) ) {
//             counter ++;
//             getline( user, b );
//             if (a != b) {
//                 cout << counter << endl;
//                 cout << a << "     " << b << endl;
//                 break;
//             }
//         }
// // 965997378642829973 - correct
// // 965997378684793993 - wrong
// // 965997377701942337
// // 965997379667645649
//         //return 0;
//     }

    int T;
    cin >> T;
    while(T--){
        ll y , x;
        cin >> y >> x;
        ll rn = ringN(y,x);
        pair<ll, ll> se = ringStartEnd(rn);
        debug() << imie(rn) ;
        //cout << se.F << " " << se.S << endl << endl;
        if (rn %2 == 0) {
            // start from top
            if (y >= x) {
                cout << se.S - x + 1 << endl;
            } else {
                cout << se.F + y - 1 << endl;
            }
        } else {
            // start from left
            if (y >= x) {
                cout << se.F + x - 1 << endl;
            } else {
                cout << se.S - y + 1 << endl;
            }
        }
    }
}

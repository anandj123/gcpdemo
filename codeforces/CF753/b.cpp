#include<bits/stdc++.h>

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

#define REP(i,n) FOR(i,0,n)
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
int INF = 1e9 + 9;
#define VAR(i,n) __typeof(n) i = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define FORDEACH(i,c) for( VAR(i,(c).rbegin()),i!=(c).rend();i++)
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

void calculate(int T) {
    ll x0, n;
    cin >> x0 >> n;
    // if (n<5) {
    //     if (x0 % 2 == 0) {
    //         cout << x0 - (n>0?1:0) + (n>1?2:0) + (n>2?3:0) - (n>3?4:0) << endl;
    //     } else {
    //         cout << x0 + (n>0?1:0) - (n>1?2:0) - (n>2?3:0) + (n>3?4:0) << endl;
    //     }
    //     return;
    // }
    
    vector<ll> n1(4);
    int d = 4;
    FOR(i,1,5){
        int d = 4; // arithmatic progression distance
        int num_elements = (n-i)/4; 
        n1[i-1] = (2*i + num_elements * d) * (num_elements + 1) / 2;
    }

    // n1 = (1+1+ ((n-1)/4) * 4) * ((n-1)/4 + 1) / 2;
    // n2 = (2+2+ ((n-2)/4) * 4) * ((n-2)/4 + 1) / 2;
    // n3 = (3+3+ ((n-3)/4) * 4) * ((n-3)/4 + 1) / 2;
    // n4 = (4+4+ ((n-4)/4) * 4) * ((n-4)/4 + 1) / 2;
    // int ans = 0;
    // debug() << imie(n1);
    
    if (x0 % 2 == 0) {
        cout << x0 - (n>0?n1[0]:0) + (n>1?n1[1]:0) + (n>2?n1[2]:0) - (n>3?n1[3]:0)<< endl;
    } else {
        cout << x0 + (n>0?n1[0]:0) - (n>1?n1[1]:0) - (n>2?n1[2]:0) + (n>3?n1[3]:0)<< endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        calculate(T);
    }
}
/* Observations

9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1




*/
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

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, vi wt, vi val, int n) 
{ 
    int i, w; 
    vvi K(n + 1, vi(W+1)); 
    //Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(
                            val[i - 1] + K[i - 1][w - wt[i - 1]], 
                            K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n, m;cin>>n>>m;
        vi w(n), v(n);
        REP(i,0,n) cin >> w[i];
        REP(i,0,n) cin >> v[i];
        debug() << imie(w) imie(v);
        cout << knapSack(m,w,v,n) << endl;
    }
}

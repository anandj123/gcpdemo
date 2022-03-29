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
    int n; cin >> n;
    vi a(n);
    REP(i,n) cin >> a[i];
    string colors; cin >> colors;
    int nred=0, nblue=0;
    REP(i,n) {
        if (colors[i] == 'R') nred++;
    }
    nblue = n - nred;
    vi ared, ablue;
    ared.clear(), ablue.clear();
    REP(i,n){
        if (colors[i] == 'R') {
            ared.PB(a[i]);
        } else {
            ablue.PB(a[i]);
        }
    }
    sort(all(ablue)), sort(all(ared));
    debug() << imie(ablue) imie(ared) ;
    int counter = 0;
    REP(i,nblue){
        if (i+1 > ablue[i]) {
            
            cout << "NO" << endl;
            return;
        }
    }
    FOR(i,nblue,n){
        int ridx = i-nblue;
        debug() << imie(i+1) imie(ared[ridx]);
        if (i+1 < ared[ridx]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;

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




*/
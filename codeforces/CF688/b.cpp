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
ll INF = 1e12;

void calculate() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n; cin >> n;
        vi a(n);
        vector< ll > diff(n-1);
        ll save = 0l;
        REP(i,0,n) cin >> a[i];
        REP(i,0,n-1) diff[i] = abs(a[i] - a[i+1]);
        
        ll s = accumulate(all(diff),0ll);

        //debug() << imie(a) imie(diff) ;

        REP(i,0,n-1){
            ll o = 0;
            
            //copy 1st
            if (i>0) o = diff[i-1] - abs(a[i+1] - a[i-1]);
            //cout << " o first: " << o << endl;
            o = diff[i] + o;
            save=max(save, o);
            //cout << " overflow first: " << o << " save : " << save << endl;
            
            //copy 2nd
            o = 0;
            if (i<n-2) o = diff[i+1] - abs(a[i] - a[i+2]);
            //cout << " o second: " << o << endl;
            o = diff[i] + o;
            save=max(save, o);
            //cout << " overflow second: " << o << " save : " << save << endl;
        }
        cout  << s - save << endl;
    }
}

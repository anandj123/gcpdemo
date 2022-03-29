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

typedef vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vvi;
int INF = 1e9;

void calculate(ll n, ll w) {
    vector<pair<ll, ll> > data(n);
    REP(i,0,n){
        ll x;
        cin >> x;
        pair<ll, ll> y = make_pair(x,i+1);
        data[i] = y;
    }
    sort(data.rbegin(), data.rend());
    // debug() << imie(data) << imie(w);
    ll C = 0;
    vector<ll> ans;
    REP(i,0,n){
        if(data[i].first <= w) {
            if (C + data[i].first > w) continue;
            C += data[i].first;
            
            ans.push_back(data[i].second);
        }
    }
    sort(all(ans));
    // debug () << imie(C);
    if ( 2 * C < w) {
        cout << "-1" << endl;
        return;
    }
    cout << ans.size() << endl;
    REP(i,0,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll n, w;
        cin >> n >> w;
        calculate(n,w);
    }
}

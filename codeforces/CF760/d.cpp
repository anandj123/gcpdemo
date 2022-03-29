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

#define REP(i,n)       FOR(i,0,n)
#define FOR(i,j,k)     for(int i=j;i<k;i++)
#define FORD(i,j,k)    for(int i=j;i>=k;i--)
#define endl           "\n"
#define F              first
#define S              second
#define MP             make_pair 
#define PB             push_back
#define all(a)         a.begin(),a.end()
#define sz(a)          int((a).size())
#define tr(c,i)        for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x)   (c.find(x) != c.end())
#define cpresent(c,x)  (find(all(c,x) != c.end())

typedef pair< long,long > ii;
typedef vector<long long> vi;
typedef long long         ll;
typedef vector< vector<long long> > vvi;
int INF = 1e9;
ll INF_LL = 1e18;
ll max_ans = 0;
void backtrack(vi&a, vi&vis,int k,ll saved) {
    int n = a.size();
    if (k==0){
        //debug() << imie(max_ans) imie(saved) imie(vis) imie(a);
        max_ans = max(max_ans,saved);
    }
    //debug() << imie(k,saved);
    REP(i,n){
        if(vis[i]) continue;
        for(int j=i+1;j<n;++j){
            if(vis[j]) continue;
            //backtrack(a,vis,k-1,0);
            vis[i] = 1;
            vis[j] = 1;
            ll mi = min(a[i]/a[j],a[j]/a[i]);
            backtrack(a,vis,k-1,saved+(a[i] + a[j] - mi));
            vis[i] = 0;
            vis[j] = 0;
        }
    }
}
void calculate(int T) {
    int n, k; cin >> n >> k;
    vi a(n);
    REP(i,n) cin >> a[i];
    vi vis(n);
    ll ans = 0;
    sort(all(a),greater<long long>());
    REP(i,n) ans+=a[i];
    REP(i,k) {
        ans = ans - a[i] - a[i+k] + (a[i+k]/a[i]);
    }
    cout << ans-max_ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(12) << fixed;
    int T;
    cin >> T;
    #ifdef LOCAL
    int debugT = T;
    clock_t z = clock();
    #endif
    while(T--){
        #ifdef LOCAL
        int Test_Case_Number = debugT-T;
        debug() << imie(Test_Case_Number);
        #endif
        calculate(T);
        #ifdef LOCAL
        debug() << ("----------------------------------------------------");
        #endif
    }
    #ifdef LOCAL
    double Total_Execution_time = (double)(clock() - z)/CLOCKS_PER_SEC;
    debug() << imie(Total_Execution_time);
    #endif
}

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
ll ans = 0;

// This logic is specific to the problem, you can replace this with
// the objective function for the permuation.
void doMax(string a){
  int N = a.length();
  FOR(i,1,N){
    ll x = stol(a.substr(0,i));
    ll y = stol(a.substr(i,a.length()-i));
    ll ans2 = x * y;
    if (ans2 > ans) {
      debug() << imie(a) imie(x) imie(y) imie(ans2) imie(ans);
      ans = ans2;
    }
  }
}
int times;
void permute(string a, int l, int r)
{
    doMax(a);
    times++;
    
    for (int i = l; i <= r; i++) // Permutations made
    {
        swap(a[l], a[i]); // Swapping done
        permute(a, l+1, r); // Recursion called
        swap(a[l], a[i]); //backtrack
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Add test case in in.in = 998244353
    // Ans = 939337176
    // Problem: https://atcoder.jp/contests/abc221/tasks/abc221_c

    int N; cin >> N;
    string S = to_string(N);
    sort(S.rbegin(), S.rend()); 
    
    permute(S,0,S.length()-1);

    // Observations: for 9 digiti INT the number of permutation is
    // 986410 (about 10^6)

    // for 10! the number is 9864101, so the objective function needs to be O(1) to pass TLE
    debug() << "For 9! this is how many times it gets called" imie(times);

    cout << ans << endl;
}
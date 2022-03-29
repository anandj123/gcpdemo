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

void calculate() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n, m; cin >> n; cin >> m;
        vi ka(n), ca(m);
        REP(i,0,n) cin >> ka[i];
        REP(i,0,m) cin >> ca[i];

        priority_queue< int, vector<int>, std::greater<int> > q;
        ll output = 0;
        int pos = 0;
 
        REP(i,0,n){
            q.push(ca[ka[i]-1]);
            // debug() << imie(ca[ka[i]-1]);

            REP(j,pos,ka[i]-1) {
                q.push(ca[j]);
                // debug() << imie(ca[j]);
            }
            pos = max(pos,ka[i]-1);
        }
        // cout << "Test case:" << endl;
        // while(!q.empty()){
        //     cout << q.top() << endl;
        //     q.pop();
        // }
        REP(i,0,n){
            output += q.top();
            q.pop();
        }
        cout << output << endl;
        // cout << "Test case:" << endl;
        while(!q.empty()){
            q.pop();
        }
    }
}

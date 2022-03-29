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

bool sorted(vi d) {
    bool sorted = true;
    REP(i,1,d.size()){
        if(d[i] < d[i-1]) {
            sorted = false;
            break;
        }
    }
    return sorted;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n,x;
        cin >> n >> x;
        
        vi d(n);
        REP(i,0,n){
            cin >> d[i];
        }
        //edge case
        if (n==1) {
            cout << 0 << endl;
            continue;
        }

        //if already sorted
        if (sorted(d)) {
            cout << 0 << endl;
            continue;
        }
        // save a copy
        vi dd(n);
        dd = d;
        int counter = 0;
        int ans = INF;
        vi ansd(n);
        ansd = d;
        REP(j,0,n){
            // restore the original array
            d = dd;
            counter = 0;
            REP(i,j,n){
                if(d[i] > x){
                    int temp = d[i];
                    d[i] = x;
                    x=temp;
                    counter++;
                    if(sorted(d)) break;
                    
                }
            }
            if (sorted(d)){
                ans = min(ans, counter);
                ansd = d;
            }
            
        }
        
        if (!sorted(ansd)) {
            cout << -1 << endl;

        } else {
            cout << ans << endl;
        }
    }
}

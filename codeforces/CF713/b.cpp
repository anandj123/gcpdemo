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
        int n; cin>>n;
        int i1, i2, j1, j2;
        bool first = true;
        REP(i,0,n){
            string s;
            cin >> s;
            REP(j,0,n){
                if (s.at(j) == '*') {
                    if(first) {
                        i1 = i;
                        j1 = j;
                        first = false;
                    } else {
                        i2 = i;
                        j2 = j;
                    }
                }
            }
        }
        int ri1, rj1, ri2, rj2;
        if (i1 == i2) {
            if (i1 == n-1) {
                ri1 = i1-1;
                ri2 = i2 -1;
                rj1= j1;
                rj2 = j2;
            } else {
                ri1 = i1+1;
                ri2 = i2 +1;
                rj1= j1;
                rj2 = j2;
            }
        } else if (j1 == j2) {
            if (j1 == n-1) {
                ri1 = i1;
                ri2 = i2;
                rj1= j1-1;
                rj2 = j2-1;
            } else {
                ri1 = i1;
                ri2 = i2;
                rj1= j1+1;
                rj2 = j2+1;
            }
        } else {
            ri1 = i1;
            rj1 = j2;
            ri2 = i2;
            rj2 = j1;
        }
        REP(i,0,n){
            REP(j,0,n){
                if (i == ri1 and j == rj1) {
                    cout << '*';
                    continue;
                }
                if (i == ri2 and j == rj2) {
                    cout << '*';
                    continue;
                }
                if (i == i1 and j == j1) {
                    cout << '*';
                    continue;
                }
                if (i == i2 and j == j2) {
                    cout << '*';
                    continue;
                }
                cout << '.';
            }
            cout << endl;
        }        
    }
}

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

void printoutput(vi ar, int x, int h) {
    int n = ar.size();

    REP(i,0,n) {
        if (ar[i] == h) {
            h = -1;
            continue;
        }
        if (ar[i] == x) {
            x = -1;
            continue;
        }
        cout << ar[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n; cin>> n;
        vi ar;
        REP(i,0,n+2){
            int b;
            cin >> b;
            ar.PB(b);
        }
        sort(all(ar));
        debug() << imie(ar);

        int h1=0, h2=0;
        REP(i,0,n+2){
            h1 = max(h1,ar[i]);
        }
        bool first = true;
        REP(i,0,n+2){
            if (first and ar[i] == h1){
                first = false;
                continue;
            }
            h2 = max(h2,ar[i]);
        }
        //debug() << imie(h1) imie(h2);
        int sum =0 ;
        REP(i,0,n+2){
            sum+=ar[i];
        }
        
        //If h1 is the sum
        int sumh1 = sum - h1;
        int x = -1;
        REP(i,0,n+2) {
            if (sumh1 - ar[i] == h1) {
                x = ar[i];
            }
        }
        debug() << imie(sum) imie(sumh1) imie(h1) imie(h2) imie(x);
        if (x > 0){
            printoutput(ar,x,h1);
        } else {
            int sumh2 = sum - h2;
            int x= -1;
            REP(i,0,n+2) {
                if (sumh2 - ar[i] == h2) {
                    x = ar[i];
                }
            }
            if (x > 0) {
                printoutput(ar,x,h2);
            } else {
                cout << -1;
            }
        }
        cout << endl;
    }
}

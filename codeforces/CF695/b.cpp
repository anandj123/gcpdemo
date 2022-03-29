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

bool isM(int a, int b, int c, int d, int e) {
    return (a<b and c<b and c<d and e<d);
}
bool isW(int a, int b, int c, int d, int e) {
    return (a>b and c>b and c>d and e>d);
}
bool isN(int a, int b, int c, int d) {
    return ((a>b and c>b and c>d) or (a<b and c<b and c < d));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n; cin >> n;
        vi d(n);
        REP(i,0,n) cin >> d[i];
        int nH = 0, nV = 0, nM = 0, nW = 0, nN = 0;
        bool done = false;
        REP(i,1,n-1){
            if(!done and i>1 and i<n-2) {
                if(isM(d[i-2], d[i-1], d[i], d[i+1], d[i+2])) {
                    nM++;
                    d[i] = d[i-1];
                    d[i+1] = d[i];
                    done = true;
                }
                if(isW(d[i-2], d[i-1], d[i], d[i+1], d[i+2])) {
                    d[i] = d[i-1];
                    d[i+1] = d[i];
                    nW++;
                    done = true;
                }
            }
            if(!done and i>1) {
                if(isN(d[i-2], d[i-1], d[i], d[i+1])) {
                    d[i+1] = d[i];
                    nN++;
                    done = true;
                }
            }
            if(d[i-1] < d[i] and d[i+1] < d[i]) nH++;
            if(d[i-1] > d[i] and d[i+1] > d[i]) nV++;
            
        }
        // debug() << imie(nH) imie(nV) imie(nM) imie(nW) imie(nN);
        int output = nH + nV - 1;
        if (output < 0) output = 0;
        // if (nM > 0) {
        //     output -=2;
        //     if (output < 0) output = 0;
        //     cout << output << endl;
        //     continue;
        // }
        // if (nW > 0) {
        //     output -=2;
        //     if (output < 0) output = 0;
        //     cout << output << endl;
        //     continue;
        // }
        // if (nN > 0) {
        //     output --;
        //     if (output < 0) output = 0;
        //     cout << output << endl;
        //     continue;
        // }
        
        cout << output << endl;
    }

}

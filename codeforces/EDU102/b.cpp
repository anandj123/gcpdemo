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

int iscontain(string s, string t) {
    // 0 = n copies found
    // 1 = substring but not n copies
    // 2 = no overlap
    int m = s.length();
    int n = t.length();
    if (n==1) {
        int c1=0, c2=0;
        REP(i,0,m) {
            if(s.at(i) == 'a'){
                c1++;
            } else{
                c2++;
            }
        }
        if(c1 > 0 and c2>0) return 1;
    }
    //debug() << imie(m) imie(n);
    int retval = 2;
    for(int i=0;i<m;i=i+n){
        if(s.substr(i,n)!=t) {
            return retval;
        } else {
            retval = 1;
        }
    }
    return 0;
}
bool allchar(string s, string t){
    char ch = s.at(0);
    REP(i,1,s.length()){
        if (s.at(i) != ch) return false;
    }
    REP(i,0,t.length()){
        if (t.at(i) != ch) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        string s, t; cin>> s; cin>>t;
        int l = lcm(s.length(), t.length());
        int m = l/s.length();
        string s2,t2;
        REP(i,0,m){
            s2 += s;
        }
        m = l/t.length();
        REP(i,0,m){
            t2 += t;
        }
        if(s2 == t2) {
            cout << s2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

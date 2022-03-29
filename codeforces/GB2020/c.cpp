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

int isPal3(char a, char b, char c) {
    //debug() << imie(a) imie(b) imie(c);
    if (a == '1' or b == '1' or c == '1') return 0;
    if (a == b and b == c) return 2;
    if (a == b or a == c or b == c) return 1;
    return 0;
    
}
int isPal2(char a, char b) {
    //debug() << imie(a) imie(b);
    if (a == '1' or b == '1') return 0;
    if (a == b) return 1;
    return 0;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        string s; cin >> s;
        int count = 0;
        if(s.length()==2 and s[0] == s[1]) {
            cout << 1 << endl;
            continue;
        }

        REP(i,1,s.length()-1) {
            int inc = 0;
            char a = s.at(i-1);
            char b = s.at(i);
            char c =  s.at(i+1);
            if (a == '1' or b == '1' or c == '1') {
                continue;
            }
            if (a == b and b == c) {
                s.at(i-1) = '1';
                s.at(i) = '1';
                s.at(i+1) = '1';
                count += 2;
                continue;
            }
            
            if (a == b) {
                s.at(i-1) = '1';
                s.at(i) = '1';
                count ++;
            }
            if ( a == c ) {
                s.at(i-1) = '1';
                s.at(i+1) = '1';
                count ++;
                continue;
            }
            if (b == c) {
                s.at(i) = '1';
                s.at(i+1) = '1';
                count ++;
                continue;
            }
        }
        REP(i,1,s.length()) {
            int inc = isPal2(s.at(i-1), s.at(i));
            if (inc > 0) {
                count += inc;
                s.at(i-1) = '1';
                s.at(i) = '1';
            }
        }
        cout << count << endl;
    }
}

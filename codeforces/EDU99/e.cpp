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

int calculate(ii a, ii b, ii c, ii d) {
    int retVal;
    if(a.first == b.first) a.second++;
    if(a.second == b.second) a.first++;
    retVal = min(abs(c.first - a.first) + 
                abs(c.second - b.second) +
                abs(d.second-a.second) + 
                abs(d.first - b.first),

                abs(c.first - b.first) + 
                abs(c.second - a.second) +
                abs(d.second-b.second) + 
                abs(d.first - a.first));

    return retVal;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ii a, b, c, d;
        int x, y;
        cin >> x >> y;
        a = MP(x,y);

        cin >> x >> y;
        b = MP(x,y);

        cin >> x >> y;
        c = MP(x,y);

        cin >> x >> y;
        d = MP(x,y);

        vi res(6);
        res[0] = calculate(a,b,c,d);
        res[1] = calculate(a,c,b,d);
        res[2] = calculate(a,d,b,c);
        res[3] = calculate(b,c,a,d);
        res[4] = calculate(b,d,a,c);
        res[5] = calculate(c,d,a,b);

        cout << *min_element(res.begin(), res.end()) << endl;
    }
}

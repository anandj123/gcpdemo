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

struct man
{
    int h;
    int w;
    int id;
};

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
#define H first
#define W second
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



int binSearch(int h, vector<man> d) {
    int l = 0;
    int r = d.size() -1;
    while(l<r){
        int mid = (l+r)/2;
        if (d[mid].h < h) return d[mid].id;
        if (d[mid].h >= h) l = mid + 1;
    }
    return -1;    
}
bool f1(man a, man b){
    if (a.h == b.h) return a.w < b.w;
    return a.h < b.h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n; cin >> n;
        vector< man > d(n);
        vector< pair<int, int> > orig(n);
        REP(i,0,n) {
            int h, w;
            cin >> h; cin >> w;
            d[i] = {h, w, i};
            orig[i] = {h, w};
        }

        sort(all(d), f1);
        REP(i,1,n){
            d[i].w = min(d[i-1].w, d[i].w);
        }

        cout << "Test case: " << endl;
        REP(i,0,n) {
            cout << d[i].h << " " << d[i].w << " " << d[i].id << endl;
        }

        REP(i,0,n){
            cout << binSearch(orig[i].first, d) << endl;
        }

    }
}

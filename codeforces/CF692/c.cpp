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
#define X first
#define Y second
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

int binsearch(vector<pair<int, int> > arr, int index) {
    int l = index+1, r = arr.size() - 1, m = (l+r)/2;
    while(l<=r){
        if(arr[m].second == arr[index].first){
            return m;
        }
        if (arr[m].second > arr[index].first) r = m-1; 
        else l = m+1;
        m =(l+r)/2;
    }
    return -1;
    
}
bool sortsec(pair<int,int> a, pair<int, int> b){ return(a.second < b.second);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n, m; cin >> n, cin >> m;
        vi vis(m);
        vector< pair<int,int> > r;
        int r1 = 0, r2=0;
        REP(i,0,m) {
            int x1, y1; cin >> x1, cin >> y1;
            if(x1 != y1) r.push_back({x1, y1});
        }
        m = r.size();
        sort(all(r));
        debug() << imie(r);
        REP(i,0,m){
            r1++;
            if( binsearch(r,i)>0) r1++;
        }
        debug() << imie(r1);

        sort(all(r),sortsec);
        debug() << imie(r);
        
        REP(i,0,m) { 
            r2++;
            if( binsearch(r,i)>0) r2++;
        }
        debug() << imie(r2);
        
        
        cout << min(r1,r2) << endl;
    }
}

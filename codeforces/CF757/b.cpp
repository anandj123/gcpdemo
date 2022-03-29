#include<bits/stdc++.h>

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

#define REP(i,n) FOR(i,0,n)
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
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

struct building{
    int visits;
    int position;
    int index;
};
bool compare(building a, building b){
    return a.visits < b.visits;
}
bool comp2(building a, building b){
    return a.index < b.index;
}
void calculate(int T) {
    int n; cin >> n;
    vector<building> b(n);
    REP(i,n) {
        int v; cin >> v;
        b[i].visits= v;
        b[i].index = i;
    }
    debug() << imie(n);
    sort(b.rbegin(), b.rend(), compare);

    int pos = 1;
    REP(i,n){
        if (i%2 == 1) {
            b[i].position = -pos;
            pos++;
        } else {
            b[i].position = pos;
        }
    }
    //REP(i,n) cerr << b[i].visits << " " << b[i].position << " " << b[i].index << endl;
    debug() << imie(pos);
    //assert(pos>n/2);
    sort(b.begin(),b.end(),comp2);
    ll tt = 0ll;
    REP(i,n) tt +=  abs(2LL * b[i].position * b[i].visits);
    assert(tt>=0);
    // debug() << imie(tt);
    cout << tt << endl;
    cout << 0 << " ";
    REP(i,n){
        cout << b[i].position << " ";
    }
    cout << endl << flush;

}
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int T;
    cin >> T;
    #ifdef LOCAL
    int debugT = T;
    clock_t z = clock();
    #endif
    while(T--){
        #ifdef LOCAL
        int Test_Case_Number = debugT-T;
        debug() << imie(Test_Case_Number);
        #endif
        calculate(T);
        #ifdef LOCAL
        debug() << ("----------------------------------------------------");
        #endif
    }
    #ifdef LOCAL
    double Total_Execution_time = (double)(clock() - z)/CLOCKS_PER_SEC;
    debug() << imie(Total_Execution_time);
    #endif
}

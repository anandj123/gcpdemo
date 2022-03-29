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
int INF = 1e9 + 9;
#define VAR(i,n) __typeof(n) i = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define FORDEACH(i,c) for( VAR(i,(c).rbegin()),i!=(c).rend();i++)
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
ii addpos(ii curr, ii move){
    return {curr.F + move.F, curr.S + move.S};
}
bool possible(ii curr, ii move, int n, int m){
    
    ii next = addpos(curr,move);
    
    bool isPossible = !(next.F  < 1 || next.F > m || next.S < 1 || next.S > n);
    
    debug() << imie(curr) imie(move) imie(next) imie(isPossible);

    return isPossible;

}
void calculate(int T) {
    int n, m; cin >> n; cin >> m;
    string moves; cin >> moves;
    map<char, ii> maps ={{'L',{0,-1}},{'R',{0,1}},{'U',{-1,0}},{'D',{1,0}}};
    debug() << imie(n) imie(m);

    ii startpos, currpos;
    startpos ={1,1};
    currpos = {1,1};

    map<ii,bool> vis;
    

    REP(i,moves.length()){
        if (vis[currpos]) {
            break;
        }
        ii canmove = maps[moves[i]];
        if (possible(currpos,canmove, n, m)) {
            vis[currpos] = true;
            currpos = addpos(currpos,canmove);
        } else {

            ii rmove = {canmove.F * -1, canmove.S * -1};

            debug() << imie(rmove);

            if (possible(startpos,rmove,n,m)) {
                startpos = addpos(startpos,rmove);
                vis[startpos] = true;    
            } else {
                break;
            }
        }
        debug() << imie(moves[i]) imie(currpos) imie(startpos);

        // cout << "outside the if loop" << endl;
    }
    
    cout << startpos.F << " " << startpos.S << endl;


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        calculate(T);
    }
}
/* Observations




*/
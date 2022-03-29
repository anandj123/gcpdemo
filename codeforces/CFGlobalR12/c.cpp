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

int check(vvi grid, int pos, int n) {
    bool col = true;
    bool row = true;

    REP(i,0,n){
        if (grid[pos][i] != 1) {
            row = false; 
            break;
        }
    }
    if (row) {
        
    }
    //debug() << imie(grid[pos]) imie(pos) imie(n) imie(row);

    REP(i,0,n){
        if (grid[i][pos] != 1) {
            col = false;
            break;
        }
    }
    //debug() << imie(grid[pos]) imie(pos) imie(n) imie(col);

    return col | row;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<string> s(n);
        REP(i,0,n) cin >> s[i];
        vvi grid(n, vi(n));
        REP(i,0,n){
            REP(j,0,n) {
                if(s[i].at(j) == 'X'){
                    grid[i][j] = 1;
                }
            }
        }
        //make 3 x 3 grids
        vvi grid3(3,vi(3));

        if (n<4) {
            grid3 = grid;
            REP(i,0,n){
                if(check(grid,i,n)){
                    grid[i][i] = 2;
                }
            }
        } else {
            REP(i,0,n-2){
                REP(j,0,n-2){
                    REP(k,0,3){
                        REP(l,0,3){
                            grid3[k][l] = grid[i+k][j+l];
                        }
                    }
                    if(i!=j) continue;
                    if(check(grid,i,n)){
                        grid[i][j] = 2;
                    }
                }
            }
        }
        
        REP(i,0,n){
            REP(j,0,n){
                if (grid[i][j]==1) cout << 'X';
                else if (grid[i][j]==0) cout << '.';
                else cout << 'O';
            }
            cout << endl;
        }
    }
}

/*


XX.XXX
XXXXXX
XXX.XX
XXXXXX
XX.X.X
XXXXXX

XX.XXX
XOXXXX
XXX.XX
XXXXXX
XX.X.X
XXXXXO

*/
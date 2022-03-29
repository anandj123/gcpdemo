#include<bits/stdc++.h>

using namespace std;

#define REP(i,n)       FOR(i,0,n)
#define FOR(i,j,k)     for(int i=j;i<k;i++)
#define FORD(i,j,k)    for(int i=j;i>=k;i--)
#define endl           "\n"
#define F              first
#define S              second
#define MP             make_pair 
#define PB             push_back
#define all(a)         a.begin(),a.end()
#define sz(a)          int((a).size())
#define tr(c,i)        for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x)   (c.find(x) != c.end())
#define cpresent(c,x)  (find(all(c,x) != c.end())

typedef pair< long,long > ii;
typedef vector<long long> vi;
typedef long long         ll;
typedef vector< vector<long long> > vvi;

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


int INF = 1e9;
ll INF_LL = 1e18;

vi DX = {-1,1,0,0};
vi DY = {0,0,-1,1};
vector<string> grid(1e6);
bool can_move(int row, int col, int n, int m,char c) {return (0 <= row && row < n && 0 <= col && col < m && grid[row][col] == c); }
 
// passing the vector by reference is the main issue.
// if you don't do this there will be TLE.
// I should figure out how to make it global variable.

void dfs(int row, int col, int n, int m){
    REP(i,4){
        if (can_move(row+DX[i],col+DY[i], n, m,'.')){
            int r = row+DX[i], c = col+DY[i];
            
            //find how many dots are there for this one.
            int cnt = 0;
            REP(j,4){
                if (can_move(r+DX[j],c+DY[j],n,m,'.')) cnt++;
            }
            if (cnt<=1) {
                grid[r][c] = '+';
                dfs(r,c, n,m);
            } 
        }
    }   
}
void calculate(int T) {
    int n, m; cin >> n >> m;
    grid.assign(n,"");
    REP(i,n) cin >> grid[i];
    
    REP(i,n)
    REP(j,m){
        if (grid[i][j] == 'L') {
            debug() << imie(j);
            dfs(i,j,n,m);
            break;
        }
    }
        // auto j = grid[i].find('L'); this is much slower than looping through the columns
        // if (j !=std::string::npos){
        // }
    
    REP(i,n){
        cout << grid[i] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

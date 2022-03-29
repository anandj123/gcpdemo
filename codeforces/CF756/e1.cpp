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
int MX = 2e5+1;
vvi ar(MX);
vi leafs;
vector<bool> vis(MX);
vi parents(MX);
vi levels(MX);
void dfs(int node, int parent, int level, vi x){
    vis[node] = true;
    parents[node] = parent;
    levels[node] = level;

    if(sz(ar[node])== 1 && ar[node][0] == parent) {
        if (node == 1) return;
        if (find(all(x),node) == x.end()) leafs.PB(node);
        return;
    }
    for(int child:ar[node]) {
        debug() << imie(child) imie(node);
        if (vis[child]) {
            continue;
        }
        dfs(child, node,level+1,x);
    }
}
int artpoint(int u, int v){

    if (u==v) return u;
    int l1 = levels[u], l2 = levels[v];
    
    debug() << imie(l1) imie(l2);
    if (l1>l2){
        swap(l1,l2);
        swap(u,v);
    }
    
    while(l1<l2){
        v = parents[v];
        l2--;
    }
    while(u != v) {
        u = parents[u];
        v = parents[v];
    }
    return u;
}
void calculate(int T) {
    int n, k; cin >> n >> k;
    vi x(k); REP(i,k) cin >> x[i];
    debug() << imie(n) imie(k) imie(x);
    REP(i,n) {
        vis[i] = false;
        parents[i] = 1;
        ar[i].clear();
        levels[i] = 0;
    }
    leafs.clear();
    REP(i,n-1){
        int u, v; cin >> u >> v;
        ar[u].PB(v);
        ar[v].PB(u);
    }

    REP(i,n){
        debug() << imie(ar[i]);
    }    
    int root = 1;
    dfs(1,1,0,x);
    debug() << imie(leafs);
    REP(i,n){
        debug() << imie(parents[i]) imie(levels[i]);
    }

    REP(i,sz(leafs)){
        
        REP(j,k){
            // if (leafs[i] == x[j]) continue;
            //position of friend x[j]
            // position of leaf leafs[i]
            // find articulation point
            // find how many steps needed to reach articulation point from root
            // find how many steps required to reach arcticulation point from friend
            // if all the steps are less then print YES
            // else NO
            int articulation_point = artpoint(leafs[i], x[j]);
            if (articulation_point == 1) continue;
            debug() << imie(leafs[i]) imie(x[j]) imie(articulation_point);
            int distance_from_friend = abs(levels[articulation_point] - levels[x[j]]);
            debug() << imie(levels[articulation_point] ) imie(distance_from_friend);
            if (levels[articulation_point] < distance_from_friend){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    

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

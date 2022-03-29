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

vector<bool> vis; //visted array
vector< vector<int> > ar; //adjecency list
int n; //number of verteces

void dfs(int cur){
  vis[cur] = true;
  for(int child:ar[cur]) {
    if (!vis[child]) dfs(child);
  }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*

    1 -- 2
    2 - 1
    3 - 4, 6
    4 - 3
    6 - 3

12 nodes
1 2
3 4
4 5
3 6
7 12
6 10
10 11
11 12
8 9

    */
  n = 13;
  REP(i,0,n) vis.push_back(false), ar.push_back({});
  
  ar[1].push_back(2), ar[2].push_back(1);
  ar[3].push_back(4), ar[4].push_back(3);
  ar[4].push_back(5), ar[5].push_back(4);
  ar[3].push_back(6), ar[6].push_back(3);
  ar[7].push_back(12), ar[12].push_back(7);
  ar[6].push_back(10), ar[10].push_back(6);
  ar[10].push_back(11), ar[11].push_back(10);
  ar[11].push_back(12), ar[12].push_back(11);
  ar[8].push_back(9), ar[9].push_back(8);
  int cc = 0;
  REP(i,1,n) {
    if(!vis[i]) dfs(i), cc++;
  }
  cout << cc;

}

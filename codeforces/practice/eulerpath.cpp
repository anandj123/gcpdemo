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

void calculate() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int v = 5;
    vvi edges(v+1, vi(5+1));
    edges[1][2] = 1;
    edges[1][3] = 1;
    edges[2][4] = 1;
    edges[2][5] = 1;
    /*
                 1
               /   \
              2     3
            /  \
           4    5
    */
   stack<int> st;
   debug() << imie(edges);

   REP(i,1,v+1) {
       REP(j,1,v+1){
           cout << edges[i][j] << " ";
       }
       cout << endl;
   }
    st.push(1);
    vi visited(v+1), en(v+1), ex(v+1), FT(2*v + 1);
    visited[1] = 1;
    int timer = 0;
    
    while(!st.empty()){
        int top = st.top();
        debug() << imie(st.top()) << visited;
        timer++;
        
        if(visited[top] == 2) {
            ex[top] = timer;
            FT[timer] = top;
            st.pop();
            visited[top] = 3;
            continue;
        }
        REP(i,1,v+1){
            if(edges[top][i] == 1 and visited[i] == 0){
                st.push(i);
                visited[i] = 1;
            }
        }

        visited[top] = 2;
        en[top] = timer;
        FT[timer] = top;
    }
    debug() << imie(visited);
    debug() << imie(en) << imie(ex);
    debug() << imie(FT);

}

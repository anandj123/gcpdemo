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

typedef vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vvi;
int INF = 1e9;

vi parent;
void make_set(int v){
    parent.PB(v);
}
int find_set(int v){
    if (v == parent[v]){
        return v;
    }
    return find_set(parent[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        parent[b] = a;
    }
}
void calculate() {
    
}
int main() {
    {
        assert("Yes" == "Yes");
    }
    /*

5 8
########
#..#...#
####.#.#
#..#...#
########

Ans: 3

    */

   // Read input

    int R , C ;
    cin >> R >> C;
    vector<string> data (R);
    REP(i,0,R){
        cin >> data[i];
    }
    
    // Find all the dots and make vector pair for positions
    vector < pair<int, int> > v;
    REP(i,0,R){
        REP(j,0,C){
            if(data[i].at(j) == '.') {
                v.PB(MP(i,j));
            }
        }
    }

    //disjoint set implementation
    // make set
    REP(i,0,v.size()) {
        make_set(i);
    }

    // union sets
    // This is wrong logic. Need BFS here for successful 
    // Here is the test case that fails
    /*


10 10
##..###..#
..#.#.....
..#...####
#.....##..
..#...#..#
.##.#.##..
.......#..
..........
...#.#....
..#..#...#

ans: 1

    */
    REP(i,0,v.size()){
        REP(j,0,v.size()){
            int diff = abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S);
            //debug() << imie(v[i].F) imie(v[j].F) imie(v[i].S) imie(v[j].S) imie(diff);
            
            if (diff == 1){
                union_sets(i,j);
            }
        }
    }
    //Find how many disjoint sets are present
    unordered_set<int> ans;
    REP(i,1,v.size()){
        ans.insert(parent[i]);
    }
    cout << ans.size() << endl;
    //debug() << imie(v) << imie(parent);
}

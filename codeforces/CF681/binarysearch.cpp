#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<set>

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

typedef vector<int> vi;
typedef long long ll;
typedef vector< vector<int> > vvi;
int INF = 1e9;

int calculate(vi table, int key) {
    int l = 0, r = table.size() -1;
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        if (table[mid] == key) {
            ans = mid;
            break;
        }
        if (table[mid] < key){
            l = mid +1;
            continue;
        } else {
            r = mid -1;
            continue;
        }
    }
    return ans;
}

int main() {
    vi table = {1,2,4,6,8,9,10};
    debug() << imie(table);
    cout << calculate(table, 4) << endl;
    cout << calculate(table, 12) << endl;

}

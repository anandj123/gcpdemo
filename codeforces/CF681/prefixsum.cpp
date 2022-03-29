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

int calculate(vi arr, int l, int r) {
    REP(i,1,arr.size()){
        arr[i] += arr[i-1];
    }
    if (l==0)  return arr[r];
    return arr[r] - arr[l-1];
}
int main() {
    {
        // Substring example
        string s = "abcde";
        cout << s.substr(2,2) << endl;
        
    }
    vi arr = {1,2,-1,3,5};
    
    debug() << imie(arr);
    
    cout << calculate(arr, 0,1) << endl; 
    cout << calculate(arr, 1,1) << endl;
    cout << calculate(arr, 2,2) << endl;
}

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
int INF = 1e9;
int sizeOfInt(ll x){
  int ans = 1;
  while(x/10 > 0){
    ans++;
    x /= 10;
  }
  return ans;
}
void calculate(int T) {

  // {
  //   debug() << imie(sizeOfInt(23));
  //   debug() << imie(sizeOfInt(3));
  //   debug() << imie(sizeOfInt(123));
  //   return;
  // }
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    ll szx1 = sizeOfInt(x1), szx2 = sizeOfInt(x2);
    // how many digits in x1 and x2
    // x1 = 2 -> 1 x2 = 19 -> 2
    // p1 = 1      p2 = 0
    if (x1 > x2){
      x2 = x2 * pow(10,szx1-szx2);
      p2 -= szx1 - szx2;
    } else {
      x1 = x1 * pow(10,szx2-szx1);
      p1 -= szx2 - szx1;
    }
    debug() << imie(x1) imie(x2) imie(p1) imie(p2);
    if (p1 == p2){
      if (x1 > x2) {
        cout << ">" << endl;
        return;
      }
      if (x1 == x2) {
        cout << "=" << endl;
        return;
      }
      cout << "<" << endl;
      return;
    }
    if (p1 > p2) {
      cout << ">" << endl;
    } else {
      cout << "<" << endl;
    } 
    return;
    
    
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

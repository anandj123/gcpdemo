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

void calculate(int n, int k, vi data) {
    sort(all(data));
    //debug() << imie(n) imie(k) imie(data);
    // sum of medians of n buckets needs to be maximum
    ll ans = 0;
    vi temp;
    int med;
    med = (n/2);
    int size = data.size();
    // if (n%2==1) med--;
    //debug() <<  imie(n) imie(med) imie(n-med);
    for(int i=1;i<=k;i++){
        int K = size - i * (med + 1) ;

        //cout << " bucket: " << i << " data : " << data[K] << endl ;
        ans += data[K];
    }

    cout <<  ans << endl ;


    // for(int j=0;j<n;j++){
    //     for(int i=j;i<data.size();i=i+n){
    //         cout << bucket data[i]);
    //     }

    // }
    
    // debug() << imie(temp);

    // n = 4, median = 2, 4 - 2 + 1 = 3
    //cout << ans << endl;
    // k buckets
    // each with n numbers
    // median of the n numbers
    // all over the k buckets
    // 4 + 27 + 91  = 122

 

    // 91 + 36 + 18 = 145

    // 94 69 38 33
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vi data(n*k);
        REP(i,0,data.size()){
            cin >> data[i];
        }
        calculate(n,k,data);
    }
}

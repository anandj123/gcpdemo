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

bool lcs( string X, string Y, int l, int r )  
{  
    // if (X.size()<2) {
    //     //cout << "NO" << endl;
    //     return 0;
    // }
    int m = X.length(), n = Y.length();
    vvi L(m + 1, vector<int>(n + 1));  
    int i, j;  
      
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
            if (i == 0 || j == 0)  {
                L[i][j] = 0;  
            } else if (X.at(i - 1) == Y.at(j - 1)) {
                L[i][j] = L[i - 1][j - 1] + 1; 
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
            }
        }  
    }  
    bool ans = false;
    //debug() << imie(X) imie(Y) imie(L) imie(ans);

    // debug() << imie(ans);
    // int counter = 0;
    REP(i,1,n){
        if (L[m][i] == 1 and i<l) {
            return true;
        }
    }
    /*
    int count2 = count(all(L[m]),2);
    if (count2 > 2 and ans == 2) cout << "YES" << endl;
    else if(counter>ans) cout << "YES" << endl;
    else cout << "NO" << endl;
     */
    return ans;

}
void calculate(int n, string s, int l, int r) {
    // cout << n << " " << s << " " << l << " " << r << endl;
    // cout << l-1 << " " << r-l+1 << endl;
    // cout << s.substr(l-1,r-l+1) << endl;
    
    assert(l<=r);
    assert(r<=n);
    if(r-l<1) {
        cout << "NO" << endl;
        return;
    }
    string X = s.substr(l-1,r-l+1);
    string Y = s;

    for(int i=0;i<l-1;i++){
        if(Y.at(i) == Y.at(l-1) ) {
            cout << "YES" << endl;
            return;
        }
    }
    
    for(int i=r;i<n;i++){
        if(Y.at(i) == Y.at(r-1) ) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    // int x1 = lcs(X, Y, l, r);
    // if (x1 > x2) cout << "NO" << endl;
    // else cout << "YES" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;
        int l, r;
        REP(i,0,q){
            cin >> l >> r;

            calculate(n, s, l, r);
        }
    }
}

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


  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( string X, string Y )  
{  
    int m = X.length(), n = Y.length();
    vvi L(m + 1, vector<int>(n + 1));  
    int i, j;  
      
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
            if (i == 0 || j == 0)  L[i][j] = 0;  
            else if (X.at(i - 1) == Y.at(j - 1))  L[i][j] = L[i - 1][j - 1] + 1;  
            else L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    
    cout << "                                    " ;
    REP(i,1,n+1){
        cout << Y.at(i-1) << ", ";
    }
    cout << endl;
    cout << "                                    " ;
    REP(i,1,n+1){
        cout << i << ", ";
    }
    cout << endl;
    REP(i,1,m+1){
        debug() << imie(X.at(i-1)) imie(i) imie(L[i]);
    }
    
    int ans=0;
    int x1 = 0, y1=0, counter = 0;
    i = m, j = n;
    while(i>0 and j>0){
        
        
        if(L[i][j] == L[i][j-1]) {
            if (X.at(i-1) != Y.at(j-1)) {
                j--;
                continue;
            }
        }

        if(L[i][j] == L[i-1][j]) {
            if (X.at(i-1) != Y.at(j-1)) {
                i--;
                continue;
            }
            
        }
        if(L[i][j] == L[i-1][j-1] + 1) {
            counter++;
            if(x1 == 0) {
                x1 = i;
                y1 = j;
            }
            ans = max(ans,(4 * counter) - (x1-i+1) - (y1-j+1));
            cout << "X: " << X.at(i-1) << " Y: " << Y.at(j-1) << " i: " 
                << i << " j: " << j << " L[i][j]: " << L[i][j] << " ans: " << ans << endl;
            i--, j--;
            continue;
        }
        
        
        
        
         
        
        
        
        
    }
    
    
    return ans;  
}  
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l1, l2;
    cin >> l1 >> l2;
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1,s2) << endl;
}

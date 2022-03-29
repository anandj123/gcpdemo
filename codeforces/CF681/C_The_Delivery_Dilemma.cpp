#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<set>
using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)
#define endl "\n"

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef long long ll;
int INF = 1e9;

void calculate(vi a, vi b, int N) {
    vector< pair<ll, ll> > data(N);
    REP(i,0,N){
        data[i] = make_pair(a[i], b[i]);
    }
    
    sort(data.begin(), data.end());

    vector<ll> cumsum(N);
    REP(i,0,N){
        cumsum[i] = (i>0?cumsum[i-1]:0) + data[i].second;
    }
    ll s =0;
    ll ans2 = INF;
    REP(i,0,N-1){
        s = cumsum[N-1] - cumsum[i]; // if we have to pick up all other items from current node
        s = max(data[i].first,s); // if we select the delivery and pickup for all till current node
        s = min(s, cumsum[N-1]); // if we don't select delivery
        ans2 = min({data[N-1].first, s, ans2}); // compare with current
    }
    if (N == 1) cout << min(data[0].first, data[0].second) << endl;
    else cout << ans2 << endl;
}
int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int N;
        cin >> N;
        vi a(N), b(N);
        REP(i,0,N){
            cin >> a[i];
        }
        REP(i,0,N){
            cin >> b[i];
        }
        calculate(a,b, N);
    }
}

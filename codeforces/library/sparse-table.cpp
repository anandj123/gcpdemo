#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int tmin[N][18], tmax[N][18], tsum[N][18], a[N];
void build(int n) {
  for(int i = 1; i <= n; ++i) {
    tmin[i][0] = a[i];
    tmax[i][0] = a[i];
    tsum[i][0] = a[i];
  }
  for(int k = 1; k < 18; ++k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
      tmin[i][k] = min(tmin[i][k - 1], tmin[i + (1 << (k - 1))][k - 1]);
      tmax[i][k] = max(tmax[i][k - 1], tmax[i + (1 << (k - 1))][k - 1]);
      tsum[i][k] = tsum[i][k - 1] + tsum[i + (1 << (k - 1))][k - 1];
    }
  }
}

int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  return min(tmin[l][k], tmin[r - (1 << k) + 1][k]);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n=10;
  
  for(int i = 1; i <= n; i++) a[i] = i;
  build(n);
  
  cout << "Min sparse table:" << endl;
  for(int i=0;i<18;++i){
    for(int j=0;j<=n;++j){
      cout << tmin[j][i] << " ";
    }
    cout << endl;
  }
  cout << "Max sparse table:" << endl;
  for(int i=0;i<18;++i){
    for(int j=0;j<=n;++j){
      cout << tmax[j][i] << " ";
    }
    cout << endl;
  }
  // WARNING:
  // Sum sparse table doesn't work, for this you should use prefix sum
  cout << "Sum sparse table:" << endl;
  for(int i=0;i<18;++i){
    for(int j=0;j<=n;++j){
      cout << tsum[j][i] << " ";
    }
    cout << endl;
  }

  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    ++l;
    ++r;
    cout << query(l, r) << '\n';
  }
  return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>

using namespace std;

#define debug(x) cout << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)
#define endl "\n";
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
void printMatrix(vvi a) {
   for(int i=0;i<a.size();i++){
      for(int j=0;j<a[0].size();j++) {
         cout << a[i][j] << " ";
      }
      cout << "\n";
   }
}
void tupletest(){
   tuple<int, int, int> point;
   
}
void mathexamples(){
   int i = 12, j = 12;
   debug(gcd(i,j));
   vi a;
   a.push_back(1);
   a.push_back(2);
   debug(accumulate(a.begin(), a.end(), 0));
   for(auto b : a){
      debug(b);
   }
   debug(floor(2.3));
   debug(ceil(2.3));
   int rows = 3, cols = 5, initVal = 6;
   vvi abc(rows,vi(cols,initVal));
   printMatrix(abc);
}
int main() {
   mathexamples();
}
 
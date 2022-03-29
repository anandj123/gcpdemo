#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {

    /*
    s even len 
    s binary
    n/2 - 0 n/2 - 1
    0101
    1010


    1 1 1 0 1 0 0 0 
    ---------------
    10010110



    111000
    ------------
    100110
    101010

    */

   int T;
   cin >> T;
   for(int k=0;k<T;k++){
       int N;
       string s;
       cin >> N >> s;
       
       int count = 0;
       int i = 0;
       while(i<N) {
          if (s[i] == s[i+1]) {
              count++;
           }
           i++;
       }
       
       count = (count+1)/2;
       cout << count << "\n";
       
   }
}

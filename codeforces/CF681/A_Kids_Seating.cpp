
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<map>
using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)
#define endl "\n"

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
int INF = 1e9;
bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}
vector<int> primes;

void getPrimes(){
    REP(i,2,100){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
}
void calculate(int N) {
    //int start = 2;
    while(N > 0) {
        REP(i, 0, primes.size()){
            REP(j,i,primes.size()){
                cout << primes[i] * primes[j] << " ";
                N --;
                if (N==0) break;
            }
            if (N==0) break;
        }
        if (N==0) break;
    }
    
    // while(N > 0) {
    //     REP(i,start,400){
    //         // debug(i);
    //         // debug(isPrime(i));
    //         if(isPrime(i)) {
    //             cout << 2 *i << " ";
    //             N--;
    //             start = i + 1;
    //             break;
    //         }
    //     }
        
        
    // }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    getPrimes();
    while(T-- > 0){
        int N;
        cin >> N;
        calculate(N);
    }
}

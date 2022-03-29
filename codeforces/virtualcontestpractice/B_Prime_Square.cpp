#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
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

int main() {
    int T;
    cin >> T;
    for(int k=0;k<T;k++){
        int N;
        cin >> N;
        int p = 1;
        while(true) {
            if (isPrime(p)) {
                p++;
                continue;
            }
            bool found = isPrime(N - 1 + p);
            if (found) {
                for (int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        if(i == j) {
                            cout << p << " ";
                        } else {
                            cout << "1 "; 
                        }
                    }
                    cout << "\n";
                }
                break;
            }
            p++;
        }        
    }
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
void calculate(long long N) {
    long long ans =0;
    bool turn = true;
    while(N>0){
        if (turn){
            if (N > 8 and N%4 == 0){
                ans += 1;
                N--;
            } else if (N % 2 == 0 and N > 2){
                ans += N/2;
                N /= 2;
            } else {
                ans += 1;
                N -=1;
            }
            turn = false;
            // debug(N);
            // debug(ans);
        } else {
            if (N > 8 and N%4 == 0){
                N--;
            } else if (N % 2 == 0 and N > 2){
                N /= 2;
            } else {
                N -=1;
            }
            turn = true;
        }
        
    }
    cout << ans << " " << endl;
}
int main() {
    int T;
    cin >> T;
    for(int kk=0;kk<T;kk++){
        long long N;
        cin >> N;
        
        calculate(N);
        
    }
}

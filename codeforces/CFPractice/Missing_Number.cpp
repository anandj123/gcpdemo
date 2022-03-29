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
    int T;
    cin >> T;
    T--;
    bool found = false;
    if(T == 1) {
        int i;
        cin >> i;
        if(i == 1) {
            cout << 2;
        } else {
            cout << 1;
        }
        found = true;
        T = 0;
    }
    vector<int> input(T);

    REP(i,0,T){
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());
    
    REP(i,1,T){
        if (input[i-1] + 1 != input[i]) {
            cout << input[i-1] + 1;
            found = true;
            break;
        }
    }
    if (!found){
        cout << T + 1;
    }
}

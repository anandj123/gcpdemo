#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
void doMod(long long *x){
    
    
    
}
int main() {
    int n, x, pos;
    cin >> n >> x >> pos;
    int i, j, c;
    
    i =0;
    j = n;
    c = (i+j) /2;
    long long pow1 = pow(10,9) + 7;
    
    int ans = n -1; // how many factorials needed
    long long output = 1; // collect the sets (factorials)
    int smaller = x - 1;
    int greater = n - x;

    while(c != pos) {
        //cout << "ans " <<  ans << " c "  << c << " greater " << greater << " smaller " << smaller << "\n"; 
        if (c > pos) {
            output *= greater;
            j = c;
            ans--;
            greater --;
        } else if (c < pos) {
            output *= (smaller);
            i = c + 1;
            ans--;
            smaller--;
        }
        c = (i+j) /2;
        if (output > pow1) {
            output %= pow1;
        }
        //cout << "output " << output << "\n";
    }
    
    //cout << "\n\nans " <<  ans << " c "  << c << " greater " << greater << " smaller " << smaller << "\n"; 
    
    for(int i = 1; i <= ans; i++){
        output *= i;
        if (output > pow1) {
            output %= pow1;
        }
        //cout << "output " << output << "\n";
    }
    cout << output  << "\n";
}

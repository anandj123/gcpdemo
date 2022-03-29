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
    for(int k=0;k<T;k++){
        int N;
        cin >> N;
        int a=0, b=0, c=0;
        int count3 = N/3;
        int count5 = N/3;
        int count7 = N/3;
        bool found = false;
        for(int i=0;i<=count3;i++){
            for(int ii=0;ii<=count5;ii++){
                for(int iii=0;iii<count7;iii++){
                    if (i*3 + ii * 5 + iii * 7 == N){
                        found = true;
                        a = i;
                        b = ii;
                        c = iii;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        
        if(!found) {
            cout << -1 << endl;
        } else {
            cout << a << " " << b << " " << c << " " << endl;
        }

    }
}

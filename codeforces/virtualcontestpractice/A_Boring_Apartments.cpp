#include<iostream>
#include<string>

using namespace std;

#define REP(i,a,b) for(int i=a; i<b;++i)

int main() {
    int t;
    cin >> t;
    REP(i,0,t){
        int n;
        cin >> n;
        string s = to_string(n);
        int m = (int) (s.at(0) - '0');
        int l = s.length();
        int output = (m-1) * 10;
        for(int j =1; j<=l;j++){
            output += j;
        }
        cout << output << "\n";

        // cp /usr/local/Cellar/gcc/9.2.0_3/include/c++/9.2.0/x86_64-apple-darwin18/bits /Library/Developer/CommandLineTools/usr/include/
        // ll /Library/Developer/CommandLineTools/usr/include/
    }
}

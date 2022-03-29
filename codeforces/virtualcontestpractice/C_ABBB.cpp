#include <iostream>
#include<string>
using namespace std;
int main(){
    int k=0;
    cin >> k;
    for(int i=0;i<k;i++){
        int ca = 0, cb=0;
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++){
            if(s.at(j) == 'A') {
                ca++;
                continue;
            }
            if(s.at(j) == 'B') {
                if(ca >0) {
                    ca--;
                    continue;
                }
                cb++;
            }
        }
        cb %=2;
        cout << ca + cb << "\n";

    }
}
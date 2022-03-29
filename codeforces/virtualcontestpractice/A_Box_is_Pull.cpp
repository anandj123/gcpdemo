#include<iostream>

using namespace std;
#define out(x) cerr << #x << " " << (x) << "\n";
int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2, output;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 != x2){
            int movec = abs(y2 - y1)>0? 2:0;
            cout << abs(x2 - x1) + movec + abs(y2-y1) << "\n";
        } else {
            cout << abs(y2-y1) << "\n";
        }
        
    }
}
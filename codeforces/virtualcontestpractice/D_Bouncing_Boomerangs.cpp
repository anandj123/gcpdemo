#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector< vector<int> > grid(n,vector<int>(n));
    vector<int> ai (n);
    for(int i=0;i<n;i++){
        cin >> ai[i];
    }
    
    vector<int> colc(n), rowc(n);
    for(int i=0;i<n;i++){
        if(ai[i] == 1){
            for(int j=i;j<n;j++){
                if (grid[n-j-1][i] == 1) {
                    continue;
                }
                grid[n-j-1][i] = 1;
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(ai[i] == 2){
            for(int j=0;j<n;j++){
                if (grid[n-j-1][i] == 1) {
                    continue;
                }
                grid[n-j-1][i] = 1;
                break;
            }
        }
    }

// This is a test
// This is another line
//
/*

*/

    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
int main(){
    int n,k, output = 0,val=0;
    cin >> n >> k;
    vi scores;
    f(i,n){
        cin >> val;
        scores.push_back(val);
        
    }
    sort(scores.begin(), scores.end(),greater<int>());
    f(i,n){
        if(scores[i] > 0 && scores[i] >= scores[k-1]) {
            output++;
        }
    }
    cout << output << endl;

}
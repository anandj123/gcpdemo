#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void calculate(vector<int> a){
    for(int j = 0; j<a.size();j++){
        //cout << "\nj " << j << "\n";
        if(j % 2 == 0) {
            cout << a[j+1] << " ";
        } else {
            cout << -a[j-1] << " ";
        }
    }
    cout << "\n";
}
void calculate2(vector<int> a){
    //cout << accumulate(a.begin(), a.end(), 0);
    //sort(a.begin(), a.end());

    int bucket = 0;
    for(int j = 0; j<a.size() -1;j++){
        bucket += a[j];
    }
    int last = a[a.size() -1];
    int g = gcd(last, bucket);

    if (bucket == 0) {
        cout << (last /g) + last << " ";
    } else {
        cout << (last /g) << " ";
    }
    for(int j = 1; j<a.size() -1;j++){
        cout << last/g << " ";
    }

    if (bucket == 0) {
        cout <<  -(bucket/g + a[0]);
    } else {
        cout <<  -bucket/g;
    }
    
    cout << "\n";
}
int main() {
    int T;
    cin >> T;
    for(int k =0;k<T;k++){
        int N;
        cin >> N;
        vector<int> val(N);
        for(int i =0;i<N;i++){
            cin >> val[i]; 
        }
        calculate(val);
    }
}

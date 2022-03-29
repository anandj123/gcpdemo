#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void calculate(vector< vector<int> > val, int rows, int cols){
    int sum=0;
    
    for (int i=0;i<=ceil(rows/2);i++){
        for(int j=0;j<=ceil(cols/2);j++){
            int a,b,c,d;
            a = val[i][j];
            b = val[i][cols-j];
            c = val[rows-i][j];
            d = val[rows-i][cols-j];
            int min1, max1, add1;
            int add2=10*exp(10);

            min1 = min(min(min(a,b),c),d);
            max1 = max(max(max(a,b),c),d);
            
            for(int k=min1;k<=max1;k++){
                add1 = abs(k-a) +abs(k-b)+abs(k-c)+abs(k-d);
                add2 = min(add2,add1);
            }

            
            if (rows-i==i) {
                add2 /=2;
            }
            if (cols-j==j) {
                add2 /=2;
            }
            sum += add2;
        }
    }
    cout << sum << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int rows, cols;
        cin >> rows;
        cin >> cols;
        rows--;
        cols--;
        vector< vector<int> > val;
        vector<int> row;
        for(int j=0;j<=rows;j++){
            for (int i=0;i<=cols;i++){
                int v;
                cin >> v;
                row.push_back(v);
            }
            val.push_back(row);
            row.clear();
        }
        calculate(val,rows,cols);
        
    }
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
void calculate(vvi a, vvi b){

/*
    for (int i = 0; i < a.size(); i++){
        for(int j = 0; j<a[0].size();j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i< b.size(); i++){
        for(int j = 0; j<b[0].size();j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
*/

    for (int i = 0; i< b[0].size(); i++){

        int val = b[0][i];
        //cout << " value to search " << val << "\n";
        for (int j = 0; j < a.size(); j++){
            for (int jj = 0; jj < a[0].size(); jj++){
                if (a[j][jj] == val){
                    for(int k = 0; k<a[0].size();k++) {
                        cout << a[j][k] << " ";
                    }
                    //cout << "\n";
                    break;
                }
            }
            
            
        }
        cout << "\n";
    }

    //cout << "test case end: \n";

}

int main() {
    int T;
    cin >> T;
    for(int k = 0; k< T; k++){
        int r,c;
        cin >> r >> c;
        vvi rows(r, vector<int>(c));
        for (int i = 0; i< r; i++){
            for(int j = 0; j<c;j++) {
                cin >> rows[i][j];
            }
        }
        vvi cols(c, vector<int>(r));

        for (int i = 0; i< c; i++){
            for(int j = 0; j<r;j++) {
                cin >> cols[i][j];
            }
        }

        calculate(rows, cols);
    }
}

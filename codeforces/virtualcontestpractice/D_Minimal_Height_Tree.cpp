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
    for (int k=0;k<T;k++){
        int N;
        cin >> N;
        int pre = 0;

        int height = N>1?1:0;
        int cw = 0, nw=0;
        cin >> pre;
        for(int i=0;i<N-1;i++){
            int node;
            cin >> node;
            //cerr << "cw : " << cw << " nw : " << nw << " node: " << node << " pre : " << pre << endl;
            if (node > pre) {
                nw++;
                pre = node;
                continue;
            } else if (cw == 0) {

                // inversion happened and if we have no more parent nodes to add to then
                // create a new level (increase height)
                cw = nw - 1; // as we are counting children number of inversion allowed is -1
                nw = 1;      // counting the current child
                height++;
                pre = node;
                //cerr << "height: " << height << endl;
            } else {
                pre = node; 
                cw--; // decrease current width count so new child takes the new inversions
                nw++; // keep tab of the next width of children
            }
        }
        //cerr << "end of test case " << "\n";
        cout << height << "\n";
    }
}

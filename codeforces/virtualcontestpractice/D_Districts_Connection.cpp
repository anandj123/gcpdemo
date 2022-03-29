#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define debug(x) cerr << #x << " : " << x << "\n"
#define REP(i,a,b) for(int i=a; i<b;++i)

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

int main() {
    int t;
    cin >> t;
    REP(T,0,t){
        int n;
        cin >> n;
        vi val(n);
        REP(i,0,n){
            cin >> val[i];
        }
        set<int> s;
        s.clear();
        vector<pair<int, int> > output;
        bool found = false;
        REP(i,0,n){
            REP(j,i+1,n){
                if (s.find(j) == s.end() or s.find(i) == s.end()) {
                    if(val[i] != val[j]) {
                        output.push_back(make_pair(i,j));
                        s.insert(i);
                        s.insert(j);
                    }
                }
            }
        }
        if (s.size() == val.size()) found = true;

        if (found) {
            cout << "YES" << "\n";
            REP(i,0,output.size()) {
                cout << output[i].first + 1 << " " << output[i].second + 1<< "\n";
            }
        } else {
            cout << "NO" << "\n";
        }
    }
}

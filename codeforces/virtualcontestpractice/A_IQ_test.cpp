#include<iostream>
#include<algorithm>
#include<vector>
#include <map> 

using namespace std;

int main(){
    
    int n=1;
    cin >> n;
    vector<int> val;
    for(int i=0;i<n;i++){
        int val1;
        cin >> val1;
        val.push_back(val1);
    }

    map<int, pair<int,int> > umap;
    for(int i=0;i<n;i++){
        int mods = val[i] % 2;
        if (umap.find(mods) == umap.end()){
            umap[mods] = pair<int,int>(1, i);
        } else {
            umap[mods] = pair<int,int>(umap[mods].first + 1, i);
        }
    }

    for (map<int, pair<int, int> >::iterator it = umap.begin(); it != umap.end(); it++ ){
        if (it->second.first == 1){
            cout << it->second.second +1 << endl;
        }
    }

}
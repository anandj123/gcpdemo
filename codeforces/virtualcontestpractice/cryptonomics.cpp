#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<string>
#include<algorithm>

using namespace std;
#define write(x) cout << #x << " " << x << endl;
bool f(pair<int, int> i, pair<int, int> j){
    return (i.second - i.first) < (j.second - j.first);
}
int main(){
    string val = "WWWLLLWWLLW";
    int c1 = count(val.begin(), val.end(),"W");

    write( c1 );

    write( count(val.begin(), val.end(), 'L') );
    
    size_t idx = val.find("L");
    write(idx);
    val.insert(idx,"Hello");
    write(val);
    val.erase(idx,5);
    write(val);
    
    size_t idx2 = val.find("W",idx+1);
    write(idx2);
    write(val.substr(idx,idx2-idx));
    vector<pair<int, int> > v;
    pair<int, int> p = make_pair(idx,idx2);
    write(p.first);
    write(p.second);
    v.push_back(p);
    

    idx = val.find("L",idx2+1);
    write(idx);
    //cout << idx << endl;    
    idx2 = val.find("W",idx+1);

    p = make_pair(idx,idx2);
    write(p.first);
    write(p.second);
    v.push_back(p);
    
    sort(v.begin(),v.end());
    write(v[0].second - v[0].first);
    write(v[1].second - v[1].first);

    sort(v.begin(),v.end(),f);
    write(v[0].second - v[0].first);
    write(v[1].second - v[1].first);


    if (idx == string::npos) {
        cout << "no more string found" << endl;
    } else {
        cout << val.length() << " " << idx << endl; 
    }
    
    val.pop_back();
    val.pop_back();
    val.pop_back();
    write(val);
    
}   
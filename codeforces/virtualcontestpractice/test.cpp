#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct data{
    int count;
    vector<int> list;
};

bool s(vector<int> i, vector<int> j) {
    return i.size() < j.size();
}

bool s1(data i, data j) {
    return i.count > j.count;
}

int main(){
    vector< vector<int> > mat;
    vector<int> row;
    row.push_back(1);
    mat.push_back(row);
    row.clear();
    row.push_back(2);
    row.push_back(2);
    mat.push_back(row);
    row.clear();
    row.push_back(3);
    row.push_back(3);
    row.push_back(3);
    mat.push_back(row);
    sort(mat.begin(),mat.end(),s);
    cout << mat[0][0];
    vector<int> newVec(mat[2].begin(),mat[2].begin()+2);
    cout << newVec[0] << newVec[1];

    vector<data> d;
    data d1 = {2,{2,2}};
    d.push_back(d1);
    cout << d[0].count;

    d1={};
    d1.count = 3;
    vector<int> l = {3,3,3};
    d1.list = l;
    d.push_back(d1);

    cout << d[1].count;

    sort(d.begin(),d.end(),s1);

    cout << d[1].count;


}
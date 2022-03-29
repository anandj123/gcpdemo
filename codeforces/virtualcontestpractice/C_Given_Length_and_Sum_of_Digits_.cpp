#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int len,sum;
    cin >> len;
    cin >> sum;
    bool found = false;
    queue<string> q;
    int first, second;
    for (int i=1;i<sum;i++){
        first = i;
        second = sum - first;
        int len1, len2;
        len1 = to_string(first).length();
        len2 = to_string(second).length();
        if (len1 + len2 == len) {
            found = true;
            q.push(to_string(first) + ":" + to_string(second));
        } 
    }
    if (!found) {
        cout << "-1 -1";
    } else {
        string output1 = to_string(first) + to_string(second);
        string output2 = to_string(first) + to_string(second);
        sort(output1.begin(), output1.end());
        sort(output2.begin(), output2.end(),greater<char>());
        for (int i=0;i<output1.length();i++){
            if (output1.substr(i,1) !="0") {
                output1 = output1.substr(i,1) + output1.substr(0,i) + output1.substr(i+1,output1.length()-i-1);
                break;
            }
        }
        cout << output1 << " " << output2;
    }

}
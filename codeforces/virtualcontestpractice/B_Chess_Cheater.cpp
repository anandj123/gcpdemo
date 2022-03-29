#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
using namespace std;
bool win(char in){
    if(in == 'L'){
        return true;
    } 
    return false;
}
void calculate(string games, int cheat){
    vector<int> nums;
    int currentpoints = 0;
    for(int i = 1; i<games.length()-1;i++){
        if(win(games.at(i))){
            if(games.at(i-1)=='W' && games.at(i+1)=='W'){
                nums.push_back(3);
            } else if(games.at(i-1)=='W' || games.at(i+1)=='W'){
                nums.push_back(2);
            } else {
                nums.push_back(1);
            }
        } else {
            if(games.at(i-1)=='W'){
                currentpoints += 2;
            } else {
                currentpoints += 1;
            }
        }
    }
    if(games.at(0) == 'W'){
        currentpoints++;
    } else {
        if(games.length()>1){
            if(games.at(1) == 'W'){
                nums.push_back(2);
            } else {
                nums.push_back(1);
            }
        }
    }
    if(games.at(games.length()-1) == 'W'){
        if(games.at(games.length()-2)){
            currentpoints+=2;
        } else {
            currentpoints++;
        }
    } else {
        if(games.length()>1){
            if(games.at(games.length()-2)=='W'){
                nums.push_back(2);
            } else {
                nums.push_back(1);
            }
        }
    }
    std::sort (nums.begin(), nums.end(),greater<int>());
    for(int i = 0;i<nums.size();i++){
    }
    if(cheat > nums.size()){
        currentpoints = games.length()*2 -1;
    } else {
        for(int i = 0; i<cheat;i++){
            currentpoints+=nums[i];
        }
    }
    cout<<currentpoints<<endl;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int cheat,games;
        cin>>games;
        cin>>cheat;
        string win;
        cin>>win;
        calculate(win,cheat);
    }

}
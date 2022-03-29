#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <functional>   // std::plus
using namespace std;

void calculate(vector<int> nums){
    int size = nums.size();
    int sum = 0;
    for(int i = 0; i < size;i++){
        sum+=nums[i];
    }
    if(sum==0){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int pos=0;
        int neg=0;
        for(int i= 0;i<size;i++){
            if(nums[i]<0){
                neg+=nums[i];
                
            } else {
                pos+=nums[i];
                
            }
        }
        if(abs(neg)>abs(pos)){
            std::sort (nums.begin(), nums.end());
        } else {
            std::sort (nums.begin(), nums.end(),greater<int>());
        }
        for(int i = 0; i<size;i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int val;
        cin >> val;
        vector<int> nums;
        for(int j=0;j<val;j++){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        calculate(nums);
        nums.clear();
    }

}
#include<bits/stdc++.h>
using namespace std;
void selection(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        int min=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[min]>nums[j]){
                min=j;
            }
           
        }
        if(min!=i){
            swap(nums[min],nums[i]);
        }
    }
}
int main(){
    vector<int> nums={4,8,2,5,0,6};
    selection(nums);
    for(int num: nums){
        cout<<num<<" ";
    }
}
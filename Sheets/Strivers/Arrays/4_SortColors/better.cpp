#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0: cnt0++;break;
                case 1: cnt1++;break;
                case 2: cnt2++;break;
            }
        }
        int k=0;
        while(cnt0--){
            nums[k]=0;
            k++;
        }
        while(cnt1--){
            nums[k]=1;
            k++;
        }
        while(cnt2--){
            nums[k]=2;
            k++;
        }
    }
};
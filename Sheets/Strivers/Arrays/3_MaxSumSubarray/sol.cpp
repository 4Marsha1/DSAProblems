#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN, curSum=0;
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            maxSum=max(maxSum,curSum);
            if(curSum<0)
                curSum=0;
        }
        return maxSum;
    }
};
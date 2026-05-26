class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size()-1; i++) {
            if(nums[i]>0)
                nums[i+1]=nums[i]+nums[i+1];
            if(max<nums[i+1])
                max=nums[i+1];
        }
        return max;
    }
};

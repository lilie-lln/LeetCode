class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, i = 1;
        for (int x : nums) sum += x*(i++%2);
        return sum;
        
    }
};

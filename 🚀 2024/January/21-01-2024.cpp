//https://leetcode.com/problems/house-robber/?envType=daily-question&envId=2024-01-21
//C


class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i<nums.size(); i++){
            int temp = sum1;
            sum1 = max(sum2 + nums[i], sum1);
            sum2 = temp;
        }

        return sum1;
    }
};

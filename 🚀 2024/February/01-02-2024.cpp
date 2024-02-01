// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size() < 3)
        return {}; //null

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int sIndex = 0;
        int eIndex = 2;
        while(eIndex<nums.size()){
            if(nums[eIndex] - nums[sIndex] > k)
                return {};
            else{
                vector<int> temp;
                for(int i = sIndex; i<=eIndex; i++){
                    temp.push_back(nums[i]);
                }
                ans.push_back(temp);
            }
            sIndex += 3;
            eIndex += 3;
        }
        return ans;
    }
};

//https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

// Solution 1:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();

        //Approach 1: 
        sort(nums.begin(), nums.end());
        int i = 0;
        for(int i = 0; i<size; i++){
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
                break;
            }
        }
        
        if (nums[0] != 1){
            ans.push_back(1);
            return ans;
        } 
        else if (nums[size - 1] != size){
            ans.push_back(size);
            return ans;
        }
        else {
            int lost;
            int prev = 0; 
            for(int i = 0; i<size; i++){
                if(prev + 1 < nums[i]){
                    lost = prev + 1;
                    break;
                }
                prev = nums[i];
            }
            ans.push_back(lost);
        }
        return ans;
    }
};

// Solution 2:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //Approcah 2:
        unordered_map<int, int> freq;
        vector<int> ans;

        for(auto i: nums){
            //count frequency 
            freq[i]++;
            //number that occurs twice
            if(freq[i] == 2)
            ans.push_back(i);
        }

        for(int i = 1; i<=nums.size(); i++){
            if(!freq[i])
            ans.push_back(i);
        }

        return ans;
    }
};

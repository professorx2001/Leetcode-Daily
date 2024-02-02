//https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";
        int lows = to_string(low).length();
        int highs = to_string(high).length();

        for(int i = lows; i<=highs; i++){
            for(int j = 0; j<10 - i; j++){
                int num = stoi(digits.substr(j, i));
                if(num >= low && num <= high)
                ans.push_back(num);
            }
        }
        return ans;
    }
};

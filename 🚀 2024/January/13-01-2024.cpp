//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
//Solution 1:
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> count;
        for(int i = 0; i<s.size(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        int ans = 0;
        for(auto i: count){
            if(i.second>0)
            ans+= i.second;
        }
        return ans;
    }
};

//Solution 2:
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        for(int i = 0; i<s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        int ans = 0;
        for(int i = 0; i<26; i++){
            if(count[i]>0)
            ans += count[i];
        }
        return ans;
    }
};

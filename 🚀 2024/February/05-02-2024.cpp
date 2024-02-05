//https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

//Solution 1:
class Solution {
public:
    int firstUniqChar(string s) {
        //brute force
        unordered_map<char, int> m;
        for(auto i : s){
            m[i]++;
        }
        for(int i = 0; i<s.size(); i++){
            if(m[s[i]] == 1)
            return i;
        }
        return -1;
    }
};

// Solution 2: 
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for(auto i : s){
            v[i - 'a']++;
        }
        for(int i = 0; i<s.size(); i++){
            if(v[s[i] - 'a'] == 1)
            return i;
        }
        return -1;
    }
};

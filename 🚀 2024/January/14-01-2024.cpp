//https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int countOfWord1[26] = {0};
        int countOfWord2[26] = {0};
        for(int i = 0; i<word1.size(); i++){
            countOfWord1[word1[i] - 'a']++;
            countOfWord2[word2[i] - 'a']++;
        }
        //checking if both have same characters
        for (char ch = 'a'; ch <= 'z'; ch++) {
        if ((countOfWord1[ch - 'a'] > 0 && countOfWord2[ch - 'a'] <= 0) ||
         (countOfWord2[ch - 'a'] > 0 && countOfWord1[ch - 'a'] <= 0)) {
            return false;
        }
    }
        //checking ki frequency is same or not
        sort(countOfWord1, countOfWord1 + 26);
        sort(countOfWord2, countOfWord2 + 26);

        for (int i = 0; i < 26; i++) {
        if (countOfWord1[i] != countOfWord2[i]) {
            return false;
        }
    }
        return true;
    }
};

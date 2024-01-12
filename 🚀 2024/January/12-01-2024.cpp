//https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12

class Solution {
public:
    bool findVowels(char ch){
        switch(ch){
                case 'a': 
                return true;
                break;
                case 'e': 
                return true;
                break;
                case 'i': 
                return true;
                break;
                case 'o': 
                return true;
                break;
                case 'u': 
                return true;
                break;
                case 'A': 
                return true;
                break;
                case 'E': 
                return true;
                break;
                case 'I': 
                return true;
                break;
                case 'O': 
                return true;
                break;
                case 'U': 
                return true;
                break; 
            }
            return false;
    }
    bool halvesAreAlike(string s) {
        int countOfFirstHalf = 0;
        int countOfSecondHalf = 0;
        int length = s.length();
        
        for(int i = 0; i<length;i++){
            if(i <length/2 and findVowels(s[i]))
            countOfFirstHalf++;
            else{
                if(findVowels(s[i]))
                countOfSecondHalf++;
            }
            
        }
        return countOfFirstHalf==countOfSecondHalf ? true : false;
    }
};

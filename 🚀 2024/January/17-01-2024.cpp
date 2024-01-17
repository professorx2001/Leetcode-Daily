//https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

//Solution 1:
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto x : m ){
            int freq = x.second;
            if(s.find(freq) != s.end()) return false;
            else{
                s.insert(freq);
            }
        }
        return true;
    }
};

//Solution 2: 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        set<int> check;

        for(auto i : arr){
            count[i]++;
        }
        for(auto& i : count){
            check.insert(i.second);
        }
        return (count.size() == check.size());
    }
};

//Solution 3:
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>ans;
        sort(arr.begin(), arr.end());
        int n= arr.size();
        int i = 0;
        while(i<n){
            int count = 1;
            for(int j=i+1; j<n; j++){
                if(arr[i]==arr[j])
                count++;
            }

            ans.push_back(count);
            i = i + count;
        }
        //check in new vector if duplicate values exists
        sort(ans.begin(), ans.end());
        for(int i=0; i+1<ans.size(); i++){
            if(ans[i]== ans[i+1])
            return false;
        }
        return true;
    }

};

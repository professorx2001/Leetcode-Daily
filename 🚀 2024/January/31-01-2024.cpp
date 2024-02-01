//https://leetcode.com/problems/daily-temperatures/?envType=daily-question&envId=2024-01-31

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> v; //store positions

        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!v.empty() && v.back().first <= temperatures[i])
                v.pop_back();
        
            pair<int,int> p1 {temperatures[i], i};
            if(v.empty())
            temperatures[i] = 0;
            else
            temperatures[i] = v.back().second - i;
            v.push_back(p1);
        }


        return temperatures;
    }
};

//https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> count;
        unordered_map<int, bool> track;

        for(int i = 0; i < matches.size(); i++) {
            count[matches[i][1]]++;
            track[matches[i][0]] = true;
            track[matches[i][1]] = true;
        }
        //Lost zero matches
        for(auto i: track) {
            if(count[i.first] == 0)
                ans[0].push_back(i.first);
        }

        // Lost exactly one match
        for(auto i: count) {
            if(i.second == 1)
                ans[1].push_back(i.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};

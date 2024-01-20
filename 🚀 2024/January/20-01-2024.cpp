//https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20
//C
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        stack<int> st;
        vector<long long> v(n, -1);
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if (!st.empty()){
                int j = st.top();
                v[i] = v[j] + arr[i] * (i - j);
            }
            else
             v[i] = arr[i] * (i+1);
             
            st.push(i);
            ans = (ans + v[i]) % mod;
        }
        return ans;
    }
};

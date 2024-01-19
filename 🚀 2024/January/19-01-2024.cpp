//https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 1; row<n; row++){

            for(int col = 0; col<n; col++){
                if(col == 0){
                    matrix[row][col] += min(matrix[row-1][col+1],matrix[row-1][col]);
                }
                else if(col == n - 1){
                    matrix[row][col] += min(matrix[row-1][col-1],matrix[row-1][col]);
                }
                else{
                    matrix[row][col] += min({matrix[row-1][col-1],matrix[row-1][col],
                    matrix[row-1][col+1]});
                }
            }
        }
        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            ans = min(ans,matrix[n-1][col]);
        }
        return ans;
    }
};

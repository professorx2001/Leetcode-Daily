//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
//C
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int curMin, int curMax) {
        if(!root) return;
        ans = max({ans, root -> val - curMin, curMax - root -> val});
		curMin = min(curMin, root -> val);
        curMax = max(curMax, root -> val);
        dfs(root -> left, curMin, curMax);
        dfs(root -> right, curMin, curMax);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root -> val, root -> val);
        return ans;
    }
};

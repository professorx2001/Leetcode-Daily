//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
//C

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* root, unordered_map<int,int>&m){
        m[root->val]++;

        if(!root->left && !root->right){
            int count = 0;
            for(auto i:m) {
                if(i.second % 2 != 0) 
                count++;
            }
            if(count <= 1) 
                ans++;

            m[root->val]--;
            return;
        }

        if(root->left) 
            dfs(root->left,m);
        if(root->right) 
            dfs(root->right,m);

        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        unordered_map<int,int> m;
        
        dfs(root,m);
        return ans;
    }
};

// Md Zaki Hussain
// https://leetcode.com/problems/range-sum-of-bst/submissions/1140364116/?envType=daily-question&envId=2024-01-08

//Solution 1:
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inorderTrav){
        if(root == NULL) return;

        inorder(root->left, inorderTrav);
        cout<<root->val<<" ";
        inorderTrav.push_back(root->val);
        inorder(root->right, inorderTrav);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorderTrav;
        inorder(root, inorderTrav);
        bool flag = false;
        int sum = low;
        for(int i = 0; i<inorderTrav.size(); i++){
            if(flag)
            sum += inorderTrav[i];
            if(inorderTrav[i] == high)
            break;
            if(inorderTrav[i] == low)
                flag = true;
            

        }
        return sum;
    }
};

//Solution 2:
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans = root -> val >= low && root -> val <= high ? root -> val : 0;
        if(root -> val > low) ans += rangeSumBST(root -> left, low, high);
        if(root -> val < high) ans += rangeSumBST(root -> right, low, high);
        return ans;
    }
};

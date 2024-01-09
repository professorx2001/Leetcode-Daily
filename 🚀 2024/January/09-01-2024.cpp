//https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

class Solution {
void findLeaf(TreeNode* root, vector<int> &temp){
    if(root == NULL) return;

    if(root->left == NULL and root->right == NULL){
    temp.push_back(root->val);
    return;
    }
    
    findLeaf(root->left, temp);
    findLeaf(root->right, temp);
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       //Brute Force take two vector store all leaf node and do a linear search
        vector<int> temp1, temp2;

        findLeaf(root1, temp1);
        findLeaf(root2, temp2);

        if(temp1.size()!=temp2.size())
            return false;

        //Linear Searching for all elements
        for(int i = 0; i<temp1.size(); i++){
            if(temp1[i]!=temp2[i])
            return false;
        }

        return true;
    }
};

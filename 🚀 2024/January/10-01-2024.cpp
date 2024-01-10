//https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10

//Solution 1:
class Solution {
public:
    TreeNode* createMapping(TreeNode* root,
    unordered_map<TreeNode*, TreeNode*>& parent, int start){
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;
        TreeNode* infectedNode = NULL;
        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            if(front->val == start)
                infectedNode = front;
            if(front->left){
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right] = front;
                q.push(front->right);
            }

        }

        return infectedNode;
    }
      
    int burn(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;

        int count = 0;

        while(!q.empty()){
            bool flag = false;

            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* front = q.front();
                    q.pop();

                if(!visited[front->left] and front->left){
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }
                if(!visited[front->right] and front->right){
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }
                if(!visited[parent[front]] and parent[front]){
                    visited[parent[front]] = true;
                    q.push(parent[front]);
                    flag = true;
                }

            }
            if(flag) count++;
        }
        return count;
    }
    int amountOfTime(TreeNode* root, int start) {
        //similar to burn a tree problem
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* infectedN = createMapping(root, parent, start);

        return burn(infectedN,parent);
    }
};

//Solution 2: It is from the Discuss section but I am unable to understand return min(left, right) - 1;.
class Solution {
public:
    int maxDepth = 0;
    int dfs(TreeNode* root, int start) {
        if(root == NULL) return 0;

        int left = dfs(root -> left, start);
        int right = dfs(root -> right, start);

        if(root -> val == start) {
            maxDepth = max(maxDepth, max(left, right));
            return -1;
        }

        if(left >= 0 && right >= 0)
        return max(left, right) + 1;

        maxDepth = max(maxDepth, abs(left - right));
        return min(left, right) - 1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxDepth;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int sum, int sum_now)
    {
        if(!root)
            return ;
        if(sum_now + root->val == sum)
        {
            ans++;    
        }
        
        dfs(root->left, sum, sum_now + root->val);
        dfs(root->right, sum, sum_now + root->val);
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root,sum, 0);
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return ans;
    }
};
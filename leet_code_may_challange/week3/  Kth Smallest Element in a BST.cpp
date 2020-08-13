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
    int ans;
    void kthSmallestUtil(TreeNode* root, int &currnode, int k)
    {
        if(root == NULL || currnode > k)
            return ;

        kthSmallestUtil(root->left, currnode, k);
        currnode++;
        if(currnode == k)
        {
            ans = root->val;
            return;
        }
        kthSmallestUtil(root->right, currnode, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        kthSmallestUtil(root,cnt, k);
        return ans;
        
    }
};
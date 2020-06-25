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
    int countNodesUtil(TreeNode* root, int &sum)
    {
        if (root == NULL)
            return sum;
        sum++;
        countNodesUtil(root->left, sum);
        countNodesUtil(root->right, sum);
        return sum;
    }
    int countNodes(TreeNode* root) {
        int sum = 0;
        return countNodesUtil(root, sum);
        
    }
};
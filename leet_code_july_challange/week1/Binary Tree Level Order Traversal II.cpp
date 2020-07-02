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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
        {
            vector<vector<int>> tmp = {};
            return tmp;
        }
        
        queue<TreeNode*> q;
        vector<vector<int>> result;
        vector<vector<int>> answer;
        int levels  = 0;
        q.push(root);
        // q.push(NULL)
        while(!q.empty())
        {
            vector<int> level_traversal = {};
            int l = q.size();
            while(l--)
            {
                auto tmp = q.front();
                level_traversal.push_back(tmp->val);
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            answer.push_back(level_traversal);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
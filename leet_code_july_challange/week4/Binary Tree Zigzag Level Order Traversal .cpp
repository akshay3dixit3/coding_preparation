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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> ltor;
        stack<TreeNode*> rtol;
        vector<vector<int>> answer;
        
        if(!root)
            return answer;
        
        ltor.push(root);
        vector<int> tmp;
        while(!ltor.empty() || !rtol.empty())
        {
            tmp = {};
            while(!ltor.empty())
            {
               TreeNode* tmp_node = ltor.top();
                ltor.pop();
                tmp.push_back(tmp_node->val);
            if(tmp_node->left)
                rtol.push(tmp_node->left);
            if(tmp_node->right)
                rtol.push(tmp_node->right);
            }
            if(tmp.size() > 0)
             answer.push_back(tmp);
            
            tmp = {};
            while(!rtol.empty())
            {
                TreeNode* tmp_node = rtol.top();
                rtol.pop();
                tmp.push_back(tmp_node->val);
                if(tmp_node->right)
                    ltor.push(tmp_node->right);
                if(tmp_node->left)
                    ltor.push(tmp_node->left);
            }
            if(tmp.size() > 0)
                answer.push_back(tmp);
        }
        return answer;
    }
};
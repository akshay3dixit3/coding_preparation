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
    TreeNode* searchBST(TreeNode* root, int val) {
       while(root)
       {
           // cout<<root->val<<endl;
           if(root->val == val)
                return root;
           if(root->val > val && root->left) // then is should be in left subtree
           {
               root = root->left;
               continue;
           }
           if(root->val > val && !(root->left))
           {
               break;
           }
           
           if(root->val < val && root->right)
           {
               root = root->right;
               continue;
           }
           if(root->val < val && !(root->right))
           {
               break;
           }
           
       }
        TreeNode* head = NULL;
        return head;
    }
};

//REALLY EASY SOLUTION.
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//  while(root && root->val != val) root = root->val < val ? root->right : root->left;
//   return root;
//     }
// };
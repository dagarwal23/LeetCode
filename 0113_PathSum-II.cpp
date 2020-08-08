/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

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
    
    
    void helper(TreeNode* root,int sum,vector<int> &curr,vector<vector<int>> &ans)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==sum)
            {
                curr.push_back(root->val);
                ans.push_back(curr);
                curr.pop_back();
            }
            return;
        }
        
        curr.push_back(root->val);
        helper(root->left,sum-root->val,curr,ans);
        helper(root->right,sum-root->val,curr,ans);
        curr.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        vector<int> curr;
        helper(root,sum,curr,ans);
        return ans;
    }
};

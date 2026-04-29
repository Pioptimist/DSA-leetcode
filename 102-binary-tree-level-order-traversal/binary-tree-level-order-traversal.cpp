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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            TreeNode* node = q.front();
            for(int i =0;i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left !=nullptr) q.push(node->left);
                if(node->right !=nullptr) q.push(node->right);
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;

        
    }
};
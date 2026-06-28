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
    int f(TreeNode* root ,vector<int> &v){
        if(!root) return -1;

        int left = f(root->left,v);
        int right = f(root->right,v);
        if(left==-1 && right == -1){
            v.push_back(root->val);
        }

        return 0;


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;

        vector<int> v1;
        vector<int> v2;
        f(root1 , v1);
        f(root2, v2);
        return v1==v2;
        
    }
};
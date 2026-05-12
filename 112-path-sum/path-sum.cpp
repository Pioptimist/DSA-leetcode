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
    bool f(TreeNode* node, int t , int s){
        if(node == NULL) return false;

        s += node->val;
        if(node->left == NULL && node->right ==NULL){
            if(s == t){
                return true;
            }
            return false;
        }

        return f(node->left , t , s)  || f(node->right , t, s);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return f(root , targetSum , sum);

        
    }
};
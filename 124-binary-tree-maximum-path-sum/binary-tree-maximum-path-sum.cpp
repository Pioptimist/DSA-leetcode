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
    int f(TreeNode* node , int &maxi){
        if(node == nullptr){
            return 0;

        }

        int lhs = max(0 , f(node->left , maxi));
        int rhs = max(0 , f(node->right , maxi));

        maxi = max( maxi , node->val + lhs + rhs);

        return node->val + max(lhs , rhs);

    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxi = INT_MIN;

        f(root , maxi);
        return maxi;
        
        
    }
};
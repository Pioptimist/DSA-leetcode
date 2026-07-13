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
    int f(TreeNode* node , int &cnt , int k){
        if(node == NULL) return -1;

        int lhs = f(node->left , cnt , k);
        if(lhs != -1){
            return lhs;
        }

        cnt++;
        if(cnt == k){
            return node->val;
        }

        return f(node->right , cnt , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        int cnt = 0;
        return f(root , cnt , k);
        
    }
};
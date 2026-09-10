/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
// jis pt pe do alg alg side jana pde , that same node is lca
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        while(root){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else{
                return root;
            }
        }

        return NULL;


    }
};
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
    TreeNode* findLR(TreeNode* root){
        if(root->right == NULL) return root;

        return findLR(root->right);
    }

    TreeNode* helper(TreeNode* node){
        if(node->left == NULL) return node->right;
        if(node->right == NULL) return node->left;

        TreeNode* left = node->left;
        TreeNode* temp = node->right;
        TreeNode* lastR = findLR(left);
        lastR->right = temp;

        return left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return helper(root);

        TreeNode* curr = root;
        while(root){
            if(root->val > key){ // stop at the node befre the key
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }

            }
        }
        return curr;
         
    }
};
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
        if(node->left == NULL){
            return node->right;
        }
        if(node->right == NULL){
            return node->left;
        }

        TreeNode* rightR = node->right;
        TreeNode* lastR = findLR(node->left);

        lastR->right = rightR;

        return node->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val > key){
                if(temp->left != NULL && temp->left->val == key){
                   temp->left = helper(temp->left);
                   break;
                }
                else{
                    temp = temp->left;
                }

            }
            else{
                if(temp->right != NULL && temp->right->val == key){
                   temp->right = helper(temp->right);
                   break;
                }
                else{
                    temp = temp->right;
                }

            } 

        }
        return root;
        
    }
};
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
//  logic is agar kisi bhi lvl mein null ke baad , tree ka koi non null node aata hai toh that tree is incomplete ie ek non null node right side aa gya when every node should be as left as possible.
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);

        bool wasN = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                wasN = true;
            }
            else {
                if(wasN)
                    return false;

                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
        
    }
};
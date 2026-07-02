/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     LL val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef long long LL;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        LL res = 0;
        queue<pair<TreeNode* , LL>> q; //node , ind
        q.push({root , 0});
        LL left , right;
        while(!q.empty()){
            
            LL n = q.size();
            LL mn = q.front().second;

            for(LL i = 0;i < n ; i++){
                auto [node, ind] = q.front();
                q.pop();

                ind -= mn;
                if (i == 0) left = ind;
                if (i == n - 1) right = ind;
        
                if(node->left != NULL) q.push({node->left , 2*ind + 1});
                if(node->right != NULL) {
                    q.push({node->right , 2*ind + 2});
                }

            }
            res = max(res , right - left + 1);
        }
        return res;
        
    }
};
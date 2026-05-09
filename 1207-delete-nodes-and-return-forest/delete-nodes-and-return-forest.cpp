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
   TreeNode* f(TreeNode* node , unordered_set<int> &st , vector<TreeNode*> &res){
    if(node == nullptr) return NULL;

    node->left = f(node->left , st , res);
    node->right  = f(node->right , st , res);

    if(st.find(node->val) != st.end()){
        if(node->left != NULL) res.push_back(node->left);
        if(node->right != NULL) res.push_back(node->right);

        return NULL;
    }
    else{
        return node;
    }

   }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s;
        for(auto num : to_delete){
            s.insert(num);
        }

        TreeNode* remainingRoot = f(root, s, res);

        if(remainingRoot != NULL)
            res.push_back(remainingRoot);

        return res;
        
    }
};
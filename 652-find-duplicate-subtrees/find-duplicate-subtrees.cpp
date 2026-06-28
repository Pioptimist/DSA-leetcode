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
//convert each subtree into str store it in map , if we visit that same str again ,store in ans.
    vector<TreeNode*> res;
    map<string , int> mp;

    string f(TreeNode* root , map<string,int> &mp , vector<TreeNode*> &res){
        if(!root) return "N";

        string s = to_string(root->val) +"_"+ f(root->left , mp , res) +"_"+ f(root->right,mp,res);

        if(mp[s] == 1){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        f(root , mp , res);
        return res;
    }
};
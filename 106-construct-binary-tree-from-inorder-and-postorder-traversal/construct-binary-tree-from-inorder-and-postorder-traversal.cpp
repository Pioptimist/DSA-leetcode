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
    TreeNode* buildBTfromInPost(vector<int>& inorder, int is, int iend,
vector<int>& postorder, int ps, int pend,
map<int,int> &hm){
        if(is > iend || ps > pend) return NULL;

        TreeNode* root = new TreeNode(postorder[pend]);

        int inroot = hm[postorder[pend]];
        int numleft = inroot - is;

        root->left = buildBTfromInPost(
            inorder, is, inroot - 1,
            postorder, ps, ps + numleft - 1, hm
        );

        root->right = buildBTfromInPost(
            inorder, inroot + 1, iend,
            postorder, ps + numleft, pend - 1, hm
        );

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> hm;
        for(int i = 0; i < inorder.size(); i++){
            hm[inorder[i]] = i;
        }
        int n = inorder.size();
        if(n != postorder.size()) return NULL;

        return buildBTfromInPost(inorder, 0, n-1,postorder, 0, n-1, hm);
    }

    
};
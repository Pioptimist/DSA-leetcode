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
    TreeNode* f(int ps , int pos , int pend , vector<int>& preorder, vector<int>& postorder){
        if(ps > pend) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        if(ps == pend) return root; //mtlb ek hi node bacha hai toh usko return

        int next = preorder[ps+1]; //root of leftsubtree

        //now we need to find this in postorder
        int j = pos;
        while(postorder[j] != next){
            j++;
        }

        int nums = j - pos + 1; //number of elements in left subtree, all of these are in left side of root of left subtre as in postorder LRRoot

        
        root->left = f(ps+1 , pos , ps + nums , preorder , postorder);
        root->right = f(ps + nums + 1 , j + 1 , pend , preorder , postorder);

        return root;


    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        return f(0 , 0 , n-1 , preorder , postorder); //pres , posts , preend
        
    }
};
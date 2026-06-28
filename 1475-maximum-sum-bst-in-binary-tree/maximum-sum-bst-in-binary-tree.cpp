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
class Nodevalue{
public:
    int maxS;
    int maxN;
    int minN;

    Nodevalue(int maxS ,int maxN ,int minN){
        this->maxS = maxS;
        this->maxN = maxN;
        this->minN = minN;
    }
};
class Solution {
public:
    long long ans=0;
    Nodevalue f(TreeNode* root){
        if(!root){
            //NULL ptr so return [0 , INT_MIN , INT_MX];
            return Nodevalue(0 , INT_MIN, INT_MAX);

        }
        Nodevalue left = f(root->left);
        Nodevalue right = f(root->right);

//rem ans keeps the max sum found so far , our maxS keeps the sum of bst

        if(left.maxN < root->val && root->val < right.minN){
            ans = max(ans, (long long)root->val + left.maxS + right.maxS);

            return Nodevalue(root->val + left.maxS + right.maxS , 
            max(root->val , right.maxN),
            min(root->val , left.minN) );
        }
        else{
            return Nodevalue( 0, INT_MAX , INT_MIN);
        }
    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
        
    }
};
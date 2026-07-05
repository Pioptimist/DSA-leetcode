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
    int sum;
    int maxN;
    int minN;

    Nodevalue(int sum ,int maxN ,int minN){
        this->sum = sum;
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

//rem ans keeps the max sum found so far , our sum keeps the sum of bst

        if(left.maxN < root->val && root->val < right.minN){
            ans = max(ans, (long long)root->val + left.sum + right.sum);

            return Nodevalue(root->val + left.sum + right.sum , 
            max(root->val , right.maxN),
            min(root->val , left.minN) );
        }
        else{
            return Nodevalue( 0, INT_MAX , INT_MIN);
//dont confuse the above line with the largest bst in bt ,in there we did maxof left size and right size bcz the class var itself was holding the max size , here we are storing the max value in ans variable and hence we returned 0 kyuki neeche bst nhi bna toh sum kis baat ka.
        }
    }
    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
        
    }
};
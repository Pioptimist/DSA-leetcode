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
// class Nodevalue{
// public:
//     int sum;
//     int maxN;
//     int minN;

//     Nodevalue(int sum ,int maxN ,int minN){
//         this->sum = sum;
//         this->maxN = maxN;
//         this->minN = minN;
//     }
// };
// class Solution {
// public:
//     long long ans=0;
//     Nodevalue f(TreeNode* root){
//         if(!root){
//             //NULL ptr so return [0 , INT_MIN , INT_MX];
//             return Nodevalue(0 , INT_MIN, INT_MAX);

//         }
//         Nodevalue left = f(root->left);
//         Nodevalue right = f(root->right);

// // ans keeps the max sum found so far , our sum keeps the sum of current bst

//         if(left.maxN < root->val && root->val < right.minN){ // its a BST
//             ans = max(ans, (long long)root->val + left.sum + right.sum);

//             return Nodevalue(root->val + left.sum + right.sum , 
//             max(root->val , right.maxN),
//             min(root->val , left.minN) );
//         }
//         else{ //not a bst so any tree which includes this is also not a bst
//             return Nodevalue( 0, INT_MAX , INT_MIN);
// //dont confuse the above line with the largest bst in bt ,in there we did maxof left size and right size bcz the class var itself was holding the max size , here we are storing the max value in ans variable and hence we returned 0 kyuki neeche bst nhi bna toh sum kis baat ka, humara answer alr ans variable mein stored hai.
//         }
//     }
//     int maxSumBST(TreeNode* root) {
//         f(root);
//         return ans;
        
//     }
// };

struct NodeValue {
    int sum;
    int maxN;
    int minN;
};

class Solution {
public:
    int ans = 0; // standard int is sufficient based on constraints

    NodeValue f(TreeNode* root) {
        if (!root) {
            // Empty tree is a valid BST with sum 0
            return {0, INT_MIN, INT_MAX};
        }

        NodeValue left = f(root->left);
        NodeValue right = f(root->right);

        // Check if the current tree is a valid BST
        if (left.maxN < root->val && root->val < right.minN) {
            int currentSum = root->val + left.sum + right.sum;
            ans = max(ans, currentSum);

            return {
                currentSum, 
                max(root->val, right.maxN), 
                min(root->val, left.minN)
            };
        } 
        
        // Not a BST, return invalid bounds to fail parent checks
        return {0, INT_MAX, INT_MIN};
    }

    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
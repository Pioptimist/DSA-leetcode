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
class NodeValue {
public:
    int minNode, maxNode, currentSum;

    NodeValue(int minNode, int maxNode, int currentSum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->currentSum = currentSum;
    }
};

class Solution {
    int globalMaxSum = 0;
private:
    NodeValue maxSumBSTHelper(TreeNode* root) {

        // An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree
        auto left = maxSumBSTHelper(root->left);      // both of these return temp obj of type nodeval
        auto right = maxSumBSTHelper(root->right);

        // If current subtree is BST
        if (left.maxNode < root->val && root->val < right.minNode) {

            int currentBstSum = left.currentSum + right.currentSum + root->val;
            
            // Update the global maximum if this BST's sum is the largest we've seen
            globalMaxSum = max(globalMaxSum, currentBstSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currentBstSum
            );
        }

        // If not BST, return invalid range
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        globalMaxSum = 0; 
        maxSumBSTHelper(root);
        return globalMaxSum;
    }
};
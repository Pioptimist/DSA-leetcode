/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool f(TreeNode* root , ListNode* head){
        if(!head) return true;
        if(!root) return false;
        

        if(head->val != root->val) return false;

        return f(root->left , head->next) || f(root->right , head->next);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false; //null mil gya toh false
        
        return f(root , head) || isSubPath(head , root->left) || isSubPath(head , root->right);

    }
};
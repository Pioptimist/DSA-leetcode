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
    int n;
//traverse the string , remember its preorder so we keep going left first , as soon as our depth 'd' doesnt match number of dash , return null and backtrack and check right till d == dash.   we did the while loop num thing bcz in the string we can have two or three digit numberts too like "123--1-34" ie nodes are 123 , 1, 34 , our way helps to form the num correctly 
    TreeNode* f(string s , int &i , int d){
        if(i >= n) return NULL;

        int j = i;
        while(j < n && s[j]=='-'){
            j++;
        }
        int dash = j - i;
        if(dash != d) return NULL;
        i = j;
        int num = 0;
        while(i < n && isdigit(s[i])){
            num = (num*10) + (s[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(num);
        root->left = f(s , i , d+1);
        root->right = f(s , i , d+1);

        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0;
        int d = 0;

        return f(traversal , i , d);
        
    }
};
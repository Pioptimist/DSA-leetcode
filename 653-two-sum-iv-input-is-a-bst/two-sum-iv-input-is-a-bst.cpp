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


class BSTiterator {
    stack<TreeNode*> st;
    bool reverse;
private:
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(reverse == true ){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
            
    }
public:
    BSTiterator(TreeNode* root, bool isRev) {
        reverse = isRev;
        pushAll(root);    
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(reverse == true) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr ) return false;

        BSTiterator l(root, false);
        BSTiterator r(root, true);
        
        int left = l.next();
        int right = r.next();

        while( left < right ){

            if(left + right == k ) return true; 
            else if(left + right > k){
                right = r.next();
            }
            else{
                left = l.next();
            }

        }
        return false;    
    }
};

// //a simple dfs kro and agr k - root->val ko pehle vis kiya hai toh true return kro
// class Solution {
// public:
//     unordered_set<int>seen;
//     bool dfs(TreeNode* root,int k){
//         if(!root) return false;
//         if(seen.count(k-root->val)) return true;

//         seen.insert(root->val);

//         return dfs(root->left,k) || dfs(root->right,k);
//     }
//     bool findTarget(TreeNode* root, int k) {
//       return dfs(root,k);  
//     }
// };
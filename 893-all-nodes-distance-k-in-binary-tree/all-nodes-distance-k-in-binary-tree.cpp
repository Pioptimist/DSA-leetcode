/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(unordered_map<TreeNode*, TreeNode*> &parents, TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left) {
            parents[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            parents[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    markParents(parents, root);
    q.push(target);
    visited[target] = true;
    int dist = 0;
    while(!q.empty()) {
        int n = q.size();
        if(dist == k) break;
        
        for(int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]) {
                visited[curr->left] = true;
                q.push(curr->left);
            }
            if(curr->right && !visited[curr->right]) {
                visited[curr->right] = true;
                q.push(curr->right);
            }
            if(parents[curr] && !visited[parents[curr]]) {
                visited[parents[curr]] = true;
                q.push(parents[curr]);
            }
        }
        dist++;
    }
    vector<int> res;
    while(!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
}
};
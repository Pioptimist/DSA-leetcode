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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode* , pair<int , int>>> q; //node , x , lvl
        map<int , map<int , multiset<int>>> mp; // x , lvl , nodes val in that x,lvl in multiset bcz allows duplicates and sorted in cases two or more nodes share same (x,lvl)
        vector<vector<int>> res;
        if(root == nullptr) return res;

        q.push({root , {0 , 0}});

        while(!q.empty()){
    
            int n = q.size();

            for(int i = 0  ; i < n ; i++){
                auto p = q.front();
                TreeNode* node = p.first;
                int x = p.second.first;
                int lvl = p.second.second;

                q.pop();

                if(node->left != NULL) q.push({node->left , { x - 1 , lvl + 1}});
                if(node->right != NULL) q.push({node->right , { x + 1 , lvl + 1}});

                mp[x][lvl].insert(node->val); // using insert bcz its a se
            }

        }
//now those nodes which has same x goes in col vector , also map keys are always sorted so thats a plus pt.
        for(auto p : mp){
            vector<int> col;
            for(auto k : p.second){  //inner map ke keys y or lvl pe traverse
                col.insert(col.end(), k.second.begin(), k.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};


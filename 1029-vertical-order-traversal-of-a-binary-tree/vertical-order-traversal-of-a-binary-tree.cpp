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
        queue<pair<TreeNode* , pair<int , int>>> q;  //node , x , lvl
        map<int , map<int , multiset<int>>> mp;  // x , lvl , nodes val in that x,lvl in multiset bcz allows duplicates and sorted in cases two or more nodes share same (x,lvl)
        vector<vector<int>> res;
        if(root == nullptr) return res;

        q.push({root , {0 , 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first ; 
            int x = p.second.first;
            int lvl = p.second.second;
            if(node->left){
                q.push({node->left , {x - 1, lvl + 1}});
            }
            if(node->right){
                q.push({node->right , {x + 1, lvl + 1}});
            }

            mp[x][lvl].insert(node->val);// using insert bcz its a set

        }
//now those nodes which has same x goes in col vector , also map keys are always sorted so thats a plus pt.
        for(auto p : mp){
            vector<int> col;
            for(auto k : p.second){  //inner map ke keys y atq lvl traverse 
                col.insert(col.end() , k.second.begin(), k.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};


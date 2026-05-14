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
        map<int , map<int , multiset<int>>> mp;
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

            mp[x][lvl].insert(node->val);

        }

        for(auto p : mp){
            vector<int> col;
            for(auto k : p.second){
                col.insert(col.end() , k.second.begin(), k.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};

// queue<pair<TreeNode*,pair<int,int>>> q;  //Q({node , {x , lvl}})
//         map<int,map<int,multiset<int>>> mp; //MP({x -> {lvl -> {nodes at x , lvl}}})

//         q.push({root,{0,0}});
//         // simple bfs
//         while(!q.empty()){
//             auto p = q.front();
//             q.pop();
//             TreeNode* node = p.first;
//             int x = p.second.first;
//             int lvl = p.second.second;
//             if(node->left) q.push({node->left,{x-1,lvl+1}});
//             if(node->right) q.push({node->right,{x+1,lvl+1}});
//             mp[x][lvl].insert(node->val); //multiset mein insert
//         }

//         vector<vector<int>> res;
//         for(auto p : mp){
//             vector<int> col;
//             for(auto q : p.second){
//                 col.insert(col.end(), q.second.begin(), q.second.end());
 
//             }
//             res.push_back(col);
//         }
//         return res;
class Solution {
public:
//hr node ka only one parent , only one node with no parent , connected components only, no cycles
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        map<int , int> mp;
        for(int i = 0 ; i < n ; i++){
            int node = i;
            int leftc = leftChild[i];
            int rightc = rightChild[i];

            if(leftc != -1){
                if(mp.find(leftc)!= mp.end()) return false;
                mp[leftc] = i;
            } 

            if(rightc != -1){
                if(mp.find(rightc)!= mp.end()) return false;
                mp[rightc] = i;
            }
        }
    
        vector<int> root;
        for(int i = 0 ; i < n ; i ++){
            if(mp.find(i) ==mp.end()){
                root.push_back(i);

            }

        }
        if(root.size() == 0 || root.size() > 1) return false;

        int r = root[0];
        vector<bool> vis(n, false);
        queue<int> q;
        int cnt = 1;
        q.push(r);
        vis[r] = true;
        
        while(!q.empty()) { 
            int j = q.size();

            for(int i = 0 ; i  < j ; i ++){
                int node = q.front();
                q.pop();
                if(leftChild[node] != -1 && !vis[leftChild[node]]){
                    cnt++;
                    q.push(leftChild[node]);
                }
                if(rightChild[node] != -1 && !vis[rightChild[node]]){
                    cnt++;
                    q.push(rightChild[node]);
                }

            }

        }

        return cnt == n;

        
        
    }
};
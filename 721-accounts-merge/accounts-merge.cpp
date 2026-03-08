class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int> mpMails;

        for(int i =0; i< n; i++){
            for(int j = 1 ; j< accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mpMails.find(mail) == mpMails.end()){
                    mpMails[mail] = i;
                }
                else{
                    dsu.unite(i , mpMails[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(n);
        for(auto it : mpMails){
            string mail = it.first;
            int node = dsu.find(it.second);

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(mergedMails[i].size() == 0) continue;

            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            sort(mergedMails[i].begin(), mergedMails[i].end());
            for(auto &it : mergedMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};
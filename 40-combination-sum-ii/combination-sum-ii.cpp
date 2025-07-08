class Solution {
public:
    void findcomb(int ind,int n,vector<vector<int>> &ans,vector<int>& candidates, vector<int> &ds,int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i =ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            findcomb(i+1,n,ans,candidates,ds,target-candidates[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        findcomb(0,n,ans,candidates,ds,target);
        return ans;
        
    }
};
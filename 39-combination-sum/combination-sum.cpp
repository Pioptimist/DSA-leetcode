class Solution {
public:
    void findcomb(int ind,int target,int n,vector<vector<int>> &ans,vector<int> &ds, vector<int> &candidates){
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findcomb(ind,target-candidates[ind],n,ans,ds,candidates);
            ds.pop_back();
        }
        findcomb(ind+1,target,n,ans,ds,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        findcomb(0,target,n,ans,ds,candidates);
        return ans;
    }
};
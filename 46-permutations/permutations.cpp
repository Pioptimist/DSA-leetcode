class Solution {
public:
    void perm(vector<int>& nums,vector<vector<int>>& ans, int n,unordered_map<int,int> &used,vector<int> &ds){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i =0;i<n;i++){
            if(used[nums[i]]==0){
                used[nums[i]]=1;
                ds.push_back(nums[i]);
                perm(nums,ans,n,used,ds);
                ds.pop_back();
                used[nums[i]] =0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        unordered_map<int,int> used;
        for(int i =0;i<n;i++){
            used[nums[i]]=0;
        }
        perm(nums,ans,n,used,ds);
        return ans;
    }
};
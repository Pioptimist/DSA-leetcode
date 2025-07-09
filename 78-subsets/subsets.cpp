class Solution {
public:
    void prints(int ind,vector<int>& nums,vector<int> &ds,vector<vector<int>> &ans,int n){
        if(ind==n){
          ans.push_back(ds);
          return;
        }
        ds.push_back(nums[ind]);
        prints(ind+1,nums,ds,ans,n);
        ds.pop_back();
        prints(ind+1,nums,ds,ans,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        prints(0,nums,ds,ans,n);
        return ans;
    }
};
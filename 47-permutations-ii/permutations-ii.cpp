class Solution {
public:
    void findperm(vector<int>& nums, vector<vector<int>> &ans,int n,int ind){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for(int i=ind;i<n;i++){
            if(seen.find(nums[i])!=seen.end()) continue;
            seen.insert(nums[i]);
            swap(nums[ind],nums[i]);
            findperm(nums,ans,n,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        findperm(nums,ans,n,0);
        return ans;
    }
};
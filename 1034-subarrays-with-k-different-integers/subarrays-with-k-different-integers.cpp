class Solution {
public:
    int subarrWithkorless(vector<int>& nums, int k){
        int l =0,r=0,cnt=0;
        map<int,int> mpp;
        int n = nums.size();
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);   //can erase using iterator too
                }
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int g = subarrWithkorless(nums, k);
        int lg = subarrWithkorless(nums,k-1);

        return (g-lg);
        
    }
};
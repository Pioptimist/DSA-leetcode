class Solution {
public:
    int f(vector<int> &nums , int m){
        int e = 0;
        int sub = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] + e <= m){
                e += nums[i];
            }
            else{
                sub++;
                e = nums[i];
            }
        }
        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin() , nums.end());

        int h = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while(l <= h){
            int m = l + (h - l)/2;

            if(f(nums , m) <= k){
                ans = m;
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return ans;
    }
};
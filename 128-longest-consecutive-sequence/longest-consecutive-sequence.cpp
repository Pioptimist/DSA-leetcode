class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int cntcurr = 0;
        int longest = 1;
        int lastsmall = INT_MIN;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0) return 0;
        for(int i = 0 ; i < n ; i++){

            if(nums[i] == lastsmall) continue;
            if(nums[i] - 1 == lastsmall){
                cntcurr++;
                lastsmall = nums[i];
            }
            else if(nums[i] - 1 != lastsmall){
                cntcurr = 1;
                lastsmall = nums[i];
            }
            longest = max(longest , cntcurr);
        }

        return longest;
        
    }
};
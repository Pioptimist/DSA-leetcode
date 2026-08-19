class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        //treating even = +1 and odd = -1
        vector<int> cumSum(n, 0);

        int maxL = 0;

        unordered_map<int, int> mp;

        for(int r = 0; r < n; r++) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if(mp.count(nums[r])) {
                prev = mp[nums[r]];
            }

            if(prev != -1) { //we have seen this element in past
                for(int l = 0; l <= prev; l++) {
                    cumSum[l] -= val;
                }
            }

            for(int l = 0; l <= r; l++) {
                cumSum[l] += val;
            }

            for(int l = 0; l <= r; l++) {
                if(cumSum[l] == 0) {
                    maxL = max(maxL, r-l+1);
                    break;
                }
            }

            mp[nums[r]] = r;
        }

        return maxL;
    }
};
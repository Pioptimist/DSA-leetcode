class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r= 0;
        int zerocnt = 0;
        int maxlen = 0;
        while( r < n){
            if(nums[r] == 0 ) zerocnt ++;
            if(zerocnt > k ){
                while(nums[l] == 1 ){
                    l++;
                }
                l++;
                zerocnt--;
            }
            
            if(zerocnt <= k ){
                int len = r - l + 1;
                maxlen = max(maxlen , len  );
            }

            r++;
        }
        return maxlen;
        
    }
};
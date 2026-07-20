class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> length(n, 1); // LIS length ending at i or dp[i]
        vector<int> count(n, 1);  // how many lis at index i
        
        int maxLen = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){  
                    if(length[j] + 1 > length[i]){
                        length[i] = length[j] + 1;
                        count[i] = count[j]; // inherit count so for eg [1, 6] we are at 6 and 1,6 can make a inc subseq so , len = 1+ dp[index of 1] a,d cnt of this subseq at 6 will be cnt of 1 , bcz say till 1, we had [0,1] and [-1.1] so cnt of seq at 1 = 2 , and then possible seq ending at will be 2 too bcz [0,1,6] and [-1 , 1 , 6]
                    }
                    else if(length[j] + 1 == length[i]){
                        count[i] += count[j]; // add ways
                    }
                }
            }
            
            maxLen = max(maxLen, length[i]);  //store lcs
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(length[i] == maxLen){  //if equals to lcs then only cnt;
                ans += count[i];
            }
        }
        
        return ans;
    }
};
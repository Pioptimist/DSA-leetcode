class Solution {
public:
//     int n;
//     vector<int> nums;
//     unordered_map<string, int> dp;

//     int f(int p, int diff) {

//         if (p == n)
//             return 0;

//         string key = to_string(p) + "#" +
//                      to_string(diff);

//         if (dp.count(key))
//             return dp[key];

//         // int skip = extend(idx+1, prev, diff);  //recursion with three states
// //in this notice we dont take the first valid element which satisfies the diff , bcz in case of duplicates , ans will vary.
//         // int take = 0;

//         // if(nums[idx] - nums[prev] == diff)
//         //    take = 1 + extend(idx+1, idx, diff);

//         // return max(skip, take);
//         int ans = 0;

//         for(int k = p+1; k<n; k++){

//             if(nums[k]-nums[p]==diff){
//                 ans=max(ans,1+f(k,diff));   //reduced state method but still O(n3)
//             }

//         }
//         return ans;
//     }

//     int longestArithSeqLength(vector<int>& arr) {

//         nums = arr;
//         n = nums.size();

//         if (n <= 2)
//             return n;

//         int ans = 2;

//         // Pick the first two elements
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {

//                 int diff = nums[j] - nums[i];

//                 ans = max(ans, 2 + f(j , diff));
//             }
//         }

//         return ans;
//     }

       int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        if(n <= 2)
            return n;
        
        vector<vector<int>> dp(n, vector<int>(1001,0)); //we are taking 1000 here bcz we are told nums[i] can be at max 500 and at min 0 so their diff can -500 to +500 , therefore 1001

        //dp[i][j] = Max AP length till ith index (0 to i) having common difference j

        int result = 0;
        
        for (int i = 1; i<n; i++) {
            
            for (int j=0; j<i; j++) {
                
                int diff    = nums[i] - nums[j] + 500; //to avoid negative diff
                
                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
//the above condition means if diff = 0 , means initial state and we havent taken two elements yet , so we take the jth and this ith , update ith to 2 , otherwise if diff > 0 then an ap already exist with a diff , so just like LIS , update the length
                result = max(result, dp[i][diff]);
            }
        }

        return result;
    }
};
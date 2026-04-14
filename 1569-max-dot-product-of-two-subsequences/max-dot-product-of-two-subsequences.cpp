class Solution {
public:
    int n , m;
    vector<vector<int>> dp;

    int f(int i , int j , vector<int>& nums1, vector<int>& nums2){
        if(i == n || j == m){
            return -1e9+7;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int val = nums1[i]*nums2[j];
        int take_b = nums1[i]*nums2[j] + f(i+1, j+1 , nums1,nums2);
        int take_i = f(i , j+1 , nums1 , nums2);
        int take_j = f(i+1 , j , nums1 , nums2);

        return dp[i][j] = max({val , take_b, take_i , take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        dp.assign(n+1 , vector<int>(m+1 , -1));

        return f(0 , 0 , nums1 , nums2);
        
    }
};
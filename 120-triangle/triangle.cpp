class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
    //since recurence f(i,j) = triangle[i][j] + min(f(i+1,j), f(i+1,j+1)) goes to next row , so to fill the dp table we need to know the next row answer already ie for base case which is i == n-1 , we need to have the last row with us hence we should just make dp = triangle
        vector<vector<int>> dp = triangle; 

        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0 ; j--){   //just think i aur j kaha se kaha tk ki value le skte so we start from second last row and thats why to fill second last row we do 0 to i for j bcz jitna i hai utne elements hai
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
//in top down notice we can go to each and every cell possible, we wont miss ay cell out.


// class Solution {
// public:
//     int f(int n , int i , int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
//         if(i == n-1){
//             return triangle[i][j];
//         }
//         if(dp[i][j] !=-1) {
//             return dp[i][j];
//         }
//         int cur = triangle[i][j] + f(n , i+1 , j , triangle, dp);
//         int nxt = triangle[i][j] + f(n , i+1 , j+1 , triangle , dp);

//         return dp[i][j] = min(cur , nxt);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n , vector<int>(n,-1));
//         return f(n , 0 , 0 , triangle, dp);
//     }
// };


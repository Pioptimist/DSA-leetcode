class Solution {
public:
//now i,j is the position on the cuts array , from these we have no way to know whcih stick we are cutting and of what length , we can try to send extra info to the func but that willl just memory choke and inc tc hence we add the 0 and n at the end of the cuts arr and use that formula to get the length of the current stick we are gonna cut.

    int f(int i , int j , vector<int>& cuts , vector<vector<int>> &dp){
        if(i > j) return 0; //no more cuts possible
        

        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k <=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + f(i , k-1 , cuts , dp) + f(k+1 , j , cuts ,dp);

            mini = min(mini , cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {

        //sorting is imp bcz without sorting for eg say [1,3,4,5,2] we cut at 4 , [1,3] and now [5,2] cleary the [5,2] is now dependent on [1,3] subproblem bcz now if i say i cut at 2 , i would be effectively messing up wit the left subproblem , thats why sorting makes sure each subproblem is independent in its nature.

        sort(begin(cuts) , end(cuts));
        int m = cuts.size();
        cuts.insert(cuts.begin() , 0);
        cuts.push_back(n);

        // vector<vector<int>> dp(m+1 , vector<int>(m+1 , -1));

        // return f(1 , m , cuts , dp);
        vector<vector<int>> dp(m + 2 , vector<int>(m+2 , 0));
        for (int i = m; i >= 1; i--) {
            
            for (int j = i; j <= m; j++) {
                int mini = INT_MAX;

                if(i > j) continue;
                for (int ind = i; ind <= j; ind++) {
                    
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

                    mini = min(mini, ans);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][m];


        
        
    }
};
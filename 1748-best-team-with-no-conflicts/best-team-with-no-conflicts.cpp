class Solution {
public:
    int n;

    int f(int i, int prev, vector<pair<int,int>> &players, vector<vector<int>> &dp) {

        if(i == n)
            return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Skip current player
        int skip = f(i + 1, prev, players, dp);

        // Take current player
        int take = 0;
        if(prev == -1 || players[prev].second <= players[i].second) {//take scores in an inc manner but also we can pick equal scores too 

            take = players[i].second + f(i + 1, i, players, dp);
        }

        return dp[i][prev + 1] = max(skip, take);
    }

    int bestTeamScore(vector<int>& scores,vector<int>& ages) {

        n = scores.size();
        vector<pair<int,int>> players;

        for(int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());  //sort by age bcz now we dont have to wrry about age now 

        // vector<vector<int>> dp(n,vector<int>(n + 1, -1));
        // return f(0, -1, players, dp);

        vector<int> dp(n); //maximum team score ending at player i

        for(int i = 0; i < n; i++)
            dp[i] = players[i].second;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                
                if(players[j].second <= players[i].second) {
                    dp[i] = max(dp[i],dp[j] + players[i].second);
                }
            }
        }

        return *max_element(begin(dp) , end(dp));
    }
};
// [10 , 11 , 12 , 9 , 8 , 7 , 6, 5] in this eg after sorting scores by age , noctice , 10 ,11 , 12 is the inc subseq so we take them not 9,8,7,6,5 bcz its strictly said score of the older one has to be >= score of the younger , hence in our recrusion we take a inc subseq.
class Solution {
public:
    int n;

    int f(int i, int prev,
          vector<pair<int,int>> &players,
          vector<vector<int>> &dp) {

        if(i == n)
            return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Skip current player
        int skip = f(i + 1, prev, players, dp);

        // Take current player
        int take = 0;

        if(prev == -1 ||
           players[prev].second <= players[i].second) {

            take = players[i].second +
                   f(i + 1, i, players, dp);
        }

        return dp[i][prev + 1] = max(skip, take);
    }

    int bestTeamScore(vector<int>& scores,
                      vector<int>& ages) {

        n = scores.size();

        vector<pair<int,int>> players;

        for(int i = 0; i < n; i++)
            players.push_back({ages[i], scores[i]});

        sort(players.begin(), players.end());

        vector<vector<int>> dp(n,
                               vector<int>(n + 1, -1));

        return f(0, -1, players, dp);
    }
};
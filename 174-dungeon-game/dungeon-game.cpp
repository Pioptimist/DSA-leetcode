class Solution {
public:
    // the idea for this ques is , if i am at cell (i , j) and my current health is HP , i need to make sure the path i choose ie right or down , my HP never goes <= 0. now to ensure that I need to know the cumulative negative number in both paths and choose the best out of that.
    // for eg consider [-8,-7,20 , 12] if i step in this path the most negative the health can be -15 , now consider this path [-8 , 20 , -25 , 10] ie if i go in this path i get ht with -8 then 20 then -25 and then 12 , ie the most neg my health can go is -13 , so i choose this path rather than the prev
    // now to make this choice , i need to know HP req in both right and down path
    
    // HP(next) = best(HPr , HPd) so HP(needed at i,j) + dungeon[i,j] >= HP(next) so therefore 
    // HP(needed at i,j or enter i,j) = HP(next) - dungean[i,j]
    // HP needed is to enter this particular room , given HP next , kitna HP chaiye hoga
    // remember HP can never be 0 or less than 0 so HP = max(1 , HP(next) - dungean[i,j])
    int m, n;
    int memo[201][201];
    int solve(int i, int j, vector<vector<int>>& dungeon) {
        
        if (i >= m || j >= n) return 1e9;
        if (i == m - 1 && j == n - 1) {
            // iss room mein ghusne ke liye kitna min HP chaiye
            return max(1, 1 - dungeon[i][j]);  // ya toh 1 or 1 - dung[i][j] bcz if say dung[i][j] = +ve , tb bhi cell ko enter krne ke liye hp should be 1 at least , if -ve then hp enter should be 1 - dungeon[i][j]
        }

        if (memo[i][j] != -1) return memo[i][j];
         // now HP next is min of HP entry for down and right path
        int nextRoomMinHp = min(solve(i + 1, j, dungeon), solve(i, j + 1, dungeon));
        int needed = nextRoomMinHp - dungeon[i][j];

        return memo[i][j] = max(1, needed);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, dungeon);
        
    }
};
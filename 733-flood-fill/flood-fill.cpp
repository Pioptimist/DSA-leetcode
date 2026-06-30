class Solution {
public:
    void dfs(int i, int j, int n, int m,
             vector<vector<int>>& image,
             int originalCol, int color) {

        image[i][j] = color;

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        for (auto d : dir) {
            int newr = i + d[0];
            int newc = j + d[1];

            if (newr >= 0 && newr < n &&
                newc >= 0 && newc < m &&
                image[newr][newc] == originalCol) {

                dfs(newr, newc, n, m, image, originalCol, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int originalCol = image[sr][sc];

        if (originalCol == color)
            return image;

        dfs(sr, sc, n, m, image, originalCol, color);

        return image;
    }
};
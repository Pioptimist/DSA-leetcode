class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k % m;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                int future;
                if(i % 2 == 0){
                    future = (j + k) % m;   // FIXED
                }
                else{
                    future = (j - k + m) % m; // FIXED
                }

                if(mat[i][j] != mat[i][future]) return false;
            }
        }
        return true;
    }
};
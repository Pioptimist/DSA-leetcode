class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int h = (n*m)-1;
        while(l<=h){
            int mid =(l+h)/2;
            int r = mid/m;
            int c = mid%m;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) h = mid-1;
            else l = mid+1;
        }
        return false;


    }
};
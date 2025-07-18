class Solution {
public:
    int maxincol(vector<vector<int>>& mat,int n,int col){
        int maxincol = -1;
        int maxind = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxincol){
                maxincol = mat[i][col];
                maxind = i;
            }
        }
        return maxind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxrowind = maxincol(mat,n,mid);
            int left =mid-1>=0 ? mat[maxrowind][mid-1] : -1;
            int right =mid+1<m ? mat[maxrowind][mid+1] : -1;
            if(mat[maxrowind][mid]>left && mat[maxrowind][mid]>right){
                return {maxrowind,mid};
            }
            else if(mat[maxrowind][mid]<left){
                high = mid-1;
            }
            else{
                low= mid +1;
            }
        }   
        return {-1,-1};
    }
};
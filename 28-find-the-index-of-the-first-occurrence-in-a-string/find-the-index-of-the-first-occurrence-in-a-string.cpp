class Solution {
public:
    int strStr(string h, string nee) {    // we can use kmp too
        int n = h.size();
        int m = nee.size();
        for(int i = 0;i<n;i++){
            int j =0;
            for(j;j<m;j++){
                if(h[i+j]!=nee[j]) break;
                if(h[i+j]==nee[j]) continue;
            }
            if(j==m && h[i+(j-1)==nee[j-1]]){
                return i;
            }
        }
        return -1;
        
    }
};
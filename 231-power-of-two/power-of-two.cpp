class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int x = n-1;
        int t = n & x;
        
        if(t!=0){
            return false;
        }
        else{
            return true;
        }
    }
};
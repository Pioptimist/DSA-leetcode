class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        int M =1e9+7;

        long long result = 1;

        for(int i =2;i<=n;i++){
            long space = 2*(i-1) +1;
            long perm = space* (space+1)/2;

            result = result * perm;
            result %=  M;
        }

        return result ;
        
    }
};
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double probsum = (k==0)? 0 : 1;
        vector<double> P(n+1);   //p[0] toh 1 hoga hi 
        P[0] = 1;
        for(int i =1;i<=n;i++){
            P[i] = probsum/maxPts;
            if(i<k){
                probsum += P[i];
            }
            if(i-maxPts >=0 && i-maxPts<k){
                probsum -= P[i-maxPts];
            }

        }
        double  result = 0;
        for(int i =k;i<=n;i++){
            result += P[i];

        }
        return result;
        
    }
};
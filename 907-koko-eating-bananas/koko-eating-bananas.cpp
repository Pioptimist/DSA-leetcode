class Solution {
public:
    long long reqhours(int mid,vector<int> &piles,int n){
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += (long long)(piles[i] + mid - 1) / mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        // max_element gives iterator to max ele and use *maxele to print
        int n = piles.size();
        int k;
        while(low<=high){
            int mid = (low+high)/2;
            if(reqhours(mid,piles,n)<=h){   
                k=mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
            

        }
        return k;
    }
};
class Solution {
public:
    // xth day mein kitne flowers bloom ho gye and out of those hum kitne bq bna skte
    bool possible(vector<int>& bloomDay,int n,int day,int m,int k){
        int cnt =0;
        int noBoq = 0;

        for(int i = 0;i<n;i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noBoq += cnt/k;
                cnt = 0;
            }
        }
        noBoq += cnt/k;     // if cnt has some value in it , take it

        if(noBoq>=m) return true;

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long low = *min_element(bloomDay.begin(),bloomDay.end());
        long long high = *max_element(bloomDay.begin(),bloomDay.end());

        int n = bloomDay.size();
        int ans = 0;

        if( n < (long long)m*k ) return -1;

        while(low <= high){

            long long mid = (long long)(low+high)/2;

            if(possible(bloomDay,n,mid,m,k)){
              ans=mid;
              high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
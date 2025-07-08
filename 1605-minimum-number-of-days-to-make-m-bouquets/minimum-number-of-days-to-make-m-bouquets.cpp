class Solution {
public:
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
        noBoq += cnt/k;      //bug bcz if  say else never runs in end of arr but cnt>0 noBoq never updates, so make sure of this
        if(noBoq>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low = *min_element(bloomDay.begin(),bloomDay.end());
        long long high = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        int ans = 0;
        if(n<(long long)m*k) return -1;
        while(low<=high){
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
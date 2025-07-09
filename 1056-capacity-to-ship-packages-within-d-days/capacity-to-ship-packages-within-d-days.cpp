class Solution {
public:
    int takendays(vector<int>& weights, int capacity) {
        int tdays = 1;  // At least one day needed
        int currLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currLoad + weights[i] > capacity) {
                tdays++;
                currLoad = 0;
            }
            currLoad += weights[i];
        }
        return tdays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int sum =0;
        for(int i =0;i<n;i++){
            sum += weights[i];
        }
        int high = sum;
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            if(takendays(weights,mid)<=days){
              ans =mid;
              high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
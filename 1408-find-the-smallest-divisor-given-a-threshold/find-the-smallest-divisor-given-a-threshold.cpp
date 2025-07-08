class Solution {
public:
    int sumd(vector<int>& nums,int n, int divisor){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high =  *max_element(nums.begin(),nums.end());
        int ans = -1;
        int n = nums.size();
        if(n>threshold) return -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(sumd(nums,n,mid)<=threshold){
                ans =mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
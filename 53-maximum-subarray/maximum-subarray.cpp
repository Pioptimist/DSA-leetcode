class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long maxi = LONG_MIN;
        long sum=0;
        for(int i = 0; i < n ; i++){
            sum +=nums[i];
            if(sum>maxi){
                maxi = sum;
                
            }
            if(sum < 0){
                sum = 0;
            }   
        
        }
        return maxi;
        
    }
};
//kadane algo says if we keep extending this subarr, is it worth it or not , if the curr subarr sum is -ve obv not worth it kyuki yeh future values ko km krdega , so only keep the curr subarr/ sum var if the sum is  +ve.
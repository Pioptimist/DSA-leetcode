class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum;
        int closum=nums[0] + nums[1] + nums[2];
        for(int i = 0;i<n-2;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                sum = nums[i] + nums[left]+ nums[right];
                if (abs(sum - target) < abs(closum - target)) {
                    closum = sum;
                }
                if(sum<target){
                    left++;
                    while(left<right && nums[left]==nums[left-1]) left++;
                }
                else if(sum>target){
                    right--;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
                else{
                    return sum;
                }
            }
        }
        return closum;
    }
};
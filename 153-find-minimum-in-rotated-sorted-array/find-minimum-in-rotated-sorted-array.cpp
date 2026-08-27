class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){ //whole search space is sorted so low is def the min
                ans = min(ans,nums[low]);
            }
            if(nums[mid]>=nums[low]){ //left half is sorted so take min but unsorted can also have the ans , so low = mid + 1 
                ans = min(ans,nums[low]);
                low = mid +1;
            }
            else if(nums[high]>=nums[mid]){ //right half is sorted so take mid , but check left half too since unsorted can also have the min.
                ans = min(ans,nums[mid]);
                high = mid -1;
            }
        }
        return ans;
    }
};
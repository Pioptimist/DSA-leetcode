class Solution {
public:
// we can apply BS on the correct sorted half , so first we need to find the sorted half and then search in that half
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]==target)  return mid;

            else if(nums[low]<=nums[mid]){  //left half is sorted

                if(target<=nums[mid] && target>=nums[low]){
                    high = mid-1;
                }
                else{
                    low = mid +1;
                }
            }
            else if (nums[mid]<=nums[high]){
                if(target>=nums[mid] && target<=nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
        
    }
};
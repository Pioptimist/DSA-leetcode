class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        while(low<=high){

            int mid = (low+high)/2;

            int missing = arr[mid]-(mid+1);  //num of missing elements at this ind

            if(missing < k){
                low = mid +1;
            }
            // else if(missing == k) return arr[mid]-1; wont work dry run on this [2,3,4,9,10]
            else{
                high = mid -1;
            }
        }
        return high+1+k;

        //the actual formula is nums[high] + more where mre is k - missing numbers at that index so we can say nums[h] + k -(nums[h] - h - 1) [the formula for missing number at index h] , on relaxing we get this high + 1 + k.
        
    }
};
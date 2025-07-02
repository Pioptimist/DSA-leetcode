class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> vec;
        for (int i = 0; i<n-1;i++){
            int first = nums[i];
            for(int j = i+1;j<n;j++){
                if(nums[j]==target-first){
                    vec.push_back(i);
                    vec.push_back(j);
                }
            }
        }
        return vec;

        
    }
};
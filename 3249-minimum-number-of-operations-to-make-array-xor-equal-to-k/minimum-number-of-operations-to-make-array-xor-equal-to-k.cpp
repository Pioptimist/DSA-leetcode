class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int XOR=0;
        int n = nums.size();
        for(int i =0;i<n; i++){
            XOR = XOR^nums[i];
        }
        int finalxor = XOR^k;
        return __builtin_popcount(finalxor);
    }
};
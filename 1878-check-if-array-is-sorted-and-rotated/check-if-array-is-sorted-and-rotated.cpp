class Solution {
public:
//check for every x rotation , if in any of these rotations vec and num are same that means true
    // bool check(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> vec = nums;
    //     sort(vec.begin(),vec.end());
    //     for(int x=0;x<n;x++){
    //         int i=0;
    //         for(i;i<n; i++){
    //            if(vec[i]!=nums[(i+x)%n]) break;
    //            else if(vec[i]==nums[(i+x)%n]) continue;
    //         }
    //         if(i==n) return true;
        
    //     }
    //     return false;
    // }

//soln2 in o(n) time , as notice in an arr which was sorted earlier and only rotated once , there would be just a single drop or break in sorted order
        bool check(vector<int>& nums) {
            int count = 0;
            int n = nums.size();

            for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                count++;
            }

            return count <= 1;
        }
};
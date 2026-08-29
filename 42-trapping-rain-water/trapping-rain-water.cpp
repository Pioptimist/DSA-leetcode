

class Solution {
public:

    int trap(vector<int>& height) {

    int l = 0;
    int r = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int ans = 0;

    while (l <= r) {

        if (height[l] <= height[r]) {

            if (height[l] >= leftMax)
                leftMax = height[l];
            else
                ans += leftMax - height[l];

            l++;
        }

        else {

            if (height[r] >= rightMax)
                rightMax = height[r];
            else
                ans += rightMax - height[r];

            r--;
        }
    }

    return ans;
    }
//think maxleft and maxright for each building at i but also we calc unit of water stored on top of building by this formula min(leftM, rightM) - height[i] where a building ht can be 0 too.
    // int trap(vector<int>& height) {
    //     int n  = height.size();
    //     vector<int> pref(n); //max ht in pref
    //     vector<int> suff(n); //max ht in suffix
    //     int total = 0;
    //     pref[0] = height[0];
    //     for(int i =1;i<n;i++){
    //         pref[i] = max(pref[i-1],height[i]);
    //     }
    //     suff[n-1] = height[n-1];
    //     for(int i =n-2;i>=0;i--){
    //         suff[i] = max(suff[i+1],height[i]);
    //     }
    //     for(int i =0;i<n;i++){
    //         int leftM = pref[i];
    //         int rightM = suff[i];
    //         if(height[i] < leftM && height[i]< rightM){ //consider only when curr building is smaller than leftmax and rightmax
    //             total = total + min(leftM, rightM) - height[i];
    //         }
    //     }
    //     return total;
    // }
};

//the below code  is done using nge and pge where our monotonic stack contains indices of hts of buildings in a dec order , here we calc width and ht both to find the amt of water held above the building.
// int trap(vector<int>& height) {
//     int n = height.size();
//     stack<int> st; // Stores indices in decreasing order of heights
//     int totalWater = 0;

//     for (int i = 0; i < n; i++) {
//         // While current bar is taller than the stack top, it acts as NGE (Right Wall)
//         while (!st.empty() && height[i] > height[st.top()]) {
//             int mid = st.top(); // Pit bottom
//             st.pop();

//             // If no left boundary exists, water cannot be trapped
//             if (st.empty()) break;

//             int left = st.top(); // PGE for this curr ele
//             int right = i;       // this curr ele is the nge for the popped ele

//             int boundedHeight = min(height[left], height[right]) - height[mid];
//             int width = right - left - 1;

//             totalWater += boundedHeight * width;
//         }
//         st.push(i);
//     }

//     return totalWater;
// }
// class Solution {
// public:
// // do lc 907 first
//     vector<int> findNSE(vector<int>& arr){
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for(int i = n-1;i>=0;i--){
//             while(!st.empty() && arr[st.top()]>arr[i]){    //here in st.top()>= we removed the equals to bcz then nse gives next smaller or equal to element to resolve the duplicate elements in arr edge case
//                 st.pop();
//             }
//             nse[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return nse;
//     }

//     vector<int> findPSE(vector<int>& arr){
//         int n = arr.size();
//         vector<int> pse(n);
//         stack<int> st;
//         for(int i = 0;i<n;i++){
//             while(!st.empty() && arr[st.top()]>=arr[i]){
//                 st.pop();
//             }
//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return pse;
//     }

//     vector<int> findNGE(const vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nge(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; --i) {
//             // pop strictly smaller elements, so equal stays (we want next >=)
//             while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
//             nge[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }
//         return nge;
//     }

//     vector<int> findPGE(const vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pge(n);
//         stack<int> st;
//         for (int i = 0; i < n; ++i) {
//             while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();

//             pge[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return pge;
//     }
//     long long subArrayRanges(vector<int>& arr) {
//         vector<int> nse = findNSE(arr);
//         vector<int> pse = findPSE(arr);
//         vector<int> nge = findNGE(arr);
//         vector<int> pge = findPGE(arr);
//         int n = arr.size();
//         long long totalmin = 0;
//         long long totalmax = 0;
//         // curr ele kitne subarrays mein largest hai
//         for (int i = 0; i < n; ++i) {
//             long long left = i - pse[i];         
//             long long right = nse[i] - i;        
//             long long contrib = (left * right);
//             contrib = (contrib * (long long)arr[i]);
//             totalmin = (totalmin + contrib);
//         }
//         // curr ele kitne subarrays mein smallest hai
//         for (int i = 0; i < n; ++i) {
//             long long left = i - pge[i];         
//             long long right = nge[i] - i;        
//             long long contrib = (left * right);
//             contrib = (contrib * (long long)arr[i]);
//             totalmax = (totalmax + contrib);
//         }

//         return totalmax-totalmin;   
//     }
// };

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long totalmax = 0, totalmin = 0;
        
        stack<int> stMin, stMax;

        for (int i = 0; i <= n; ++i) {
            // Process minimums (monotonically increasing stack)
            while (!stMin.empty() && (i == n || nums[stMin.top()] >= nums[i])) {
                int mid = stMin.top();
                stMin.pop();
                int pse = stMin.empty() ? -1 : stMin.top();
                int nse = i;
                totalmin += (long long)nums[mid] * (mid - pse) * (nse - mid);
            }
            stMin.push(i);

            // Process maximums (monotonically decreasing stack)
            while (!stMax.empty() && (i == n || nums[stMax.top()] <= nums[i])) {
                int mid = stMax.top();
                stMax.pop();
                int pge = stMax.empty() ? -1 : stMax.top();
                int nge = i;
                totalmax += (long long)nums[mid] * (mid - pge) * (nge - mid);
            }
            stMax.push(i);
        }

        return totalmax - totalmin;
    }
};
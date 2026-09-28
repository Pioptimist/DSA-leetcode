// class Solution {
// public:
//     const int MOD = 1e9 + 7;
//     vector<int> findNSE(vector<int>& arr){
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for(int i = n-1;i>=0;i--){
//             while(!st.empty() && arr[st.top()]>arr[i]){    //here we removed st.top()>= the equal to bcz then nse gives next smaller or equal to element to resolve the duplicate elements in arr edge case
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
//             while(!st.empty() && arr[st.top()]>=arr[i]){  //notice the equal to which mean prev smaller or equal to , we do that bcz consider [1,1] at 0th index we consider subarr [1] , [1,1] and when we are at 1st index we consider [1] and [1,1] again if we didnt had this = here. so this equals to prevent from recounting same subarr with same min element.
//                 st.pop();
//             }
//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }
//         return pse;
//     }
//     //idea is we check in how many subarray the curr ith element can be the min in those , and then we count the contribution of that element and add in total.
//     int sumSubarrayMins(vector<int>& arr) {
//         vector<int> nse = findNSE(arr);
//         vector<int> pse = findPSE(arr);
//         int n = arr.size();
//         long long total = 0;
//         for (int i = 0; i < n; ++i) {
//             long long left = i - pse[i];         
//             long long right = nse[i] - i;        
//             long long contrib = (left * right) % MOD;
//             contrib = (contrib * (long long)arr[i]) % MOD;
//             total = (total + contrib) % MOD;
//         }
//         return (int) total;
        
//     }
// };


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        long long total = 0;

        // Loop runs to n bcz say after loop runs till n - 1 , sm ele remains in stak , then we can say those doesnt have a nse ie nse for those is n , hence we go to n and flush those ele
        for (int i = 0; i <= n; ++i) {
            
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                int nse = i;

                long long left = mid - pse;
                long long right = nse - mid;

                long long contrib = (left * right) % MOD;
                contrib = (contrib * arr[mid]) % MOD;
                total = (total + contrib) % MOD;
            }
            st.push(i);
        }

        return (int)total;
    }
};
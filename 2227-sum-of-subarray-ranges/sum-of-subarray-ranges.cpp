class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){    //here we removed st.top()>= the equal to bcz then nse gives next smaller or equal to element to resolve the duplicate elements in arr edge case
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNGE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            // pop strictly smaller elements, so equal stays (we want next >=)
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGE(arr);
        int n = arr.size();
        long long totalmin = 0;
        long long totalmax = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - pse[i];         
            long long right = nse[i] - i;        
            long long contrib = (left * right);
            contrib = (contrib * (long long)arr[i]);
            totalmin = (totalmin + contrib);
        }

        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];         
            long long right = nge[i] - i;        
            long long contrib = (left * right);
            contrib = (contrib * (long long)arr[i]);
            totalmax = (totalmax + contrib);
        }

        return totalmax-totalmin;   
    }
};
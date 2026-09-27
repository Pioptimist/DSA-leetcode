class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> NGE;
        stack<int> st;

        for(int i =n-1;i>=0;i--){ //start from right

            while(!st.empty() && nums2[i] > st.top()){ //keep going till we find the number greated than num[i]
                st.pop();
            }
            if(st.empty()) NGE[nums2[i]]=-1; // no nge found
            
            else{
                NGE[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x : nums1){
            ans.push_back(NGE[x]);
        }
        return ans;

    }
};
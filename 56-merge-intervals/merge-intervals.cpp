class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int k = 0;
        for(int i =0; i<n; i++){
            if(ans.empty() || intervals[i][0]>ans[k][1]){
                ans.push_back(intervals[i]);
                if(i>0){
                    k++;
                }
            }
            else if(ans[k][1]>=intervals[i][0]){
                ans[k][1]= max(ans[k][1], intervals[i][1]);
            }
        }
        return ans;
        
    }
};
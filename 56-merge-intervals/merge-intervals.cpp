class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n = intervals.size();
        vector<vector<int>> mergeInt;
        if(n==0) return mergeInt;
        vector<int> tempInt = intervals[0];
        for(auto it : intervals){
            if(it[0] <= tempInt[1]){
                tempInt[1] = max(it[1] , tempInt[1]);
            }
            else{
                mergeInt.push_back(tempInt);
                tempInt = it;
            }
        }
        mergeInt.push_back(tempInt);
        return mergeInt;
        
    }
};
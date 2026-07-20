class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n = intervals.size();
        vector<vector<int>> mergeInt;
        if(n==0) return mergeInt;
        vector<int> tempInt = intervals[0];
        for(auto it : intervals){
            if(mergeInt.size() ==0 || mergeInt.back()[1] < it[0]){
                //start a new interval
                mergeInt.push_back(it);
            }
            else{
                mergeInt.back()[1] = max(mergeInt.back()[1] , it[1]); //update the interval if the curr interval start lies inside the last interval's end and then update the end.
            }
        }
        // mergeInt.push_back(tempInt);
        return mergeInt;
        
    }
};
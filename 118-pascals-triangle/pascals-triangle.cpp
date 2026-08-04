class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        long long ans = 1;
        vector<vector<int>> ansr; //final ans
        vector<int> genrow; //generate rows 
        for(int row = 1;row<=numRows;row++){
            ans = 1;
            genrow.clear();
            genrow.push_back(1);
            for(int col = 1; col<=row-1;col++){
                ans = ans*(row-col);
                ans = ans/col;
                genrow.push_back(ans);
            }
            ansr.push_back(genrow);
        }
        return ansr;
        
    }
};
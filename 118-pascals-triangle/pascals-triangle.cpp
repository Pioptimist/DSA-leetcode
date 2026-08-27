class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        long long ans = 1;
        int n = numRows;

        vector<vector<int>> ansr;

        vector<int> genrows;
        for(int r = 1 ; r <= n ; r++){
            ans = 1;
            genrows.clear();

            genrows.push_back(ans);  // push the first 1;

            for(int c = 1 ; c < r ; c++){   //start from 2nd col upto the last

                ans = ans * (r - c);    // the elements formula
                ans = ans/c; 
                genrows.push_back(ans);
            }
            ansr.push_back(genrows);

        }
        return ansr;
        
    }
};

//or we can build it from prev rows as given in the animation
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> ans;

//         for(int i = 0; i < numRows; i++) {

//             vector<int> row(i + 1, 1); //create current row , now first and last element is 1 , we need to change the middle 1s to their correct val.

//             for(int j = 1; j < i; j++) {
//                 row[j] = ans[i-1][j-1] + ans[i-1][j]; //pichle row ke do index ka sum
//             }

//             ans.push_back(row);
//         }

//         return ans;
//     }
// };
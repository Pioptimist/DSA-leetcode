class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int c = (n/rows);
        string ans;
        vector<vector<char>> grid(rows , vector<char>(c, '$'));
        
        for(int i = 0 ; i< rows ; i++){
            for(int j = 0 ; j < c ; j++){
                grid[i][j] = encodedText[i*c + j];
            }
        }
        for(int cols = 0 ; cols < c ; cols++){
            int r = 0;
            int j = cols;
            while(r < rows && j < c){
                ans.push_back(grid[r][j]);
                r++;
                j++;

            }

        }

        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
        
    }
};
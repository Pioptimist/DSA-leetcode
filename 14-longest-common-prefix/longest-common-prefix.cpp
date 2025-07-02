class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        vector<char> vec;
        vector<char> ans;
        for(int i=0;i<strs[0].length();i++){
            vec.push_back(strs[0][i]);

        }
        for(int i = 0;i<vec.size();i++){
            int j =1;
            for(j=1; j<n;j++){
                if(vec[i]==strs[j][i]){
                    continue;
                }
                else if(i >= strs[j].length() || (vec[i]!=strs[j][i])){
                    return string(ans.begin(),ans.end());

                }

            }
            if (j==n){
                ans.push_back(vec[i]);
            }

        }
        return string(ans.begin(),ans.end());
        
    }
};
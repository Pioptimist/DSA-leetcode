
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int result = 0;
        for(int i =0;i<n;i++){
            vector<int> freq(26,0);

            for(int j =i;j<n;j++){
                freq[s[j]-'a']++;
                int maxele = 0;
                int minele = 1e5;
                for(int k =0;k<26;k++){
                    if(freq[k]>0){
                        maxele =  max(maxele,freq[k]);
                        minele = min(minele,freq[k]);
                    }
                }
                result += maxele - minele;
            }
        }
        return result;
    }
};
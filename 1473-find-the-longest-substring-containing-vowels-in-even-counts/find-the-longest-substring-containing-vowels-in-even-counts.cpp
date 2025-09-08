class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string,int> mpp;   //currstate in string and int
        int result = 0;
        string currstate = "00000";
        mpp[currstate] = -1;

        vector<int> vowl(5);  //a,e,i,o,u
        for(int i =0;i<s.size();i++){
            if(s[i] == 'a'){
                vowl[0] = (vowl[0] +1) %2;
            }
            else if(s[i] == 'e'){
                vowl[1] = (vowl[1] +1) %2;
            }
            else if(s[i] == 'i'){
                vowl[2] = (vowl[2] +1) %2;
            }
            else if(s[i] == 'o'){
                vowl[3] = (vowl[3] +1) %2;
            }
            else if(s[i] == 'u'){
                vowl[4] = (vowl[4] +1) %2;
            }

            currstate = "";
            for(int j =0;j<5;j++){
                currstate = currstate + to_string(vowl[j]);
            }

            if(mpp.find(currstate)!=mpp.end()){
                result = max(result, i-mpp[currstate]);
            }
            else{
                mpp[currstate] = i;
            }
        }
        return result;


    }
};
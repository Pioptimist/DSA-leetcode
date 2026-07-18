class Solution {
public:
//kya hum worddict ke words ko use krke s bna skte hai ya nhi , not necessarily using every word and any word can be repeated any amt of time , so seems like a simple recursion
    int n;
    int m;
    vector<int> dp;
    bool f(int i ,string &s ,  vector<string>& wordDict){
       if(i >= n) return true;  //saare substr match kr gye tabhi bahar aa gye
        
       if(dp[i] != -1) return dp[i];
       for(string word : wordDict){
          if(s.substr(i , word.size()) == word){ //match , now check ahead

            if(f(i + word.size() , s , wordDict)) return dp[i] = true;
          }
       }
       
       return dp[i] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        m = wordDict.size();
        dp.assign(n , -1);
        return f(0 , s , wordDict);
        
    }
};

//approach : try going thru every word in wordDict if any word matches ,call next recursion to check if s can be formed or nah

//will give tle in cases like s = "aaaa" dict = ["a","aa"] , draw tree diagram we will see same recursion call from different states = > memoise


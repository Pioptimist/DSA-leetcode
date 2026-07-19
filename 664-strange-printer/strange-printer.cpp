class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int f(int l, int r, string& s){
        if(l == r)
            return 1; //single char ko print krne ka tareeka is only 1
        
        else if(l > r)
            return 0; //no way to print as empty string now
        
        if(dp[l][r] != -1)
            return dp[l][r];


        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;  //jb tk i matches char at l , keep going forward

        if(i == r+1)
            return 1; //mtlb hr ek char same hai lth char ke , toh we can print them in 1 go.

        int normal = 1 + f(i,r,s); //mtlb agr abcaa hai toh usko a|b|c|aa aise krke ans

        int aage_ka = INT_MAX;  //to overwrite print

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = f(i,j-1,s) + f(j,r,s); //here we dont do 1 + .... bcz say we have abcaa , and i is at 1 , j is at 3, now from l to j ie 0 to 3, we can print in one go ie aaa so we might think we should 1 + f(1,2) + f(2,r) but notice carefully agr hum yaha +1 kr dete toh f(2 ,r) mein issi same a ko cnt krke answer aata ie we would have overcounted this aaaa. pehla toh +1 yaha add kiya for aaaa and then we send f(2,r) ie it starts from this last 'a' in aaaa and recounts printing this last a , which is wrong kyuki yeh wala a toh issi aaaa ke sath print ho chuka tha
                
                aage_ka = min(aage_ka, x);
            }
        }

        return dp[l][r] = min(aage_ka, normal);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        
        dp.resize(n,vector<int>(n+1, -1));
        
        return f(0, n-1, s);
    }
};

//try dry running cases like aba , abcaa , abaca
class Solution {
public:
    string longestPalindrome(string s) {
        // using the logic to check palindrome from the middle and if left of middle is righto f middle then its a palindrome, eg - aba and for even aabbaa here middle will be two chars and in odd just single and keeps on checking if left ==right or not if yes then inc left and right point and check again

        string result = "";
        int reslen = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            int r=i,l = i;
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1 > reslen){
                    result = s.substr(l,r-l+1);
                    reslen = r-l+1;
                }
                l--;
                r++; 
            }      
            r=i+1;
            l =i;
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if(r-l+1 > reslen){
                    result = s.substr(l,r-l+1);
                    reslen = r-l+1;
                }
                l--;
                r++;
            }
            
            
            
        }
        return result;
    }
};
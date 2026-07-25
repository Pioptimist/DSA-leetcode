class Solution {
public:
//think sliding window
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 1) return 1;

        vector<int> hash(256 , 0);
        int maxi = 0;

        int l= 0 , r = 0;
        while (r < s.size()) {
            // 1. Add the new character to our window
            hash[s[r]]++;
    
            // 2. If it caused a duplicate, shrink from the left until it's fixed
            while (hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }
    
            // 3. The window is definitely valid here, so update maxi
            maxi = max(maxi, r - l + 1);
    
            // 4. Move right pointer ahead
            r++;
        }

        return maxi;
        
    }
};
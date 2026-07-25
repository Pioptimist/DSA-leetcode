class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(128, 0); 
        for (char ch : t) {
            hash[ch]++;
        }
        
        int required_count = t.size();
        int l = 0, r = 0;
        
        int mini = INT_MAX;
        int si = -1; //starting inx of valid window
        
        while (r < s.size()) {
            if (hash[s[r]] > 0) {
                required_count--;
            }
            // Decrement the character in hash (unneeded chars become negative)
            hash[s[r]]--; 
            
            // jo bhi char chaiye the , woh mil gye iss window ke andr
            while (required_count == 0) {
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    si = l;
                }
               
                hash[s[l]]++; // Add the character back to our hash
                
    
                if (hash[s[l]] > 0) { //means we added a needed char back into our hash , so obv we need it in future 

                    required_count++; //will break the while loop
                }
                l++;  //shrink window
            }
            
            r++; 
        }
        
        return mini == INT_MAX ? "" : s.substr(si, mini);
    }
};
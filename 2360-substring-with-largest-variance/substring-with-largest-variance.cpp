class Solution {
public:

//just like kadane algo , we dont neeed to trav each substr , we trav once and we decide is cont this particular substr worth it or not , we somewhat thinks the same here , imagine every major ele is  +1 and minor is -1 , so we ask to ourselve how can we get the higher sum in the curr substr , either by discont it bcz it becomes negative and harm the future sum or we cont it.
//concept of major ele and minor is imp bcz we are told the diff between any 2 char present in s so by default for their diff to be max , one has to occur more than the other so major and minor

//for a valid variance we def need a major and minor ele so like bbbb has 0 var bcz no minor present in this. now consider abbbb, and assume we took  major as b and minor a , now we see a and reset cnt , now there is no minor ahead and bbbb cant have a vaild var , so its very imp ki agr hum cnter reset kr rhe ho toh atleast future mein ek minor toh ho jiise hum ek valid string with var bna skte hai
    int largestVariance(string s) {

        int ans = 0;
        int freq[26] = {};
        for(char c : s) freq[c-'a']++;

        for(char major = 'a'; major <= 'z'; major++) {
            if(freq[major - 'a'] == 0) continue;

            for(char minor = 'a'; minor <= 'z'; minor++) {

                if(major == minor || freq[minor - 'a'] == 0) continue;

                int majorCount = 0;
                int minorCount = 0;

                // Count how many minor characters are left ahead
                int remainingMinor = 0;
                for(char c : s)
                    if(c == minor) remainingMinor++;

                for(char c : s) {
                    // Ignore other characters
                    if(c != major && c != minor) continue;

                    if(c == major) {
                        majorCount++;
                    }
                    else {
                        minorCount++;
                        remainingMinor--;
                    }

                    // Valid substring must contain at least one minor
                    if(minorCount > 0)
                        ans = max(ans, majorCount - minorCount);

                    // Kadane reset
                    if(majorCount < minorCount && remainingMinor > 0) {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }

        return ans;
    }
};


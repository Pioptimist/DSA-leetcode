class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> orig(n);

        // lets try with orig[0] = 0
        orig[0] = 0;
        for(int i =0;i<n-1;i++){
            orig[i+1] = orig[i]^derived[i];

        }
        if(orig[0] ^ orig[n-1]== derived[n-1]){
            return true;
        }

        // lets try with orig[0] = 1
        orig[0] = 1;
        for(int i =0;i<n-1;i++){
            orig[i+1] = orig[i]^derived[i];

        }
        if(orig[0] ^ orig[n-1]== derived[n-1]){
            return true;
        }
        return false; //when neither is true
        
    }
};
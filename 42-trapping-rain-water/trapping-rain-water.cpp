class Solution {
public:
    int trap(vector<int>& height) {
        int n  = height.size();
        vector<int> pref(n);
        vector<int> suff(n);
        int total = 0;
        pref[0] = height[0];
        for(int i =1;i<n;i++){
            pref[i] = max(pref[i-1],height[i]);
        }
        suff[n-1] = height[n-1];
        for(int i =n-2;i>=0;i--){
            suff[i] = max(suff[i+1],height[i]);
        }
        for(int i =0;i<n;i++){
            int leftM = pref[i];
            int rightM = suff[i];
            if(height[i] < leftM && height[i]< rightM){
                total = total + min(leftM, rightM) - height[i];
            }
        }
        return total;
    }
};
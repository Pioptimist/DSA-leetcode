class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1= INT_MIN;
        int ele2= INT_MIN;
        int n = nums.size();
        vector<int> ans;
        int cnt1=0;
        int cnt2=0;
        for(int i=0; i<n;i++){
            if(ele2!=nums[i] && cnt1==0){
                cnt1=1;
                ele1= nums[i];
            }
            else if(ele1!=nums[i] && cnt2==0){
                cnt2=1;
                ele2= nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }
        int realcnt1 =0;
        int realcnt2 =0;
        for(int i=0; i<n;i++){
            if(nums[i]==ele1) realcnt1++;
            if(nums[i]==ele2) realcnt2++;
        }
        if(realcnt1>(n/3)) ans.push_back(ele1);
        if(realcnt2>(n/3)) ans.push_back(ele2);

        return ans;
    }
};

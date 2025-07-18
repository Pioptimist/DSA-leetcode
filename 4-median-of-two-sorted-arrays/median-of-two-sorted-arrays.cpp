class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low = 0, high =n1;
        
        int lefthalf = (n1+n2+1)/2;
        int n = (n1+n2);
        while(low<=high){
           int l1 = INT_MIN, l2 = INT_MIN;
           int r1 = INT_MAX , r2 = INT_MAX;
           int m1 = (low+high)/2;
           int m2 = lefthalf - m1;
           if(m1<n1) r1 = nums1[m1];
           if(m2<n2) r2 = nums2[m2];
           if(m1-1>=0) l1 = nums1[m1-1];
           if(m2-1>=0) l2 = nums2[m2-1];
           if(l1<=r2 && l2<=r1){
            if(n%2==1) return (double)max(l1,l2);
            return (double)(max(l1,l2)+min(r1,r2))/2;
           }
           else if(l1>r2){
            high=m1-1;
           }
           else{
            low = m1 +1;
           }
        }
        return 0;
    }
};
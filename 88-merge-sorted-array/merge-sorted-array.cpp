class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n+m;
        int gap = (len/2) + 1;

        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right<len){
                if(left<m && right< m){
                    if(nums1[left]> nums1[right]){
                        swap(nums1[left],nums1[right]);
                    
                    }
                    left ++;
                    right++;
                }

                else if(left < m && right >= m){
                    if(nums1[left]> nums2[right-m]){
                        swap(nums1[left],nums2[right-m]);
                    
                    }
                    left ++;
                    right ++;

                }

                else {
                    if(nums2[left-m]> nums2[right-m]){
                        swap(nums2[left-m],nums2[right-m]);
                    
                    }
                    left ++;
                    right ++;
                
                }
                

            }
            if(gap ==1) break;
            gap = (gap+1)/2 ;

        }
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        
        
    }
};
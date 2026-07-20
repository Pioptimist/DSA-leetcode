class Solution {
public:
    void merge(vector<int> &arr,int low ,int high,int mid){
        int cnt = 0;
        int left = low;
        int right = mid +1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(arr[left]>=arr[right]){
                temp.push_back(arr[right]);
                right++;

            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low; i < high+1;i++){
            arr[i] = temp[i-low];    //get temp elements back to arr after merging
        }
    }
    int cntpairs(vector<int> &arr, int low , int high, int mid){
        int cnt = 0;
        int right = mid +1;
        for (int i = low; i<=mid;i++){
            while(right<=high && (long long)arr[i]  >2LL*arr[right] ) right++;
            cnt = cnt + (right - (mid+1) );
        }
        return cnt;
    }

    int mergesort(vector<int> &arr, int low, int high){
        int cnt = 0;
        if(low==high) return cnt;
        int mid = (low + high)/2;
        cnt+=mergesort(arr,low,mid);
        cnt+=mergesort(arr, mid +1,high);
        cnt +=cntpairs(arr,low,high,mid);
        merge(arr, low , high, mid);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        cnt = mergesort(nums,0,n-1);
        return cnt;
        
    }
};

//one might think why dont we do this like we did cnt inversion ques and just change that equation to 2*a[right] , its bcz if we do that we will be missing comparing valid elements and not sort them for eg , in this ques 6 !> 2*3 so we skip 6 but 6 > 3 so upon skiping 6 , we wont be sorting 6 and fuck up sort nature of the arrays , that's why we follow this manner of cnting the valid pairs in this question.
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
        for(int i=low; i<high+1;i++){
            arr[i] = temp[i-low];
        }
    }
    int cntpairs(vector<int> &arr, int low , int high, int mid){
        int cnt = 0;
        int right = mid +1;
        for (int i = low; i<=mid;i++){
            while(right<=high && (long long)arr[i]>2LL*arr[right]) right++;
            cnt = cnt + (right-(mid+1));
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
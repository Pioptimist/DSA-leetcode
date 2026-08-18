class NumArray {
public:
    int n;
    vector<int> segT;

    void fBT(int i , int l , int r , vector<int> &nums){
        if(l == r){
            segT[i] = nums[r];
            return;
        }
        int mid = l + (r-l)/2;
        fBT(2*i+1 , l , mid , nums);
        fBT(2*i+2 , mid + 1 , r , nums);
        segT[i] = segT[2*i+1] + segT[2*i+2];
    }

    void fupd(int idx , int i , int val , int l ,int r){ //idx is index on nums and i on segT
        if(l == r) {
            segT[i] = val;  //update the node
            return ;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            fupd(idx , 2*i+1 , val , l , mid);
        }
        else{
            fupd(idx , 2*i + 2 , val , mid + 1 , r);
        }

        segT[i] = segT[2*i+1] + segT[2*i+2];

    }

    int query(int start , int end , int l , int r , int i){
        if( l > end || r < start){
            return 0;
        }

        if(l >=start && r<=end){
            return segT[i];
        }

        int mid = l + (r-l)/2;
        return query(start , end , l , mid , 2*i+1)   //go to left subtree
               + query(start , end , mid+1 , r , 2*i+2);  //go to right subtree

    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segT.resize(4*n);
        fBT(0 , 0 , n-1 , nums); //build the segment tree
        
    }
    
    void update(int index, int val) {
        fupd(index , 0 , val , 0 , n-1); //point update in segT
        
    }
    
    int sumRange(int left, int right) {
        return query(left ,right , 0 , n-1 , 0); // query for adding up elements from left to right
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
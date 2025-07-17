class Solution {
public:
    bool ispossible(vector<int> &position,int m,int assummedmindist,int n){
        int cntballs =1;
        int lastball = position[0];  // placing the first ball at 0th basket
        int maxel = *max_element(position.begin(),position.end());
        int minel = *min_element(position.begin(),position.end());
        for(int i =1;i<=n-1;i++){
            if(position[i]-lastball>=assummedmindist){
                cntballs++;
                lastball = position[i];
            }
        }
        return cntballs >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int maxel = *max_element(position.begin(),position.end());
        int minel = *min_element(position.begin(),position.end());
        int high = maxel - minel;
        while(low<=high){
            int mid = (low+high)/2;
            if(ispossible(position,m,mid,n)==false){
                high = mid-1;
            }
            else{
                low = mid +1;
            }

        }
        return high;
        
    }
};
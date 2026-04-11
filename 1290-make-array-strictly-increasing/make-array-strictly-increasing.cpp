class Solution {
public:
    map<pair<int,int>, int> dp;
    int f(int i , vector<int> &arr1 , vector<int> &arr2 , int prev , int n , int m){
        if(i >= n) return 0;

        if(dp.count({i, prev})) return dp[{i, prev}];

        int res1 = 1e9 + 1;
        if(arr1[i] > prev){
            res1 = f(i+1 , arr1 , arr2 , arr1[i], n , m);
        }
        
        int res2  = 1e9 + 1;
        auto it = upper_bound(begin(arr2), end(arr2) , prev);
        if(it != arr2.end()){
            int j = it - begin(arr2);
            // arr1[i] = arr2[j];
            res2 = 1 + f(i+1 , arr1 , arr2 , arr2[j] , n , m);
        }

        return dp[{i, prev}] = min(res1 , res2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        sort(begin(arr2), end(arr2));
        int res = f(0 , arr1 , arr2 , INT_MIN , n , m);
        if(res == 1e9 + 1){
            return -1;
        }
        return res;
        
    }
};
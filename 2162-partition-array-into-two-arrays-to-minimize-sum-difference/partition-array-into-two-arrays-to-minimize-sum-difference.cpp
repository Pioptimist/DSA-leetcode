class Solution {
public:
//a subset is like a subseq but order doesnt matter
    void generate(vector<int>& arr, int idx, int count, int sum, vector<vector<int>>& store) {
        if(idx == arr.size()) {
            store[count].push_back(sum);
            return;
        }

        // take
        generate(arr, idx + 1, count + 1, sum + arr[idx], store);

        // not take
        generate(arr, idx + 1, count, sum, store);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        vector<int> leftArr(nums.begin(), nums.begin() + half);
        vector<int> rightArr(nums.begin() + half, nums.end());
        vector<vector<int>> left(half + 1), right(half + 1);    //subarr sum ko store

        // generate all subset sums
        generate(leftArr, 0, 0, 0, left);
        generate(rightArr, 0, 0, 0, right);

        //meet in middle algo
        for(int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int total = 0;
        for(int x : nums) total += x;

        int ans = INT_MAX;

        // now we try to form subset 1 and make it sum as close to total/2 as possible , so now we try to pick from left half and the rest from right half and then we add to get sum of subset 1 and then store the diff of (total - 2s1) and return the min out of it

        for(int k = 0; k <= half; k++) { //start picking from left
            for(int x : left[k]) { //say we pick only 1 ele , then we use the possible sum left can give when we only pick 1 element

                int need = total/2 - x; //we need this from right
                auto &vec = right[half - k]; //we pick the rest from right

                auto it = lower_bound(vec.begin(), vec.end(), need);
                
                //now lb gives first ele>=need , so it points to that
                if(it != vec.end()) {   
                    int s = x + *it;
                    ans = min(ans, abs(total - 2*s));
                }
                
                //we dont just want ele>=need , chances are that the pointed ele might not be closest to need, so we check the prev element , for eg we need= 32 in [10, 25, 40, 50]  so lb points to 40 , but we check 25 too
                
                if(it != vec.begin()) {
                    --it;
                    int s = x + *it;
                    ans = min(ans, abs(total - 2*s));
                }
            }
        }

        return ans;
    }
};
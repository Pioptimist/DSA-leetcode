class Solution {
public:
//another lis variant where we take each pair as a part of the inc subseq.
    int maxEnvelopes(vector<vector<int>>& env) {
    
        // sort(env.begin(), env.end());

        // int n = env.size();
        // vector<int> dp(n,1);
        // int ans = 1;
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<i;prev++){

        //         if(env[prev][0] < env[i][0] &&
        //            env[prev][1] < env[i][1]){

        //             dp[i]=max(dp[i],dp[prev]+1);
        //         }
        //     }
        //     ans=max(ans,dp[i]);
        // }

        // return ans;
        //gives tle since o(n2)

//whenever we find thatr quess is asking for lis , think binary search method

//now to use binary search we can do them on pairs , we need to do them on sigle int elements , thats why we think of sorting but when width is same , then for those pair we sort them y ht but in descending order , desc order bcz if say 6,5 and 6,7 , lis on ht would take 6,5 first but width of 6 cant fit in width of 6 , it needds > 6 . thats why the desc order bcz now it makes sure in our lis we do not take any two element with same width

        sort(env.begin(),env.end(),[](auto &a, auto &b){

            if(a[0]==b[0])
                return a[1]>b[1];

            return a[0]<b[0];

        });

        vector<int> temp;
        temp.push_back(env[0][1]);
        int len = 1;

        for(auto x : env){
            int ht = x[1];

            if(ht > temp.back()){
                temp.push_back(ht);
                len++;
            }
            else{
                int i = lower_bound(begin(temp) , end(temp) , ht) - begin(temp);
                temp[i] = ht;
            }
        }

        return len;
    }
};
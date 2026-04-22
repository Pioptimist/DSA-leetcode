class Solution {
public:
    int lastpt;
    map<pair<int , int> , int> mp;
    int f(vector<pair<int , int>> &cord , int i , int maxE){
        if(i >= cord.size()){
            if(maxE >= lastpt){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(cord[i].first > maxE){
            return 1e9;
        }

        if(mp.find({i , maxE}) != mp.end()) return mp[{i,maxE}];
        int notT = f(cord , i +1 , maxE);
        int take = 1 + f(cord , i + 1 , max(maxE , cord[i].second));

        return mp[{i,maxE}] = min(notT , take);
    }
    int minTaps(int n, vector<int>& ranges) {
        lastpt = n;
        vector<pair<int , int>> cord;
        for(int i = 0 ; i < n+1 ; i++){
            int a = max(0 , i - ranges[i]);
            int b = min(n , i + ranges[i]);

            cord.push_back({a,b});
        }

        sort(begin(cord) , end(cord));
        
        int res =  f(cord , 0 , 0);

        return res==1e9 ? -1 : res;
        
    }
};
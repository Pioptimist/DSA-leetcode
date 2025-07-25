class Solution {
public:
    string frequencySort(string s) {
        // we are using  priority queue for storing the char with their freq so that that we can gain the char with most freq without traversing by pq.toop  remember if a pair is given in pq sorting is done on first element
        string result = "";
        int n =s.size();
        unordered_map<char,int> mpp;
        for(int i =0;i<n;i++){
            mpp[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto ele : mpp){
            pq.push({ele.second,ele.first});     // for pq we use push() not insert
        }

        while(!pq.empty()){
            auto [freq,alp] = pq.top();
            pq.pop();
            result += string(freq,alp);
        }
        return result;
    }
};
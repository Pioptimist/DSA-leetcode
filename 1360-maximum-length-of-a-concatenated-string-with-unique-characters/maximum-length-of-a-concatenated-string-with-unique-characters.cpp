class Solution {
public:

    bool check(string &newstr){
        vector<int> freq(26,0);
        for(int i = 0 ; i < newstr.size() ; i++){
            freq[newstr[i] - 'a']++;
            if(freq[newstr[i] - 'a'] > 1) return false;
        }
        return true;
    }
    int f(vector<string>& arr , string &temp , int i){
        if( i == arr.size()){
            return temp.size();
        }
        
        int take = INT_MIN;
        string newstr = temp + arr[i];
        if(check(newstr)){
            take = f(arr , newstr , i+1);
        }

        int notTake = f(arr , temp , i +1);

        return max(take , notTake);
   
    }
    int maxLength(vector<string>& arr) {
        string temp = "";

        return f(arr , temp , 0);
        
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        //the idea is simple , get rid of the biggest digits going left to right
        for(int i =0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){  //means the number was smth like 123456 and in above we wont be able to pop so as we can see the las number will be the highest value , so pop them 
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0'){  //get rid of leading zeros
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
        
    }
};
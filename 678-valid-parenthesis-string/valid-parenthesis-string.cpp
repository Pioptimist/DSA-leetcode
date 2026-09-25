class Solution {
public:
    bool checkValidString(string s) {

        stack<int>openSt;
        stack<int>starSt;

        int n = s.size();

        for(int i=0;i<n;i++){

            if(s[i] == '('){
                openSt.push(i);

            }else if(s[i] == '*'){
                starSt.push(i);

            }else{ // ')'

                if(!openSt.empty()){
                    openSt.pop();

                }else if(!starSt.empty()){
                    starSt.pop();

                }else{
                    return false;

                }
            }
        }
        if(openSt.empty()){
            return true;
        }else{

            while(!openSt.empty() && !starSt.empty() && openSt.top() < starSt.top()){
                openSt.pop();
                starSt.pop();
            }

            if(openSt.empty()){
                return true;
            }
        }

        return false;

    }
};
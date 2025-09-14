class Solution {
public:
    int sum = 0;

    int Countdig(int n){
        int cnt = 0;
        sum = 0;
        while(n!=0){

            sum = sum + n%10;

            n = n/10;

            cnt++;

        }
        return cnt;
    }
    int addDigits(int num) {
        while(Countdig(num)>1){
            num = sum;
        }
        return num;
        
    }
}; 
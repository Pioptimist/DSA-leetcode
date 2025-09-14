class Solution {
public:
    // Function to sum digits of n
    int sumDigits(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int addDigits(int num) {
        while (num >= 10) { // while num has more than 1 digit
            num = sumDigits(num);
        }
        return num;
    }
};

// class Solution {
// public:

//     int M = 1e9 + 7;

//     int f(long long n, long long i) {
//         if(i >= n) {
//             return 1;
//         }
//         long long res = 0;
//         if(i % 2 == 0) {

//             for(int j = 0; j < 5; j++) {
//                 res = (res + f(n, i + 1)) % M;
//             }
//notice we are just recursing for 5 times and 4 times resp , loop is useless
//         }
//         else {
//             for(int j = 0; j < 4; j++) {
//                 res = (res + f(n, i + 1)) % M;
//             }

//         }
//         return res;
//     }

//     int countGoodNumbers(long long n) {

//         return f(n, 0);
//     }
// };

// class Solution {
// public:

//     long long M = 1e9 + 7;

//     long long f(long long n, long long i) {
//         if(i >= n) {
//             return 1;
//         }

//         if(i % 2 == 0) {
//             return (5 * f(n, i + 1)) % M;
//         }

//         return (4 * f(n, i + 1)) % M;
//     }

//     int countGoodNumbers(long long n) {

//         return f(n, 0);
//     }
// };

class Solution {
public:

    long long M = 1e9 + 7;

    long long power(long long a, long long b) {

        long long res = 1;

        while(b > 0) {

            // odd exponent
            if(b % 2 == 1) {
                res = (res * a) % M;
            }

            a = (a * a) % M;
            b /= 2;
        }

        return res;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays * oddWays) % M;
    }
};
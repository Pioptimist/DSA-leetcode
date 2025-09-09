class Solution {
public:
    long long minEnd(int n, int x) {
    long long ans = x;
    long long k = (long long)n - 1;   
    int bit = 0;           

    for (int i = 0; i < 63; i++) {  
        if (((long long)x >> i) & 1) {
            continue; // bit already fixed in x so we dont change this
        }
        if ((k >> bit) & 1) {
            ans |= (1LL << i);  
        }
        bit++;
    }
    return ans;
}

};
class Solution {
public:
    void fillLPS(const string& temp, vector<int>& lps) {
        int n = temp.size();
        lps.resize(n); // Resize the LPS vector
        lps[0] = 0;
        int i = 1;
        int lenlps = 0; // Length of the previous longest prefix which is equal to suffix in temp
        
        while (i < n) {
            if (temp[i] == temp[lenlps]) {
                lenlps++;
                lps[i] = lenlps;
                i++;
            } else {
                if (lenlps != 0) {
                    lenlps = lps[lenlps - 1]; // Use the LPS array to avoid unnecessary comparisons
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    string shortestPalindrome(string s) {
        string rs(s.rbegin(), s.rend()); // Reverse the string
        string temp = s + "#" + rs; // Use a separator to avoid overlap
        vector<int> lps;
        fillLPS(temp, lps);
        
        // The length of the longest palindromic prefix
        int longpref = lps[temp.size() - 1];
        
        // Characters to add in front of the original string
        string weNeedToAdd = rs.substr(0, rs.size() - longpref);
        
        return weNeedToAdd + s; // Return the shortest palindrome
    }
};













// this gives runtime error due to tc
// bool ispalind(int ind,string s){
//     string temp = s.substr(0,ind+1);
//     int n = temp.size();
//     if(n<2) return true;
//     for(int i =0;i<n/2;i++){
//         if(temp[i]!=temp[n-i-1]){
//             return false;
//         }
//     }
//     return true;
// string result = "";
// string revs(s.rbegin(),s.rend());      //way to reverse a string without modying the original
// int n = s.size();
// if(ispalind(n-1,s)) return s;
// for(int i=0;i<n;i++){
//     if(s[i]!=revs[i]){
//         if(ispalind(n-2-i,s)){
//             result = result + revs[i] + s;
//             break;
//         }
//         else{
//             result += revs[i];
//         }
//     }
//     else{
//         if(ispalind(n-2-i,s)){
//             result = result + revs[i] + s;
//             break;
//         }
//         else{
//             result += revs[i];
//         
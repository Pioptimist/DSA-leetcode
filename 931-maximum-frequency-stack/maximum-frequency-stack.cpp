class FreqStack {
    // we pop the element with the most freq  , if there is tie , we pop that element which was pushed in the stack recently
    unordered_map<int, int> freq; // freq of elements
    unordered_map<int, stack<int>> group;  // for each freq we store the element so for eg if we got freq of 2:1 , 3:2 and 5:3 then [1-> [2 , 3 ,5] , 2->[3  ,5] , 3->[ 5 ]] and here maxfreq is 3 , now we are asked to pop , we go to maxfreq in grp and then pop 5. we are asked to pop again now maxfreq is 2 , its  tie since both 5 and 3 are 2 times here , so we go to grp[maxfreq] and pop the most recent one from that stack.
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        freq[val] = freq[val] + 1;
        int f = freq[val];
        maxFreq = max(maxFreq, f);
        group[f].push(val);
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        
        freq[val]--;
        
        if (group[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
class Solution {
    vector<int> tree; // the tree here holds the max gap btw two obstacles lying in 0 to r , can watch codewithmik video or just draw the tree and add obstacles and see how they pan out , make sure to take n for the tree as the max x in the queries
    

    // Point Update
    void update(int i, int l, int r, int idx, int val) { //idx is for the leaf node range , i is to update segT index
        if (l == r) {
            tree[i] = val; // Store the gap at this exact obstacle
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * i + 1, l, mid, idx, val);
        } else {
            update(2 * i + 2, mid + 1, r, idx, val);
        }
        
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    // Standard Range Maximum Query
    int query(int i, int l, int r, int start, int end) {
        if (start > r || end < l) return 0; // Out of bounds
        
        if (start <= l && r <= end) return tree[i]; // Fully inside
        
        int mid = l + (r - l) / 2;
        return max(query(2 * i + 1, l, mid, start, end), 
                   query(2 * i + 2, mid + 1, r, start, end));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        max_x += 2; // Add a small buffer just to be safe
        
        tree.assign(4 * max_x, 0); // Initialize tree with 0s
        
        
        set<int> st;
        st.insert(0); // The track always starts with an implicit obstacle at 0
        
        vector<bool> result;
        
    
        for (const auto& q : queries) {
            if (q[0] == 1) { 
                int x = q[1];
                
                
                auto it = st.upper_bound(x);
                int prev_obs = *prev(it); // Obstacle immediately before x
                
                // The new obstacle at x creates a gap: (x - prev_obs)
                update(0, 0, max_x, x, x - prev_obs);
                
                // If there is an obstacle after x, its gap has now shrunk
                if (it != st.end()) {
                    int next_obs = *it;
                    update(0, 0, max_x, next_obs, next_obs - x); // Shrink the next gap
                }
                
                st.insert(x); 
                
            } else { 
                int x = q[1];
                int sz = q[2];
                
                // Find the last obstacle that comes before or at x
                auto it = prev(st.upper_bound(x));
                int prev_obs = *it;
                
                
                int max_gap_before = query(0, 0, max_x, 0, prev_obs); //max gap from 0 to prev obstacle  , we dont care if x has an obstacle over itself or not as the block can touch an obstacle.
                
            
                int gap_at_end = x - prev_obs;
                
                // If either of those is big enough, it fits!
                if (max(max_gap_before, gap_at_end) >= sz) {
                    result.push_back(true);
                } else {
                    result.push_back(false);
                }
            }
        }
        
        return result;
    }
};


// class Solution {
// public:
//     vector<bool> getResults(vector<vector<int>>& queries) {
//         vector<bool> result;

//         set<int> st;

//         for(auto &query : queries) {
//             if(query[0] == 1) { //Type-1 Query
//                 st.insert(query[1]); //insert x
//             } else {
//                 int x = query[1];
//                 int sz = query[2];

//                 int prev = 0;
//                 bool found = false;

//                 for(int curr : st) {
//                     if(curr > x) {
//                         break;
//                     }

//                     if(curr - prev >= sz) {
//                         found = true;
//                         break;
//                     }

//                     prev = curr;
//                 }

//                 if(!found) {
//                     found = (x - prev >= sz);
//                 }

//                 result.push_back(found);
//             }
//         }

//         return result;
//     }
// };



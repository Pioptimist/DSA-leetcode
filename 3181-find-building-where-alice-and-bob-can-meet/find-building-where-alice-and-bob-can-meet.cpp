class Solution {
public:

    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, const vector<int>& heights) {
        if (l == r) {
            segmentTree[i] = l; 
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);
        buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights);

        segmentTree[i] = (heights[segmentTree[2 * i + 1]] >= heights[segmentTree[2 * i + 2]]) ?
                         segmentTree[2 * i + 1] : segmentTree[2 * i + 2];
    }

    // Function to query the segment tree for the index of the maximum value in range [start, end]
    int querySegmentTree(int start, int end, int i, int l, int r, const vector<int>& segmentTree, const vector<int>& heights) {
        if (l > end || r < start) {
            return -1; // Return -1 for out-of-bound queries
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i]; // Return the index of the maximum element
        }
        
        int mid = l + (r - l) / 2;
        int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;

        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
    }

    // Function to return the index of the maximum element in the range from a to b
    int RMIQ(const vector<int>& st, const vector<int>& heights, int n, int a, int b) {
        return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segmentTree(4 * n);
        
        buildSegmentTree(0, 0, n - 1, segmentTree, heights);

        vector<int> result;
        for(auto& query: queries){
            int min_i = min(query[0], query[1]);
            int max_i = max(query[0], query[1]);

            if(min_i == max_i || heights[max_i] > heights[min_i]){
                result.push_back(max_i); 
                continue;
            }

            int l = max_i + 1;
            int r = n - 1;
            int result_idx = INT_MAX;
            
            while (l <= r) {  // binary search 
                int mid = l + (r - l) / 2;
                int idx = RMIQ(segmentTree, heights, n, l, mid);

                if (heights[idx] > max(heights[min_i], heights[max_i])) {
                    r = mid - 1;
                    result_idx = min(result_idx, idx);
                } else {
                    l = mid + 1;
                }
            }

            if(result_idx == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(result_idx);
            }
        }
        return result;
    }
};
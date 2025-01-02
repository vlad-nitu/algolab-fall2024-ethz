## Topics
- Prefix sum, Binary search OR Sliding window.

## Idea 1 - Binary search
- `O(N^2)` for 75 points: precompute the prefix sum: `pre[i:j]` and then iterate: for (i=0,n) for(j=i,n) nested and store the closest_sum to `k`. 
- (O(NlogN) Binary Search + Prefix Sum) : |k - s[i:j]| = |k - (pre[j] - pre[i-1])| = |pre[j] - (k + pre[i-1])|; Iterate through all `i`'s and binary search `j` as follows:
- `auto it_j = std::lower_bound(pre.begin() + i, pre.end(); k + pre[i - 1]);` <=> smallest `j >= i` s.t.: pre[j] - (k + pre[i - 1]) >= 0

## Idea 2 - Sliding window
- `O(N)`: sliding_window_sum = pre[j] - pre[i - 1] <= k: j ++ (right ptr); else i++ (left ptr)
- Lexicographical ordering is ensured the way we update the sliding windows' boundaries
- Sliding window is [i:j] (both ends inclusive)


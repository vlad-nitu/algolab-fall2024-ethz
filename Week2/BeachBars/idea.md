# Topics
- Sliding window, math.

# Idea
- Sort input inc. order to be able to use Sliding Window on the sorted input later.
- Use Sliding Window to keep track of the amount of bars we can reach [x - 100, x + 100], by placing a bar in position `x`. 
- Mathematically: the best position for `x` is in the middle of `[v[i], v[j]]` segment. 
- Let `diff = x[j] - x[i]`. 2 cases:
1. If `diff % 2 == 0` (meaning that there is an odd number of integer positions in the segment: `v[i], v[j]`, we can uniquely place the bar to achieve the min. max distance from all the cadidates (which is equivalent to the min. max distance to the ends of the segment) by placing it in: `a = v[i] + diff / 2`). Note that `a` is at min max distance from both left and right ends (`v[i]` and `v[j]`, respectively), at `curr_min_dist = diff/2`).
2. If `diff % 2 == 1` (meaning that there is an even number of integer positions in the segment: `v[i], v[j]`, we can place the bar in two positions to achieve the min. max distance from all the cadidates (which is equivalent to the min. max distance to the ends of the segment) by placing it in: `a = v[i] + diff / 2` OR `b = v[i] + diff / 2 + 1`). Note that `a` is at min max distance from the right end (`v[j]`), whereas `b` is at min max distance from the left end (`v[i]`), both at `curr_min_dist = diff/2 + 1`.
- SLIDING WINDOW: `if v[j] - v[i] <= 200: j ++ (increase window by moving the right ptr. to the right); else i ++ (decrease/shrink window by moving the left ptr to the right)`
- 3 cases:
1. `curr_num_parasols > max_num_parasols`  -> update `max_num_parasols` and `min_dist` with the current values, clear old values in `opt_locs` and add the candidates to it (opt_locs = cands). 
2. `curr_num_parasols == max_num_parasols && curr_min_dist < min_dist`  -> same as in 1
3. `curr_num_parasols == max_num_parasols && curr_min_dist == min_dist`  -> append the new candidates `cands` to `opt_locs`.


# Time complexity
- `O(NlogN)` for sorting the input (or for the sorted set `opt_locs` that we use to insert candidates, to ensure the bars are unique and sorted in ascending order by-construction).

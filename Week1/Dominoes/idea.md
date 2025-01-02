## Topics
- Greedy, Impl.

## Idea
- At any iteration `i`, we will bring down dominoes: `std::max(fall_id, i + v[i] - 1)`
- If we can't reach current Domino `i`, the answer is `i-1` (the last domino that we could reach) & break

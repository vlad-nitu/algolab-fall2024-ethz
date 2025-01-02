## Topics
- Partial sums, Combinatorics

## Idea
- reduce 3D problem to 2D by fixing 2 rows: `(i1, i2)`; `i1 <= i2` and then reduce the elements between the rows on each column using:  `pref_sum_col[j][i]` = sum of all elements on col 'j' between rows '0' to 'i', inclusive: 
sum[i1,i2,j1] = pref_sum_col[j1][i2] - pref_sum_col[j1][i1 - 1] , where sum[i1,i2,j1] means the sum of all elements on column `j1` in the input matrix, between the rows `i1` and `i2` rows (observe how we map a vector to an integer, and then: a submatrix to a vector, when iterating all columns for a set `(i1, i2)` pair. 
- After reducing the problem from 3D to 2D, we can run the [`Even Pairs`](../EvenPairs/src/main.cpp) algorithm in `O(N)` for each pair `(i1, i2); i1 <= i2`.

## Time complexity
- `O(N^3)`: `O(N^2)`: `i1` and `i2` fixed rows and `O(N)` 2D even pairs for each such `(i1, i2)` pair.

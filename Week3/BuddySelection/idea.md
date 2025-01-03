# Topics
- BGL: Max Matching

# Idea
- Construct a BGL Graph `G` by adding an edge between students `(i, j); 0 <= i < n; i < j < n` if they have more than `f` common characteristics. 
- To **compute how many characteristics two students have in common**: store the characteristics of each student in an `std::unordered<std::string>`. Next, fix one set (say: characteristics of `i`, and iterate through all: `x : set_of_characteristics_of_j`; if `x in set_of_characteristics_of_i` => `x` is a common characteristic of both `i` and `j`. Count how many such `x`s exist.
- Run [`boost::edmonds_maximum_cardinality_matching`](https://algolab.inf.ethz.ch/doc/boost/doc/libs/1_74_0/libs/graph/doc/maximum_matching.html) on the Graph (also known as "Edmonds Maximum Cardinality Matching") to obtain the number of student pairs: `boost::matching_size` that can be formed with `> f` common characteristics.
- ANS: `if (pairs == N / 2)` => all students could be matched with another student that has `> f` common characteristics with him => "not optimal"; else "optimal" from professor.

# Time complexity
- Edmonds' Maximum Matching algorithm: `O(m * n * ack(m, n))`, where m <= C_n_2 = n * (n - 1) / 2 and n <= 400 => `O(n^3)` worst case.


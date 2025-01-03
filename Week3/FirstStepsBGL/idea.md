# Topics
- BGL Graphs: Dikjstra & Kruskal

# Idea`
- Build an undirected graph `G` based on slides code:
```
edge_desc_undir e = boost::add_edge(u, v, G).first; weights[e] = c;
```
- Run Kruskal on it based on slides code. In order to retrieve `mst_cost` = sum of edges of the MST, pass the `weights` weight_map as const& to the function and:
```
  for (std::vector<edge_desc_undir>::iterator it = mst.begin(); it != mst.end(); ++it) {
    mst_cost += mst_weights[*it];
```
- Run Dijkstra based on slides code. When retrieving `max_dist(0, u)` for any node `u` in the graph, ensure that `u` was visited by Dijkstra by checking `dist_map[u] != std::numeric_limits<int>::max()` (as, based on BGL Dijkstra docs, when a node is not visited, the `dist_map[u]` entry is populated w/ `INT_MAX`.
- NOTE how weight maps expect an vertex/edge descriptor as argument: `weights[e]`

# Time Complexity: 
- `O(MlogM)` for Kruskal (MST) and `O(NlogN + M)` for Dijkstra.

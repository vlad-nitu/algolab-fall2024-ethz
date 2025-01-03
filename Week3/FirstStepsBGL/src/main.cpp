///1
#include <bits/stdc++.h>
using namespace std;

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp> // MST
#include <boost/graph/dijkstra_shortest_paths.hpp> // Dijkstra

// MST & Dijkstra: both on undirected graph
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      weighted_graph_undir;
typedef boost::property_map<weighted_graph_undir, boost::edge_weight_t>::type weight_map_undir;
typedef boost::graph_traits<weighted_graph_undir>::edge_descriptor            edge_desc_undir;
typedef boost::graph_traits<weighted_graph_undir>::vertex_descriptor          vertex_desc_undir;  


int kruskal(const weighted_graph_undir &G, const weight_map_undir &mst_weights) {
  std::vector<edge_desc_undir> mst;    // vector to store MST edges (not a property map!)

  boost::kruskal_minimum_spanning_tree(G, std::back_inserter(mst));

  int mst_cost = 0; 
  for (std::vector<edge_desc_undir>::iterator it = mst.begin(); it != mst.end(); ++it) {
    mst_cost += mst_weights[*it]; 
  }
  return mst_cost;
}

std::vector<int> dijkstra_dist_map(const weighted_graph_undir &G, int src) {
  int n = boost::num_vertices(G);
  std::vector<int> dist_map(n);

  boost::dijkstra_shortest_paths(G, src,
    boost::distance_map(boost::make_iterator_property_map(
      dist_map.begin(), boost::get(boost::vertex_index, G))));

  return dist_map; 
}

void solve() {
  int n, m; cin >> n >> m; 

  // Create G
  weighted_graph_undir G(n);
  weight_map_undir weights = boost::get(boost::edge_weight, G);

  
  
  for (int i = 0; i < m; ++i) {
    int u, v, c; cin >> u >> v >> c; 
    // Build G
    edge_desc_undir e = boost::add_edge(u, v, G).first; weights[e] = c;
  }
  
  std::vector<int> dist_map = dijkstra_dist_map(G, 0);  
  int max_dist = -1; 
  for (auto &dist: dist_map) {
    if (dist != std::numeric_limits<int>::max())
      max_dist = max(dist, max_dist); 
  }    
  std::cout << kruskal(G, weights) << ' ' << max_dist << '\n';  
  
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve();
}


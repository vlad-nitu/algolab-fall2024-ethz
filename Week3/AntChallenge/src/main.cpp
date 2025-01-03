///4
#include <bits/stdc++.h> 
using namespace std; 

using vec_t = vector<int>; 
using mat_2d_t = vector<vec_t>;
using mat_3d_t = vector<mat_2d_t>; 

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp> // Kruskal MST
#include <boost/graph/dijkstra_shortest_paths.hpp> // Dijkstra

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      weighted_graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<weighted_graph>::edge_descriptor            edge_desc;
typedef boost::graph_traits<weighted_graph>::vertex_descriptor          vertex_desc;


std::vector<edge_desc> kruskal(const weighted_graph &G) {

  
  weighted_graph dijkstra_G(boost::num_vertices(G));
  weight_map dijkstra_weights = boost::get(boost::edge_weight, dijkstra_G);
  
  std::vector<edge_desc> mst;    // vector to store MST edges (not a property map!)
  boost::kruskal_minimum_spanning_tree(G, std::back_inserter(mst));
  
  return mst; 
}

int dijkstra_dist(const weighted_graph &G, int s, int t) {
  int n = boost::num_vertices(G);
  std::vector<int> dist_map(n);

  boost::dijkstra_shortest_paths(G, s,
    boost::distance_map(boost::make_iterator_property_map(
      dist_map.begin(), boost::get(boost::vertex_index, G))));

  return dist_map[t];
}

void solve() {
  int n, e, s, start, stop; cin >> n >> e >> s >> start >> stop; 
  
  mat_3d_t m(s, mat_2d_t(n, vec_t(n, std::numeric_limits<int>::max()))); 
  
  for (int i = 0; i < e; ++i) {
    int a, b; cin >> a >> b;
    for (int j = 0; j < s; ++j) { // Add the edges in the private network m[j] of specie `j`
      int t; cin >> t;
      m[j][a][b] = m[j][b][a] = std::min(m[j][a][b], t); 
    }
  }
  
  for (int i = 0; i < s; ++i) { // Hives: useless info in the problem
    int x; cin >> x;
  }
  
  mat_2d_t min_edge(n, vec_t(n, std::numeric_limits<int>::max())); 

  for (int j = 0; j < s; ++j) {
    weighted_graph mst_G(n); 
    weight_map mst_weights = boost::get(boost::edge_weight, mst_G);
    
    for (int a = 0; a < n; ++a)
      for (int b = a + 1; b < n; ++b) 
        if (m[j][a][b] != std::numeric_limits<int>::max()) {
          edge_desc e = boost::add_edge(a, b, mst_G).first; 
          mst_weights[e] = m[j][a][b];   
        }
    std::vector<edge_desc> mst = kruskal(mst_G); 
    for (std::vector<edge_desc>::iterator it = mst.begin(); it != mst.end(); ++it) {
      int a = boost::source(*it, mst_G); int b = boost::target(*it, mst_G); 
      min_edge[a][b] = min_edge[b][a] = min(min_edge[a][b], m[j][a][b]); 
    }
  }
  
   weighted_graph dijkstra_G(n); 
   weight_map dijkstra_weights = boost::get(boost::edge_weight, dijkstra_G);
   for (int a = 0; a < n; ++a)
    for (int b = 0; b < n; ++b)
      if (min_edge[a][b] != std::numeric_limits<int>::max())
      {
        auto e = boost::add_edge(a, b, dijkstra_G).first; 
        dijkstra_weights[e] = min_edge[a][b]; 
      }
    
  std::cout << dijkstra_dist(dijkstra_G, start, stop) << '\n'; 
  
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve();
}

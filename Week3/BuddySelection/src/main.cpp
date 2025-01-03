///1
#include <bits/stdc++.h> 
using namespace std; 

using set_t = unordered_set<string>; 
using mat_t = vector<set_t>; 

// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/max_cardinality_matching.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> graph;
typedef boost::graph_traits<graph>::vertex_descriptor                       vertex_desc;

int common_chars_count(const set_t &s1, const set_t &s2) {
  int cnt = 0;
  for (auto x: s2)
    if (s1.find(x) != s1.end())
      cnt ++; 
  
  return cnt;
}

void solve() {
  int n, c, f; cin >> n >> c >> f; 
  
  mat_t characteristics(n); 
  
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < c; ++j) {
        string charact; cin >> charact; 
        characteristics[i].insert(charact); 
      }
  }
  
  graph G(n); 
  
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) { // for each pair of students (i, j)
      if (common_chars_count(characteristics[i], characteristics[j]) > f) { // Add an edge in the graph for possible matching
        boost:add_edge(i, j, G); 
      } 
    }
  
  // Run Edomn's Maximum Matching algorithm in O(m * n * ack(n, m)); ack(n, m) <= 4
  std::vector<vertex_desc> mate_map(n);  // exterior property map
  
  boost::edmonds_maximum_cardinality_matching(G,
    boost::make_iterator_property_map(mate_map.begin(), boost::get(boost::vertex_index, G)));
  int matching_size = boost::matching_size(G,
    boost::make_iterator_property_map(mate_map.begin(), boost::get(boost::vertex_index, G)));
  
  if (matching_size == n / 2) {
    std::cout << "not optimal\n";
  }
  else
    std::cout << "optimal\n"; 
    
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve();
  
}

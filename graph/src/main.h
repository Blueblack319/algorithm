#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

template <typename T>
struct Edge {
  unsigned src;
  unsigned dst;
  T weight;
};

template <typename T>
class Graph {
 private:
  unsigned V;
  std::vector<Edge<T>> edge_list;

 public:
  Graph(unsigned N) : V(N) {}

  auto vertices() const { return V; }

  auto& edges() const { return edge_list; }

  auto edges(unsigned v) const {
    std::vector<Edge<T>> edges_from_v;
    for (auto& e : edge_list) {
      if (e.src == v) edges_from_v.emplace_back(e);
    }

    return edges_from_v;
  }

  void add_edge(Edge<T>&& e) {
    if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
      edge_list.emplace_back(e);
    else
      std::cerr << "Out of bound" << std::endl;
  }

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Graph<U>& G);
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const Graph<U>& G) {
  for (unsigned i = 1; i < G.vertices(); i++) {
    os << i << ":\t";

    auto edges = G.edges(i);
    for (auto& e : edges) os << "{" << e.dst << ": " << e.weight << "}, ";

    os << std::endl;
  }
  return os;
}

template <typename T>
auto create_reference_graph() {
  Graph<T> G(9);

  std::map<unsigned, std::vector<std::pair<unsigned, T>>> edge_map;
  edge_map[1] = {{2, 0}, {5, 0}};
  edge_map[2] = {{1, 0}, {5, 0}, {4, 0}};
  edge_map[3] = {{4, 0}, {7, 0}};
  edge_map[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
  edge_map[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
  edge_map[6] = {{4, 0}, {7, 0}, {8, 0}};
  edge_map[7] = {{3, 0}, {6, 0}};
  edge_map[8] = {{4, 0}, {5, 0}, {6, 0}};

  for (auto& i : edge_map)
    for (auto& j : i.second) G.add_edge(Edge<T>{i.first, j.first, j.second});

  return G;
}

template <typename T>
std::vector<unsigned> bfs(const Graph<T>& G, unsigned start);

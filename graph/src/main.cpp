#include "main.hpp"

#include <iostream>

template <typename T>
std::vector<unsigned> dfs(const Graph<T>& G, unsigned start,
                          std::set<unsigned>& visited,
                          std::vector<unsigned>& visit_order) {
  visited.insert(start);
  visit_order.push_back(start);

  for (auto& edge : G.edges(start)) {
    if (visited.find(edge.dst) == visited.end())
      dfs(G, edge.dst, visited, visit_order);
  }
  return visit_order;
};

int main() {
  using T = unsigned;

  auto G = create_reference_graph<T>();
  std::cout << "[Input Graph]" << std::endl;
  std::cout << G << std::endl;

  std::cout << "[DFS visit order]" << std::endl;
  std::set<unsigned> visited;
  std::vector<unsigned> visit_order;
  auto bfs_visit_order = dfs(G, 1, visited, visit_order);
  for (const auto& v : bfs_visit_order) std::cout << v << std::endl;
  return 0;
}
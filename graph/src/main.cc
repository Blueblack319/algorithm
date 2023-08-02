#include "main.h"

#include <iostream>

template <typename T>
std::vector<unsigned> breadthFirst(const Graph<T>& G, unsigned start) {
  // We need three data structures: queue, visited(vector),
  // visited_order(vector)
  std::queue<unsigned> queue;
  std::set<unsigned> visited;
  std::vector<unsigned> visit_order;

  queue.push(start);
  while (!queue.empty()) {
    unsigned current = queue.front();
    queue.pop();

    if (visited.find(current) == visited.end()) {
      visited.insert(current);
      visit_order.push_back(current);
      auto edges_from = G.edges(current);

      for (auto& edge : edges_from) {
        if (visited.find(edge.dst) == visited.end()) queue.push(edge.dst);
      }
    }
  }
  return visit_order;
};

int main() {
  using T = unsigned;

  auto G = create_reference_graph<T>();
  std::cout << "[Input Graph]" << std::endl;
  std::cout << G << std::endl;

  std::cout << "[BFS visit order]" << std::endl;
  auto bfs_visit_order = breadthFirst(G, 1);
  for (const auto& v : bfs_visit_order) std::cout << v << std::endl;
  return 0;
}
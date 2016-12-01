#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <list>

using namespace std;

class graph {

public:
  graph(int V);
  void add_edge(int v, int w);
  void BFS(int s);

private:
  int _v;
  vector<list<int>> _adjacent;
};

graph::graph(int V) : _adjacent(V) {
  this->_v = V;
}

void graph::add_edge(int v, int w) {
  _adjacent[v].push_back(w);
}

void graph::BFS(int s) {

  vector<bool> visited(_v, false);
  vector<int> distance(_v, -1);

  list<int> queue;

  visited[s] = true;
  distance[s] = 0;
  queue.push_back(s);

  while (!queue.empty()) {

    s = queue.front();
    queue.pop_front();

    for (auto i : _adjacent[s]) {
      if (!visited[i]) {
        visited[i] = true;
        distance[i] = distance[s] + 6;
        queue.push_back(i);
      }
    }
  }

  for (int i = 0; i < _v; i++) {
    if (distance[i]) {
      cout << distance[i];
      if (i != (_v - 1))
        cout << " ";
    }
  }
}


void bfs_short_reach() {
  int q;

  cin >> q;

  for (int i = 0; i < q; i++) {
    int nodes, edges;

    cin >> nodes >> edges;

    graph gr(nodes);
    for (int k = 0; k < edges; k++) {
      int start_node;
      int end_node;

      cin >> start_node >> end_node;

      gr.add_edge(start_node - 1, end_node - 1);
      gr.add_edge(end_node - 1, start_node - 1);
    }

    int start_node;
    cin >> start_node;
    gr.BFS(start_node - 1);

    if (i != (q - 1))
      cout << endl;
  }
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <list>
#include <set>

#include "utils.h"

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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
void rust_murder() {
    int t;

    const int MAXN = 2 * 5000;    
    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        vector<set<int>> adj_list(n);

        for (int i = 0; i < m; i++) {
            int v1, v2;

            cin >> v1 >> v2;
            v1--;
            v2--;

            adj_list[v1].insert(v2);
            adj_list[v2].insert(v1);
        }

        int start_node;
        cin >> start_node;

        start_node--;
        
        vector<bool> visited(n, false);
        vector<int> distance(n, -1);

        list<int> queue;

        visited[start_node] = true;
        distance[start_node] = 0;
        queue.push_back(start_node);

        set<int>unvisited;
        for (int i = 0; i < n; i++) {        
            if (i != start_node)
                unvisited.insert(i);
        }

        int vis_node;
        while (!queue.empty()) {

            vis_node = queue.front();
            queue.pop_front();

            for (auto it = unvisited.begin(); it != unvisited.end();) {
                if (adj_list[vis_node].find(*it) == adj_list[vis_node].end()) {

                    auto tmp = it;
                    ++tmp;
                    distance[*it] = distance[vis_node] + 1;
                    queue.push_back(*it);
                    unvisited.erase(it);
                    it = tmp;
                } else {
                    ++it;
                }                 
            }                          
        }
        
        for (int i = 0; i < n; i++) {
            if (distance[i]) {
                cout << distance[i];
                if (i != (n - 1))
                    cout << " ";
            }
        }

        cout << endl;
    }
}

//-----------------------------------------------------------------------------
void count_connections(vector<vector <uint64> >& adjacent, vector< bool >& visited, uint64 k) {
    
    visited[k] = true;
    for (int i = 0; i < adjacent[k].size(); i++) {
        if (!visited[adjacent[k][i]]) {            
            count_connections(adjacent, visited, adjacent[k][i]);
        }
    }
    return;
}

void roads_and_libraries() {

    int q;

    cin >> q;
    while (q--) {
        uint64 n, m, clib, croad;
        cin >> n >> m >> clib >> croad;

        vector<vector<uint64>> adjacent(n);

        for (int i = 0; i < m; i++) {
            uint64 u, v;
            cin >> u >> v;
            u--;
            v--;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }   

        if (croad >= clib) {
            cout << clib * n << endl;
            continue;
        }
                       
        // count components;
        vector<bool> visited(n, false);
        uint64  component_count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {                
                count_connections(adjacent, visited, i);
                component_count ++;
            }
        }

        cout << (n - component_count) * croad + component_count * clib << endl;
    }
}

//-----------------------------------------------------------------------------
void count_players(vector<vector <uint64> >& adjacent, vector< bool >& visited, uint64 k, uint64& count) {

    visited[k] = true;
    count++;
    for (int i = 0; i < adjacent[k].size(); i++) {
        if (!visited[adjacent[k][i]]) {
            count_players(adjacent, visited, adjacent[k][i], count);
        }
    }
    return;
}

void journey_to_the_moon() {
    uint64 n, p; // number of astronauts, number of pairs
    cin >> n >> p;

    vector<vector<uint64>> adjacent(n);

    for (int i = 0; i < p; i++) {
        uint64 u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<uint64> countries;

    uint64 ones = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            uint64 count = 0;
            count_players(adjacent, visited, i, count);
            if (count > 1)
                countries.push_back(count);
            else
                ones++;
        }
    }

    uint64 sum = 0;
    for (int i = 0; i < countries.size(); i++)
        for (int j = i + 1; j < countries.size(); j++)
            sum += countries[i] * countries[j];

    // adjust for ones;
    
    if (ones != 0) {
        for (int i = 0; i < countries.size(); i++)
            sum += countries[i] * ones;

        sum += (0 + ones - 1) * ones / 2;

        //sum += sum * ones + (0 + ones - 1) * ones / 2;
    }
        

    cout << sum;
}


//-----------------------------------------------------------------------------
void prim_mst() {
    uint64 n, m;
    cin >> n >> m;

    // represent the node and the distance as pair <node, distance;
    vector<vector<pair<uint64, uint64>>> adjacent(n);

    for (int i = 0; i < m; i++) {
        uint64 u, v, dist;
        cin >> u >> v >> dist;
        u--;
        v--;
        adjacent[u].push_back({v, dist });
        adjacent[v].push_back({u, dist});
    }

    uint64 start;
    cin >> start;
    start--;


}
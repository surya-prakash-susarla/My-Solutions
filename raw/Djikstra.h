#include <iostream>
#include <limits>
#include <set>
#include <vector>
using namespace std;

int MAX_VALUE = numeric_limits<int>::max();

int getClosest(const vector<int>& distances, const vector<bool>& visited) {
  int min_value = MAX_VALUE, index = -1;
  for (int i = 0; i < distances.size(); i++)
    if (distances[i] != -1 and not visited[i] and distances[i] < min_value) {
      min_value = distances[i];
      index = i;
    }
  return index;
}

vector<int> djikstraSourceAllPairShortestPath(int source,
                                              vector<vector<int>> graph) {
  // disconnection between vertices given by '0'
  vector<int> distances(graph.size(), -1);
  distances[source] = 0;
  vector<bool> visited(graph.size(), false);
  while (true) {
    int index = getClosest(distances, visited);
    if (index == -1)
      break;
    for (int i = 0; i < graph.size(); i++)
      if (graph[index][i] != -1 and
          (distances[i] == -1 or
           distances[i] > graph[index][i] + distances[index]))
        distances[i] = graph[index][i] + distances[index];
    visited[index] = true;
  }
  return distances;
}

#include <bits/stdc++.h>

#include <limits>
#include <stack>
#include <vector>

using namespace std;

typedef long long int llint;

vector<string> split_string(string);

llint max_value = numeric_limits<llint>::max();

llint dfs(llint node,
          vector<bool>& visited,
          vector<vector<bool>> matrix,
          vector<int> cost) {
  stack<llint> stack_values;
  llint total_sum = 0;
  stack_values.push(node);
  while (not stack_values.empty()) {
    llint current_node = stack_values.top();
    stack_values.pop();
    total_sum += cost[current_node];
    visited[current_node] = true;
    for (llint i = 0; i < matrix.size(); i++)
      if (matrix[current_node][i] and not visited[i]) {
        // cout  << "Pushing into stack " << i << endl;
        stack_values.push(i);
      }
  }
  return total_sum;
}

// Complete the balancedForest function below.
llint balancedForest(vector<int> c, vector<vector<int>> edges) {
  cout << endl << endl << "-------------------------------" << endl;
  llint nodes = c.size();
  vector<vector<bool>> matrix(nodes, vector<bool>(nodes, false));
  for (llint i = 0; i < edges.size(); i++)
    matrix[edges[i][0] - 1][edges[i][1] - 1] = true, matrix[edges[i][1] - 1]
                                                           [edges[i][0] - 1] =
                                                               true;
  llint total_sum = 0;
  for (int i = 0; i < nodes; i++)
    total_sum += c[i];
  cout << "Total dfs value : " << total_sum << endl;
  llint final_answer = max_value, n_edges = edges.size();
  for (llint i = 0; i < n_edges; i++) {
    vector<bool> visited(nodes, false);
    llint v1 = edges[i][0] - 1, v2 = edges[i][1] - 1;
    matrix[v1][v2] = false, matrix[v2][v1] = false;
    llint sum1 = dfs(v1, visited, matrix, c);
    // check possibility of removing only a single edge
    if (total_sum - sum1 == sum1 and sum1 < final_answer)
      final_answer = sum1;
    // else if ( sum1 < total_sum - sum1 )
    //{
    for (llint j = i + 1; j < n_edges; j++) {
      vector<bool> visited_backup(visited);
      llint s1_bk = sum1;
      llint v3 = edges[j][0] - 1, v4 = edges[j][1] - 1;
      matrix[v3][v4] = false, matrix[v4][v3] = false;
      llint sum2 = -1, sum3 = -1;
      if (visited[v3]) {
        // cout  << "Picked second " << v4 << endl;
        vector<bool> temp_visited(nodes, false);
        sum2 = dfs(v4, temp_visited, matrix, c);
        sum1 -= sum2;
        sum3 = total_sum - sum1 - sum2;
      } else if (sum1 < total_sum - sum1)
      // else
      {
        // cout  << "Picked second direct : " << v3 << endl;
        sum2 = dfs(v3, visited, matrix, c);
        sum3 = total_sum - sum1 - sum2;
      }
      if (sum1 == sum2 and sum3 < sum2 and sum2 - sum3 < final_answer)
        final_answer = sum2 - sum3;
      else if (sum2 == sum3 and sum1 < sum2 and sum3 - sum1 < final_answer)
        final_answer = sum3 - sum1;
      else if (sum3 == sum1 and sum2 < sum1 and sum1 - sum2 < final_answer)
        final_answer = sum1 - sum2;
      matrix[v3][v4] = true, matrix[v4][v3] = true;
      visited = visited_backup;
      sum1 = s1_bk;
      // cout  << v1 << " " << v2 << " " << v3 << " " << v4 << endl;
      // cout  << sum1 << " " << sum2 << " " << sum3 << endl;
    }
    //}
    matrix[v1][v2] = true, matrix[v2][v1] = true;
  }
  if (final_answer == max_value)
    return -1;

  cout << final_answer << endl;

  return final_answer;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
      int c_item = stoi(c_temp[i]);

      c[i] = c_item;
    }

    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
      edges[i].resize(2);

      for (int j = 0; j < 2; j++) {
        cin >> edges[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = balancedForest(c, edges);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char& x, const char& y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

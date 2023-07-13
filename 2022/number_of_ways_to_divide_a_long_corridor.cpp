#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numberOfWays(string input) {
    vector<int> indices;
    constexpr int mod = 1000000007;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 'S')
        indices.push_back(i);
    }

    if (indices.size() < 2 or indices.size() % 2 == 1)
      return 0;
    else if (indices.size() == 2)
      return 1;
    else {
      typedef long long int llint;
      llint answer = 1;
      for (int i = 2; i < indices.size(); i += 2) {
        int current_gap = indices[i] - indices[i - 1];
        answer *= current_gap;
        answer %= mod;
      }
      return answer;
    }
  }
};

int main() {
  std::vector<std::pair<std::string, int>> values = {
      {"SPSPPSSPSSSS", 6},
      {"SSSS", 1},
      {"SSPPSPS", 3},
      {"PPSPSP", 1},
      {"S", 0},
      {"SPPPPPPPSPPPSPSSSPPPPPPPPPPPPPPPPPSPPPPPPPPPPPPPPPPSPPPPPSPSPPPPPPSPSPP"
       "SPSPPPSPSPPSSPPPPPSPPSSPP",
       0},
      {"SSS", 0}};

  for (const std::pair<string, int>& i : values) {
    Solution temp;
    int answer = temp.numberOfWays(i.first);
    cout << "Given answer for : " << i.first << "   = " << answer << endl;
    cout << "Expected answer : " << i.second << endl;
    cout << endl;
  }
  return 0;
}

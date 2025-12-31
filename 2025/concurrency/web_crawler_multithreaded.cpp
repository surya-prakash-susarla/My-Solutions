#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

typedef long long int llint;
typedef long long unsigned int ullint;

using namespace std;

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
 public:
  vector<string> crawl(string startUrl, HtmlParser parser) {
    const int n = 5;
    working = vector<atomic<bool>>(n);
    for (int i = 0; i < n; i++)
      working[i] = false;
    pending.push(startUrl);
    for (int i = 0; i < n; i++) {
      cout << "starting thread : " << i << endl;
      pool.emplace_back(&Solution::run, this, parser, i);
    }

    {
      unique_lock l(m);
      c.wait(l, [&] { return shouldExit(); });
      stop = true;
      c.notify_all();
    }

    cout << "exiting main thread" << endl;
    return {discovered.begin(), discovered.end()};
  }

  bool shouldExit() {
    bool none_working = true;
    for (int i = 0; i < working.size(); i++)
      none_working &= not working[i].load();
    return none_working and pending.empty();
  }

  bool isSameDomain(string base, string target) {
    string bd = getDomain(base);
    string td = getDomain(target);
    return bd == td;
  }

  string getDomain(string url) {
    string current;
    int c = 0;
    for (char i : url) {
      if (i == '/') {
        if (c > 2)
          return current;
        c++;
      } else if (c == 2) {
        current += i;
      }
    }
    return current;
  }

  void run(HtmlParser parser, int i) {
    while (true) {
      unique_lock l(m);
      c.wait(l, [&] { return stop.load() or not pending.empty(); });
      if (stop.load()) {
        cout << "stopping thread : " << i << endl;
        c.notify_all();
        return;
      }
      working[i] = true;
      string current = pending.front();
      cout << "processing url : " << current << endl;
      pending.pop();
      bool should_skip_discovery = discovered.contains(current);
      if (!should_skip_discovery)
        discovered.insert(current);

      l.unlock();

      if (should_skip_discovery) {
        working[i] = false;
        c.notify_all();
        continue;
      }

      c.notify_all();

      // slow call.
      vector<string> next = parser.getUrls(current);
      vector<string> valid;
      for (auto i : next) {
        if (isSameDomain(current, i))
          valid.push_back(i);
      }

      {
        lock_guard l(m);
        for (auto i : valid)
          pending.push(i);
        c.notify_all();
      }

      cout << "setting working of : " << i << " , to false " << endl;
      working[i] = false;
      c.notify_all();
    }
  }

  vector<jthread> pool;
  vector<atomic<bool>> working;
  atomic<bool> stop = false;

  mutex m;
  condition_variable c;
  queue<string> pending;
  set<string> discovered;
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}

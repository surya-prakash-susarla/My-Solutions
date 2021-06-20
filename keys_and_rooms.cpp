class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int size = rooms.size();
    vector<bool> visited(size, false);
    queue<int> q;
    set<int> s;

    q.push(0);

    while (not q.empty()) {
      int current_room = q.front();
      if (s.size() == size)
        return true;
      if (not visited[current_room]) {
        s.insert(current_room);
        for (auto i : rooms[current_room])
          if (not visited[i])
            q.push(i);
        visited[current_room] = true;
      }
      q.pop();
    }

    if (s.size() == size)
      return true;
    return false;
  }
};
class Solution {
 public:
  bool canAliceWin(int n) {
    int remove = 11;

    bool alice = true;

    while (true) {
      remove--;
      if (alice) {
        if (remove == n)
          return true;

        if (remove > n)
          return false;

        n -= remove;

      } else {
        if (remove == n)
          return false;

        if (remove > n)
          return true;

        n -= remove;
      }

      alice = not alice;
    }
    return false;
  }
};

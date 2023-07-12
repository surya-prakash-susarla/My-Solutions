/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#define interval Interval
class Solution {
 public:
  vector<Interval> intervalIntersection(vector<Interval>& a,
                                        vector<Interval>& b) {
    vector<interval> answers;
    int index = 0;
    for (interval current : b) {
      for (int i = index; i < a.size(); i++) {
        if (a[i].start == current.start) {
          // equal case
          answers.push_back(
              interval(current.start, min(current.end, a[i].end)));
        } else if (a[i].start > current.start) {
          // greater case
          if (a[i].start <= current.end)
            answers.push_back(interval(a[i].start, min(current.end, a[i].end)));
          else
            continue;
        } else {
          // smaller case
          if (a[i].end >= current.start)
            answers.push_back(
                interval(current.start, min(current.end, a[i].end)));
          else
            index += 1;
        }
      }
    }
    return answers;
  }
};
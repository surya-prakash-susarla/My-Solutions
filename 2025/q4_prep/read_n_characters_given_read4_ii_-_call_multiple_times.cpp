/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */

  int __rec__(char* buf, int& buf_offset, int n) {
    if (prev_offset == 4) {
      // full content so fresh read.

      int rc = read4(temp);

      if (rc == 0)
        return 0;

      older_read_size = rc;
      int limit = min(n, rc);

      // dirty assignment.
      rc = limit;

      prev_offset = 0;
      while (limit--) {
        buf[buf_offset++] = temp[prev_offset++];
      }

      return rc;
    } else {
      // content exists.
      int content_size = older_read_size - prev_offset;
      int return_value = min(n, content_size);

      if (n < content_size) {
        while (n--) {
          buf[buf_offset++] = temp[prev_offset++];
        }
      } else {
        while (content_size--)
          buf[buf_offset++] = temp[prev_offset++];

        // jump the prev offset to end since the partial buffer is read.
        prev_offset = 4;
      }
      return return_value;
    }
  }

  int read(char* buf, int n) {
    int of = 0;
    int tr = 0;
    while (n > 0) {
      int rc = __rec__(buf, of, n);
      if (rc == 0) {
        return tr;
      }

      tr += rc;
      n -= rc;
    }
    return tr;
  }

  int older_read_size = 0;
  int prev_offset = 4;
  char* temp = new char[4];
};

class Solution {
 public:
  string defangIPaddr(string address) {
    string final_value;
    for (char c : address) {
      if (c != '.')
        final_value = final_value + c;
      else {
        final_value = final_value + '[' + c + ']';
      }
    }
    return final_value;
  }
};
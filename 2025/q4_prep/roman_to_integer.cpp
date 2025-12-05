class Solution {
 public:
  int romanToInt(string input) {
    int answer = 0;

    for (int i = 0; i < input.size(); i++) {
      switch (input[i]) {
        case 'V':
          answer += 5;
          break;
        case 'L':
          answer += 50;
          break;
        case 'D':
          answer += 500;
          break;
        case 'M':
          answer += 1000;
          break;
        case 'I': {
          if (i + 1 < input.size() and
              (input[i + 1] == 'V' or input[i + 1] == 'X')) {
            if (input[i + 1] == 'V')
              answer += 4;
            else
              answer += 9;
            i++;
          } else {
            answer += 1;
          }
          break;
        }
        case 'X': {
          if (i + 1 < input.size() and
              (input[i + 1] == 'L' or input[i + 1] == 'C')) {
            if (input[i + 1] == 'L')
              answer += 40;
            else
              answer += 90;
            i++;
          } else {
            answer += 10;
          }
          break;
        }
        case 'C': {
          if (i + 1 < input.size() and
              (input[i + 1] == 'D' or input[i + 1] == 'M')) {
            if (input[i + 1] == 'D')
              answer += 400;
            else
              answer += 900;
            i++;
          } else {
            answer += 100;
          }
          break;
        }
      }
    }

    return answer;
  }
};

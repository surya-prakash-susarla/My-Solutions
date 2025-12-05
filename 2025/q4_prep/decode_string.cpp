class Solution {
 public:
  string decodeString(string input) {
    string answer = "";

    for (int i = 0; i < input.size();) {
      if (isalpha(input[i])) {
        answer += input[i];
        i++;
        continue;
      }
      if (isdigit(input[i])) {
        string digits(1, input[i]);
        int j;
        for (j = i + 1; j < input.size(); j++)
          if (input[j] == '[')
            break;
          else
            digits += input[j];
        int k;
        int counter = 0;
        for (k = j + 1; k < input.size(); k++)
          if (input[k] == ']') {
            if (counter == 0)
              break;
            else
              counter--;
          } else if (input[k] == '[')
            counter++;

        string rem = input.substr(j + 1, k - j - 1);
        rem = decodeString(rem);
        string net = "";
        for (int x = 0; x < stoi(digits); x++)
          net += rem;
        answer += net;
        i = k + 1;
        continue;
      }

      cout << "error" << endl;
    }

    return answer;
  }
};

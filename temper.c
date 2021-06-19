#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *keyw[] = {"void",   "main",   "int",    "char",   "default",
                "double", "float",  "if",     "else",   "while",
                "do",     "string", "return", "printf", "scanf",
                "FILE",   "malloc", "calloc", "for",    "\0"};
char oper[] = {'+', '-', '%', '/', '*', '='};
char symb[] = {'{', '}', '(', ')'};

int nk = 19, no = 6, ns = 4;
int o = 0, k = 0, i = 0, s = 0;

int check(char arr[], int lim, char c) {
  for (int i = 0; i < lim; i++)
    if (arr[i] == c)
      return 1;
  return 0;
}

int check_k(char temp[]) {
  for (int i = 0; i < nk; i++)
    if (strcmp(keyw[i], temp) == 0)
      return 1;
  return 0;
}

int word_check(int index, char input[]) {
  char temp[250];
  int j = 0;
  while (input[index] != '\0') {
    if (isalnum(input[index]))
      temp[j++] = input[index++];
    else {
      if (check(symb, ns, input[index]))
        s++;
      else if (check(oper, no, input[index]))
        o++;
      if (j != 0) {
        temp[j] = '\0';
        if (check_k(temp))
          k++;
        else
          i++;
      }
      return index + 1;
    }
  }
  return -1;
}

void input_string() {
  char input[250];
  fgets(input, 250, stdin);
  int in = 0;
  while (input[in] != '\0') {
    in = word_check(in, input);
  }
  printf("keywords = %d , operators = %d , identifiers = %d , symbols = %d \n",
         k, o, i, s);
  return;
}

int main() {
  input_string();
  return 0;
}

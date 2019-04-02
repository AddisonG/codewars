#include <ctype.h>
#include <stdio.h>

char* playPass(char* string, int rotate) {
  int length = strlen(string);
  char* result = malloc(sizeof(char) * length + 1);
  
  for (int i = length - 1; i >= 0; i--) {
    if (isalpha(string[i])) {
      char shiftedLetter = ((string[i] - 'A' + rotate) % 26) + 'A';
      result[length - i - 1] = i % 2 ? tolower(shiftedLetter) : toupper(shiftedLetter);
    } else if (isdigit(string[i])) {
      result[length - i - 1] = '0' + '9' - string[i];
    } else {
      result[length - i - 1] = string[i];
    }
  }
  
  result[length] = 0;
  
  return result;
}

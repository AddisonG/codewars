#include <stdbool.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
  if (strlen(search_text) == 0) {
    return 0;
  }
  int count = 0;
  char *pointer = full_text;
  
  while (pointer = strstr(pointer, search_text)) {
    count++;
    if (allow_overlap) {
      pointer++;
    } else {
      pointer += strlen(search_text);
    }
  }
  return count;
}

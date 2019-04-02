#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair Pair;
struct Pair {
  char* first;
  char* second;
};

Pair** partlist(char** strings, int size) {
  Pair** pairs = malloc(sizeof(Pair*) * (size - 1));
  
  for (int i = 0; i < (size - 1); i++) {
    int j = 0;
    Pair* pair = calloc(1, sizeof(Pair));
    
    // First half (Do first value outside loop)
    pair->first = malloc(strlen(strings[j]) + 1);
    strcpy(pair->first, strings[j]);
    // Do remaining pairs
    for (j++; j <= i; j++) {
      pair->first = realloc(pair->first, strlen(pair->first) + strlen(strings[j]) + 2); // +1 for space, +1 for null char
      strcat(pair->first, " ");
      strcat(pair->first, strings[j]);
    }
    
    // Second half (Do first value outside loop)
    pair->second = malloc(strlen(strings[j]) + 1);
    strcpy(pair->second, strings[j]);
    // Do remaining pairs
    for (j++; j < size; j++) {
      pair->second = realloc(pair->second, strlen(pair->second) + strlen(strings[j]) + 2); // +1 for space, +1 for null char
      strcat(pair->second, " ");
      strcat(pair->second, strings[j]);
    }
    
    pairs[i] = pair;
  }
  
  return pairs;
}

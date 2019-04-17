#include <stddef.h>

int artificial_rain(const int *heights, size_t n) {
  int bestSpread = 0;
  printf("\n\n");
  for (int i = 0; i < n; i++) {
    printf("%d-", heights[i]);
    int slope = heights[i], spread = 1;
    for (int left = i - 1; left >= 0 && heights[left] <= slope; left--) { // Left
      slope = heights[left];
      spread++;
    }
    
    slope = heights[i];
    for (int right = i + 1; right < n && heights[right] <= slope; right++) { // Right
      slope = heights[right];
      spread++;
    }
    
    if (spread > bestSpread) {
      bestSpread = spread;
    }
  }
  return bestSpread;
}

int artificial_rain(const int *heights, int n) {
  int height = heights[0], best = 0, flat = 0, down = 0, up = 0;
  for (int i = 1; i < n; i++) {
    if (height == heights[i]) { // Flat ( - )
      flat++;
      continue;
    } else if (heights[i] > height) { // Uphill ( / )
      best = best > down + flat ? best : down + flat;
      up += flat + 1;
      down = 0;
    } else if (down) { // Downhill ( \ )
      down += flat + 1;
    } else { // Local Max ( /\ )
      down = up + flat + 1;
      up = 0;
    }
    flat = 0;
    height = heights[i];
  }
  best = best > up + down + flat ? best : up + down + flat;
  return best + 1;
}

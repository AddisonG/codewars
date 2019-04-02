package kata

import (
  "strings"
)

func duplicate_count(s string) int {
  var counts [128]int
  ret := 0
  for _, c := range strings.ToLower(s) {
    counts[c]++
    if counts[c] == 2 {
      ret++
    }
  }
  return ret
}

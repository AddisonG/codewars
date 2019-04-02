package kata

import (
  "fmt"
  "strings"
  "math"
)

func IsValidCoordinates(coords string) bool {
  var latLong []string = strings.Split(coords, ", ")
  if len(latLong) != 2 || strings.Contains(coords, "e") {
    return false
  }

  var lat, long float64
  num, err := fmt.Sscanf(latLong[0], "%f\n", &lat)
  if num != 1 || err != nil || math.Abs(lat) > 90 {
    return false
  }
  num, err = fmt.Sscanf(latLong[1], "%f\n", &long)
  if num != 1 || err != nil || math.Abs(long) > 180 {
    return false
  }

  return true
}

package kata

import (
  "sort"
  "reflect"
)

func InAscOrder(numbers []int) bool {
  sorted := make([]int, len(numbers))
  copy(sorted, numbers)
  sort.Ints(sorted)
  return reflect.DeepEqual(sorted, numbers);
}
